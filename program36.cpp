#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

// Function declarations
double expression();
double term();
double factor();
double exponent();
double number();

// Global variables
char input[100];
int index = 0;
char lookahead;

// Function to get the next character from the input
void nextToken() {
    lookahead = input[index++];
}

// Function to parse an expression (handles addition and subtraction)
double expression() {
    double result = term();
    while (lookahead == '+' || lookahead == '-') {
        if (lookahead == '+') {
            nextToken();
            result += term();
        } else if (lookahead == '-') {
            nextToken();
            result -= term();
        }
    }
    return result;
}

// Function to parse a term (handles multiplication and division)
double term() {
    double result = factor();
    while (lookahead == '*' || lookahead == '/') {
        if (lookahead == '*') {
            nextToken();
            result *= factor();
        } else if (lookahead == '/') {
            nextToken();
            result /= factor();
        }
    }
    return result;
}

// Function to parse a factor (handles parentheses and exponentiation)
double factor() {
    if (lookahead == '(') {
        nextToken();
        double result = expression();
        if (lookahead == ')') {
            nextToken();
        } else {
            printf("Error: Mismatched parentheses.\n");
            exit(EXIT_FAILURE);
        }
        return result;
    } else {
        return exponent();
    }
}

// Function to parse exponentiation
double exponent() {
    double result = number();
    if (lookahead == '^') {
        nextToken();
        result = pow(result, exponent());
    }
    return result;
}

// Function to parse a number (handles integers and floating-point numbers)
double number() {
    double result = 0;
    if (isdigit(lookahead) || lookahead == '.') {
        int start = index - 1;
        while (isdigit(lookahead) || lookahead == '.') {
            nextToken();
        }
        char buffer[50];
        int length = index - start - 1;
        strncpy(buffer, &input[start], length);
        buffer[length] = '\0';
        result = atof(buffer);
    } else {
        printf("Error: Invalid number.\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

// Main function to test the parser
int main() {
    printf("Enter a mathematical expression: ");
    scanf("%s", input);
    index = 0;
    nextToken();
    double result = expression();
    if (lookahead == '\0') {
        printf("The result of the expression is: %lf\n", result);
    } else {
        printf("Error: Invalid expression.\n");
    }
    return 0;
}

