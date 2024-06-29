%{
#include <stdio.h>

%}

digit       [0-9]
identifier  [a-zA-Z_][a-zA-Z0-9_]*
string      \"([^\\"]|\\.)*\"
float       {digit}+\.{digit}*
integer     {digit}+ 

%%

"/*"([^*]|\*+[^*/])*\*+"/"    { /* ignore multi-line comments */ }
"//".*                        { /* ignore single-line comments */ }

{identifier}                  { /* ignore identifiers */ }
{float}                       { printf("Float constant: %s\n", yytext); }
{integer}                     { printf("Integer constant: %s\n", yytext); }
{string}                      { printf("String constant: %s\n", yytext); }

[ \t\n\r]+                    { /* ignore whitespace */ }

.                             { /* ignore other characters */ }

%%

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", argv[1]);
        return 1;
    }

    yyin = file;
    yylex();
    fclose(file);

    return 0;
}

int yywrap() {
    return 1;
}
