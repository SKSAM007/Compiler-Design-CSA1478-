#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPR_SIZE 100

// Structure to hold an expression
typedef struct {
    char expression[MAX_EXPR_SIZE];
    char tempVar[5]; // Temporary variable to replace common subexpression
} Expression;

// Function declarations
void optimizeExpressions(Expression expressions[], int numExpressions);
int isCommonSubexpression(char* expr1, char* expr2);

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

    // Perform optimization
    optimizeExpressions(expressions, numExpressions);

    // Output optimized expressions
    printf("\nOptimized expressions:\n");
    for (int i = 0; i < numExpressions; i++) {
        printf("Expression %d: %s\n", i + 1, expressions[i].expression);
    }

    return 0;
}

// Function to perform common subexpression elimination
void optimizeExpressions(Expression expressions[], int numExpressions) {
    for (int i = 0; i < numExpressions; i++) {
        for (int j = i + 1; j < numExpressions; j++) {
            if (isCommonSubexpression(expressions[i].expression, expressions[j].expression)) {
                sprintf(expressions[j].tempVar, "t%d", i + 1); // Use t1, t2, t3, ... as temporary variables
                // Replace common subexpression with temporary variable
                char* subExprPos = strstr(expressions[j].expression, expressions[i].expression);
                strcpy(subExprPos, expressions[j].tempVar);
                strcat(subExprPos + strlen(expressions[i].expression), subExprPos + strlen(expressions[i].expression));
            }
        }
    }
}

// Function to check if expr1 is a common subexpression of expr2
int isCommonSubexpression(char* expr1, char* expr2) {
    return strstr(expr2, expr1) != NULL;
}

