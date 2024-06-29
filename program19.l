%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int macro_count = 0;
int header_count = 0;

%}

%%

^"#define"     { macro_count++; }
^"#include".* { header_count++; }

"/*"([^*]|\*+[^*/])*\*+"/"    { /* ignore multi-line comments */ }
"//".*                        { /* ignore single-line comments */ }

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

    printf("Number of Macros defined: %d\n", macro_count);
    printf("Number of Header files included: %d\n", header_count);

    return 0;
}

int yywrap() {
    return 1;
}
