%{
#include <stdio.h>
#include <string.h>

// Function to determine if a string is a keyword
int is_keyword(const char *str) {
    const char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if",
        "int", "long", "register", "return", "short", "signed", "sizeof",
        "static", "struct", "switch", "typedef", "union", "unsigned", "void",
        "volatile", "while"
    };
    for (int i = 0; i < sizeof(keywords)/sizeof(keywords[0]); i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

%}

%%

"//".*                                 { /* Ignore single-line comments */ }
"/\\*([^*]|\\*+[^*/])*\\*/"            { /* Ignore multi-line comments */ }

"#include[ \t]*<[^>]*>"                { printf("Header File: %s\n", yytext); }

\"([^\\\"]|\\.)*\"                     { printf("String Literal: %s\n", yytext); }

[0-9]+                                 { printf("Integer Constant: %s\n", yytext); }
[0-9]+"."[0-9]*([eE][-+]?[0-9]+)?      { printf("Floating-point Constant: %s\n", yytext); }

"=="|"<="|">="|"!="|"="|"<"|">"        { printf("Operator: %s\n", yytext); }
"\\+|-|\\*|/|%|&|\\||!"                { printf("Operator: %s\n", yytext); }

"\\[|\\]|\\(|\\)|\\{|\\}|\\.|,|;|->"   { printf("Punctuation: %s\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]*                 {
                                          if (is_keyword(yytext))
                                              printf("Keyword: %s\n", yytext);
                                          else
                                              printf("Identifier: %s\n", yytext);
                                        }

[ \t\n]+                               { /* Ignore whitespace */ }

.                                      { printf("Unknown Token: %s\n", yytext); }

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
