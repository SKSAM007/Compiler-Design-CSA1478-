#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Forward declarations of functions
bool E();
bool E_prime();
bool T();
bool T_prime();
bool F();

// Global variables
char input[100];
int index = 0;
char lookahead;

// Function to get the next character from the input
void nextToken() {
    lookahead = input[index++];
}

// Function to match the current character with the expected character
bool match(char expected) {
    if (lookahead == expected) {
        nextToken();
        return true;
    }
    return false;
}

// Grammar functions
bool E() {
    if (T()) {
        if (E_prime()) {
            return true;
        }
    }
    return false;
}

bool E_prime() {
    if (lookahead == '+') {
        if (match('+')) {
            if (T()) {
                if (E_prime()) {
                    return true;
                }
            }
        }
        return false;
    }
    // e production
    return true;
}

bool T() {
    if (F()) {
        if (T_prime()) {
            return true;
        }
    }
    return false;
}

bool T_prime() {
    if (lookahead == '*') {
        if (match('*')) {
            if (F()) {
                if (T_prime()) {
                    return true;
                }
            }
        }
        return false;
    }
    // e production
    return true;
}

bool F() {
    if (lookahead == '(') {
        if (match('(')) {
            if (E()) {
                if (match(')')) {
                    return true;
                }
            }
        }
        return false;
    } else if (isalnum(lookahead)) {  // id (identifier)
        nextToken();
        return true;
    }
    return false;
}

// Main function to test the parser
int main() {
    printf("Enter the input string: ");
    scanf("%s", input);
    index = 0;
    nextToken();
    if (E() && lookahead == '\0') {
        printf("The input string is valid according to the grammar.\n");
    } else {
        printf("The input string is invalid according to the grammar.\n");
    }
    return 0;
}

