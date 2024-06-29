%{
#include <stdio.h>
%}

%option noyywrap

%%

abc {
    printf("ABC");
}

.|\n {
    putchar(yytext[0]);
}

%%

int main() {
    yylex();
    return 0;
}
