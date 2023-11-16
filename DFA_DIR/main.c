#include "lexer.h"

int NUM;  // 定义全局变量NUM标识识别的数字
char str[1001]; // 定义字符流接受数组
int sym; // 定义系统类别
int current_state;
int line = 1;
// 定义特殊符号
char csym[] = {
        ' ', '\t', '+', '-', '*', '/', '(', ')', '=', ',', '.', ';', '<', '>',
};
// 定义特殊符号的种类号
int c_syms[] = {
        SYM_SPACE, SYM_TAB, SYM_ADD, SYM_SUB, SYM_MUL, SYM_TRAN, SYM_LBR, SYM_RBR, SYM_EQU, SYM_COMMA, SYM_PERIOD,
        SYM_SEMICOLON, SYM_LESS, SYM_GREATER,

};

// 定义关键字
char *word[] = {
        "begin", "call", "const", "do", "end", "if",
        "odd", "procedure", "then", "var", "while"
};

// 定义关键字的种类号
int word_syms[] = {
        SYM_BEG, SYM_CALL, SYM_CONST, SYM_DO, SYM_END, SYM_IF, SYM_ODD,
        SYM_PROCEDURE, SYM_THEM, SYM_VAR, SYM_WHILE
};


void lexer(FILE *fp);

int main() {
    // 读取测试文件
    FILE *fp = fopen("D:\\Workplace\\WindowsLexer\\test.txt", "r");
    if (!fp) {
        printf("Can not open the file...");
    } else {
        // dfa process
        lexer(fp);
    }
    fclose(fp);


    return 0;
}

void lexer(FILE *fp) {
    char ch; //  定义单个输入字符
    FILE *output = fopen("D:\\Workplace\\WindowsLexer\\program_list.txt", "w+");
    current_state = START;
    while ((ch = getch(fp, output, &line)) != EOF) {
//        if(ch=='r'){
//            printf("stop...\n");
//        }
        switch (current_state) {
            case START:
                do_start(ch);
                ungetc(ch, fp);
                break;
            case INID:
                do_inid(ch, fp, output, &line);
                break;
            case INNUM:
                do_innum(ch, fp, output, &line);
                break;
            case MIDASSIGN:
                do_mid_assign(ch, fp, output, &line);
                break;
            case INASSIGN:
                do_inassign(ch, fp, output, &line);
                break;
            case INCOMMENT:
                do_incomment(ch, fp, output, &line);
                break;
            case INCHAR:
                do_inchar(ch, fp, output, &line);
                break;
            case SPCHAR:
                do_special_char(ch, fp, output, &line);
                break;
        }
    }
    fprintf(output, "Line: %d processed\n", line);
    fclose(output);
}

