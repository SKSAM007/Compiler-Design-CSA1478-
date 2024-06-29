%{
#include <stdio.h>
%}

%option noyywrap

/* Regular expression for a valid email address */
%%
^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,6}$ {
    printf("Valid email address: %s\n", yytext);
}

.|\n {
    printf("Invalid email address: %s\n", yytext);
}

%%

int main() {
    yylex();
    return 0;
}
