%{
#include <stdio.h>
#include <string.h>
%}

%option noyywrap

%%

(ftp|http|https|mailto):\/\/[-a-zA-Z0-9@:%._\+~#=]{2,256}\.[a-zA-Z]{2,6}([-a-zA-Z0-9@:%_\+.~#?&//=]*) {
    printf("Valid URL: %s\n", yytext);
}

.|\n {
    printf("Invalid URL: %s\n", yytext);
}

%%

int main(int argc, char *argv[]) {
    yyin = stdin;  // Read from standard input

    yylex();  // Start processing

    return 0;
}
