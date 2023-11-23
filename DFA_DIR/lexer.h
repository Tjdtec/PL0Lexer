//
// Created by JiangdeTu on 2023/11/14.
//

#ifndef WINDOWSLEXER_LEXER_H
#define WINDOWSLEXER_LEXER_H
# define ARRAY_SIZE 11
#endif //WINDOWSLEXER_LEXER_H

# include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 有限状态机的状态定义
enum states {
    START, INID, INNUM, MIDASSIGN, INASSIGN, INCOMMENT, COMMENTEND, INCHAR, CHAREND, ERROR, SPCHAR
    //SPCHAR: special char 即特殊符号
};

extern int current_state;

//类别码, 为每一个保留字都设置了一个类别码
enum symtype {
    /*
     * 识别 :=，<=，>=之类的特殊符号，全局量sym则分别被赋值为SYM_BECOMES，SYM_LEQ，SYM_GEQ
     * 识别"begin", "call", "const", "do", "end", "if", "odd", "procedure", "then", "var", "while"等关键字，全局变量则被赋值为SYM_BEG, SYM_CALL, SYM_CONST, SYM_DO, SYM_END, SYM_IF, SYM_ODD,
     * SYM_PROCEDURE, SYM_THEM, SYM_VAR, SYM_WHILE
     * 识别特殊符号' ', '+', '-', '*', '/', '(', ')', ',', '.', ';', '<', '>'等关键字，全局变量被赋值为：SYM_SPACE, SYM_ADD, SYM_SUB,SYM_MUL, SYM_TRAN, SYM_LBR, SYM_RBR, SYM_COMMA, SYM_PERIOD,
     * SYM_SEMICOLON
    *  制定的顺序参考实验原理中的单词表
     * */
    SYM_NULL,
    SYM_IDENTIFIER,
    SYS_NUMBER,
    SYM_ADD,
    SYM_SUB,
    SYM_MUL,
    SYM_TRAN,
    SYM_EQU,
    SYM_GREATER,
    SYM_LESS,
    SYM_UNEQU,
    SYM_LEQ,
    SYM_GEQ,
    SYM_LBR,
    SYM_RBR,
    SYM_LCOM,
    SYM_RCOM,
    SYM_SEMICOLON,
    SYM_COMMA,
    SYM_AIR,
    SYM_BECOMES,
    SYM_VAR,
    SYM_IF,
    SYM_THEN,
    SYM_ELSE,
    SYM_WHILE,
    SYM_FOR,
    SYM_BEG,
    SYM_WRITELN,
    SYM_PROCEDURE,
    SYM_END,
    SYM_CALL,
    SYM_CONST,
    SYM_DO,
    SYM_ODD,
    SYM_THEM,
    SYM_SPACE,
    SYM_PERIOD,
    SYM_COMMENT,
    SYM_CHAR,
    SYM_TAB
};


char getch(FILE *input, FILE *output, int *lineCounter);

int getsym(int state);

int search_in_array_ch(char ch, const char *ch_sym, int len);

void error(int i);

void do_start(char ch);

void do_inid(char ch, FILE *input, FILE *output, int *line);

void do_innum(char ch, FILE *inputs, FILE *output, int *line);

void do_mid_assign(char ch, FILE *inputs, FILE *output, int *line);

void do_inassign(char ch, FILE *inputs, FILE *output, int *line);

void do_incomment(char ch, FILE *inputs, FILE *output, int *line);

void do_comment_end(char *p_str);

void do_inchar(char ch, FILE *inputs, FILE *output, int *line);

void do_char_end(char *p_str);

void do_special_char(char ch, FILE *inputs, FILE *output, int *line);