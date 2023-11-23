//
// Created by JiangdeTu on 2023/11/15.
//

# include "lexer.h"


extern int NUM;  // 定义全局变量NUM标识识别的数字
extern char str[1001]; // 定义字符流接受数组
extern int sym; // 定义系统类别
extern int current_state;
extern char csym[];
extern int c_syms[];
extern char *word[];
extern int word_syms[];

char getch(FILE *input, FILE *output, int *lineCounter) {
    char ch = fgetc(input);

    while (ch == '\n') {
        // 跳过行结束符\n
        fprintf(output, "Line: %d processed\n", *lineCounter);
        (*lineCounter)++;
        ch = fgetc(input);
    }

    return ch;
}

int getsym(int state) {
    int current_sym = -1;  // 记录当前单词种类号，用局部变量尽量减少对全局变量的修改
    int flag = 0;
    switch (state) {
        case INID:
            for (int i = 0; i < ARRAY_SIZE; i++) {
                if (strcmp(str, word[i]) == 0) {
                    current_sym = word_syms[i];
                    flag = 1;
                    break;  // 找到匹配项后可以提前结束循环
                }
            }
            if (!flag) {
                // 没有匹配的关键字， 则定义为标识符
                current_sym = SYM_IDENTIFIER;
            }

            break;
        case INNUM:
            current_sym = SYS_NUMBER;  // 读取SYM_NUMBER的种类号
            break;
        case INASSIGN:
            current_sym = SYM_BECOMES;
            break;
        case COMMENTEND:
            current_sym = SYM_COMMENT;
            break;
        case CHAREND:
            current_sym = SYM_CHAR;
            break;
        case ERROR:
            current_sym = 100;
            break;
    }
    return current_sym;
}


int search_in_array_ch(char ch, const char *ch_sym, int len) {
    int flag = 0;
    // 检查字符是否与特殊符号数组中的任意一个元素相等
    for (int i = 0; i < len; i++) {
        if (ch == ch_sym[i]) {// 与数组a中的元素相等
            flag = 1;
            break;
        }
    }
    return flag;
}

