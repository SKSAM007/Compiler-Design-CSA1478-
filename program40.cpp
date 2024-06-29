#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPR_SIZE 100

// Structure to hold an expression
typedef struct {
    char expression[MAX_EXPR_SIZE];
} Expression;

// Function declarations
void generateTAC(Expression expressions[], int numExpressions);
void printTAC(Expression expressions[], int numExpressions);

int main() {
    int numExpressions;

    printf("Enter the number of expressions: ");
    scanf("%d", &numExpressions);

    Expression expressions[numExpressions];

    // Input expressions
    printf("Enter the expressions (one per line):\n");
    for (int i = 0; i < numExpressions; i++) {
        printf("Expression %d: ", i + 1);
        scanf("%s", expressions[i].expression);
    }

    // Generate Three-Address Code (TAC)
    generateTAC(expressions, numExpressions);

    // Print Three-Address Code (TAC)
    printf("\nGenerated Three-Address Code (TAC):\n");
    printTAC(expressions, numExpressions);

    return 0;
}

// Function to generate Three-Address Code (TAC)
void generateTAC(Expression expressions[], int numExpressions) {
    // In this example, we are not performing any optimization, just printing the expressions
    printf("Generating Three-Address Code (TAC)...\n");
}

// Function to print Three-Address Code (TAC)
void printTAC(Expression expressions[], int numExpressions) {
    for (int i = 0; i < numExpressions; i++) {
        printf("Expression %d: %s\n", i + 1, expressions[i].expression);
    }
}

