%{
# include <stdio.h>
%}

%%
"+"         { printf("(3: +)\n"); }
"-"         { printf("(4: -)\n"); }
"*"         { printf("(5: *)\n"); }
"/"         { printf("(6: /)\n"); }
"="         { printf("(7: =)\n"); }
">"         { printf("(8: >)\n"); }
"<"         { printf("(9: <)\n"); }
"<>"        { printf("(10: <>)\n");}
"<="        { printf("(11: <=)\n");}
">="        { printf("(12: <=)\n");}
"("         { printf ("(13, ()\n");}
")"         { printf ("(14, ))\n");}
"{"        { printf("(15: {)\n");}
"}"        { printf("(16: })\n");}
";"         { printf("(17: ;)\n"); }
","         { printf("(18: ,)\n"); }
"\""        { printf("(19: ,\\)\n)"); }
":="        { printf("(20: ,:=)\n"); }
"var"       { printf("(21: var)\n"); }
"if"        { printf("(22: if)\n"); }
"then"      { printf("(23: then)\n");}
"else"      { printf("(24: else)\n");}
"while"     { printf("(25: while)\n"); }
"for"       { printf("(26: for)\n"); }
"begin"     { printf("(27: begin)\n"); }
"writeln"   { printf("(28: writeln)\n");}
"procedure" { printf("(29: procedure)\n"); }
"end"       { printf("(30: end)\n"); }
"call"      { printf("(31: call)\n"); }
"const"     { printf("(32: const)\n"); }
"do"        { printf("(33: do)\n"); }
"odd"       { printf("(34: odd)\n"); }
"then"      { printf("(35: then)\n"); }
[ \t\n]+    ;  // 忽略空格、制表符和换行符
[a-zA-Z]+   { printf("(1: %s)\n", yytext); }
[0-9]+      { printf("(2: %s)\n", yytext); }
.           { printf("Unrecognized character: %s\n", yytext); }
%%

int main()
{
    yylex();
    return 0;
}

int yywrap()
{
	return 1;
}