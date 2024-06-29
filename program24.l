%{
#include <stdio.h>

int char_count = 0;
int line_count = 0;
int word_count = 0;
int in_word = 0;

%}

%%

\n          { line_count++; char_count++; in_word = 0; }
.           { char_count++; }
[ \t\n]+    { if (in_word) { word_count++; in_word = 0; } }
[a-zA-Z0-9]+ { if (!in_word) { word_count++; in_word = 1; } char_count += yyleng; }

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

    if (in_word) {
        word_count++; // if file ended with a word
    }

    printf("Characters: %d\n", char_count);
    printf("Lines: %d\n", line_count);
    printf("Words: %d\n", word_count);

    return 0;
}

int yywrap() {
    return 1;
}
