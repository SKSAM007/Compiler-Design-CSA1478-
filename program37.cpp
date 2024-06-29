#include <stdio.h>
#include <ctype.h>
#include <string.h>

int temp_count = 0;

void generateTAC(char *expr) {
    char stack[100][100];
    int top = -1;

    int len = strlen(expr);
    for (int i = len - 1; i >= 0; i--) {
        if (isdigit(expr[i])) {
            char operand[2] = {expr[i], '\0'};
            strcpy(stack[++top], operand);
        } else if (strchr("+-*/", expr[i])) {
            char op1[100], op2[100], result[100];
            strcpy(op1, stack[top--]);
            strcpy(op2, stack[top--]);

            sprintf(result, "t%d", temp_count++);
            printf("%s = %s %c %s\n", result, op1, expr[i], op2);

            strcpy(stack[++top], result);
        }
    }

    if (top == 0) {
        printf("Result: %s\n", stack[top]);
    } else {
        printf("Error in expression\n");
    }
}

int main() {
    char expr[100];

    printf("Enter an arithmetic expression (in reverse Polish notation): ");
    scanf("%s", expr);

    printf("Three-Address Code:\n");
    generateTAC(expr);

    return 0;
}

