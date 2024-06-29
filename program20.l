%{
#include <stdio.h>
#include <string.h>

%}

%%

"<"[^>]*">"    { printf("HTML tag: %s\n", yytext); }

[ \t\n]+       { /* ignore whitespace */ }

.              { /* ignore other characters */ }

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
