%{
#include <stdio.h>
#include <string.h>
%}

%option noyywrap

%%
[[:alpha:]_][[:alnum:]_]* {
    printf("Word: %s\n", yytext);
}

"<"|"<="|">"|">="|"=="|"!=" {
    printf("Relational Operator: %s\n", yytext);
}

.|\n {
    /* Ignore unmatched characters */
}

%%

int main(int argc, char *argv[]) {
    yyin = stdin;  // Read from standard input

    yylex();  // Start processing

    return 0;
}
