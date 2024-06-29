%{
#include <stdio.h>
#include <string.h>

// Define keywords
const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
};

int is_keyword(const char *token) {
    for (int i = 0; i < 32; i++) {
        if (strcmp(token, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}
%}

%%

[a-zA-Z_][a-zA-Z0-9_]*   {
                            if (is_keyword(yytext)) {
                                printf("Keyword: %s\n", yytext);
                            } else {
                                printf("Identifier: %s\n", yytext);
                            }
                        }

[ \t\n]+                 ;   // Ignore whitespace

.                        ;   // Ignore other characters

%%

int main(int argc, char **argv) {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
