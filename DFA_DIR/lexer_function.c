//
// Created by JiangdeTu on 2023/11/14.
//
# include "lexer.h"

extern int NUM;  // 定义全局变量NUM标识识别的数字
extern char str[1001]; // 定义字符流接受数组
extern int sym; // 定义系统类别
extern int current_state;
extern char csym[14];
extern int c_syms[];
extern char *word[];
extern int word_syms[];
extern int line;


void do_start(char ch) {
    if (isalpha(ch)) {
        current_state = INID; // 字母
    } else if (isdigit(ch)) {
        current_state = INNUM;
    } else if (ch == ':') {
        current_state = MIDASSIGN;
    } else if (ch == '{') {
        current_state = INCOMMENT;
    } else if (ch == '\"') {
        current_state = INCHAR;
    } else {
        int flag = search_in_array_ch(ch, csym, sizeof(csym) / sizeof(csym[0]));
        if (!flag) {
            current_state = ERROR;
            error();
        } else current_state = SPCHAR;
    }

}

void do_inid(char ch, FILE *inputs, FILE *output, int *line) {
    char t_str[2];
    memset(str, '\0', sizeof(str));
    do {
        sprintf(t_str, "%c", ch);  // 将字符转化成字符串
        strcat(str, t_str);
        if (!strcmp(str, "end")) {
            sym = getsym(current_state);
            printf("(%d, \"%s\")\n", sym, str);
            return;
        }
        ch = getch(inputs, output, line);
    } while (isalpha(ch) || isdigit(ch));
    sym = getsym(current_state);
    printf("(%d, \"%s\")\n", sym, str);
    memset(str, '\0', sizeof(str));
    ungetc(ch, inputs); // 回退字符
    current_state = START;
}

void do_innum(char ch, FILE *inputs, FILE *output, int *line) {
    while (isdigit(ch)) {
        NUM = NUM * 10 + (ch - '0');
        ch = getch(inputs, output, line);
    }
    sym = getsym(current_state);
    printf("(%d, \"%d\")\n", sym, NUM);
    NUM = 0;
    ungetc(ch, inputs);  // 回退字符到输入流
    current_state = START;
}


void do_mid_assign(char ch, FILE *inputs, FILE *output, int *line) {
    ch = getch(inputs, output, line); // 冒号不能单独存在, 直接判断后面是不是=就好了
    if (ch == '=') {
        current_state = INASSIGN;
        do_inassign(ch, inputs, output, &line);
    } else {
        current_state = ERROR;
        error();
    }
    current_state = START;
}

void do_inassign(char ch, FILE *inputs, FILE *output, int *line) {
    // 这个状态时说明已经完整识别出赋值符号了
    // 直接输出赋值符号： :=和他的种类码即可
    sym = getsym(current_state);
    printf("(%d, \":=\")\n", sym);
    current_state = START;
}

void do_incomment(char ch, FILE *inputs, FILE *output, int *line) {
    char t_str[2];
    memset(str, '\0', sizeof str);
    while ((ch = getch(inputs, output, line)) != '}') {
        //如果读到的都不是 '}'，则后面的均是注释, 状态保持不变，持续读取
        sprintf(t_str, "%c", ch);
        strcat(str, t_str);
        if (strlen(str) >= 1000) {
            current_state = ERROR;
            error();
            return;
        }
    }
    // 注释识别完成
    current_state = COMMENTEND;
    do_comment_end(str);
}

void do_comment_end(char *p_str) {
    // 输出最后的解析结果和单词种类编号
    sym = getsym(current_state);
    printf("(%d, \"注释\")\n", sym);
    current_state = START;

}

void do_inchar(char ch, FILE *inputs, FILE *output, int *line) {
    char t_str[2];
    while ((ch = getch(inputs, output, line) != '\"')) {
        // 如果不是读到结束符' " '则默认认为都算是字符串
        sprintf(t_str, "%c", ch);
        strcat(str, t_str);
        if (strlen(str) >= 1000) {
            current_state = ERROR;
            error();
            return;
        } else if (ch == EOF) {
            current_state = ERROR;
            error();
            return;
        }
    }
    // 字符串识别完成
    current_state = CHAREND;
    do_char_end(str);
}

void do_char_end(char *p_str) {
    // 输出解析的字符串和单词种类编号
    sym = getsym(current_state);
    printf("(%d, \"%s\")\n", sym, p_str);
    current_state = START;
}


void do_special_char(char ch, FILE *inputs, FILE *output, int *line) {
    // 特殊字符识别然后输出
    for (int i = 2; i < sizeof(csym) / sizeof csym[0]; i++) {
        if (ch == csym[i]) {
            if (ch == '<') {
                ch = getch(inputs, output, line);
                if (ch == '=') {
                    sym = SYM_LEQ;
                    printf("(%d, \"<=\")\n", sym);
                } else {
                    sym = SYM_LESS;
                    printf("(%d, \"<\")\n", sym);

                }
            } else if (ch == '>') {
                ch = getch(inputs, output, line);
                if (ch == '=') {
                    sym = SYM_GEQ;
                    printf("(%d, \">=\")\n", sym);
                } else {
                    sym = SYM_GREATER;
                    printf("(%d, \"<\")\n", sym);
                }
            } else {
                sym = c_syms[i];
                printf("(%d, \"%c\")\n", sym, csym[i]);
            }
        }
    }
    current_state = START;
}


void error() {
    FILE *fp = fopen("D:\\Workplace\\WindowsLexer\\program_list.txt", "r");
    fseek(fp, -1, SEEK_END);
    // system("cls");
    printf("(\"ERROR\",  -100)\n");
    printf("error line: %d\n", line);
}