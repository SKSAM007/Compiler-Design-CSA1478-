%{
#include <stdio.h>
#include <stdlib.h>

void calculate(const char* expression);
%}

%option noyywrap

%%
[0-9]+[ \t]*\+[ \t]*[0-9]+ {
    calculate(yytext);
}

[0-9]+[ \t]*\-[ \t]*[0-9]+ {
    calculate(yytext);
}

[0-9]+[ \t]*\*[ \t]*[0-9]+ {
    calculate(yytext);
}

[0-9]+[ \t]*\/[ \t]*[0-9]+ {
    calculate(yytext);
}

[ \t\n]+ {
    /* Ignore whitespace */
}

. {
    printf("Invalid input: %s\n", yytext);
}

%%

void calculate(const char* expression) {
    int num1, num2;
    char op;
    sscanf(expression, "%d %c %d", &num1, &op, &num2);

    switch(op) {
        case '+':
            printf("%d + %d = %d\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%d - %d = %d\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%d * %d = %d\n", num1, num2, num1 * num2);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero\n");
            } else {
                printf("%d / %d = %d\n", num1, num2, num1 / num2);
            }
            break;
        default:
            printf("Invalid operator: %c\n", op);
            break;
    }
}

int main() {
    yylex();
    return 0;
}
