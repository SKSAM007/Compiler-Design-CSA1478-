#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function declarations
bool S(char input[], int index, int length);
bool parse(char input[]);

// Function to parse according to the rule S -> aSb | e
bool S(char input[], int index, int length) {
    // Case S -> e
    if (index >= length) {
        return true;
    }

    // Case S -> aSb
    if (input[index] == 'a') {
        index++;
        if (S(input, index, length)) {
            while (index < length && input[index] != 'b') {
                index++;
            }
            if (index < length && input[index] == 'b') {
                index++;
                return true;
            }
        }
    }

    return false;
}

// Function to check if the entire input string satisfies the grammar
bool parse(char input[]) {
    int length = strlen(input);
    return S(input, 0, length) && (length == 0 || input[length - 1] == 'b');
}

int main() {
    char testStrings[][50] = {
        "aabb",
        "aababb",
        "aabbab",
        "aaabbb",
        "aabbba",
        "ab",
        "abab",
        "aaaabbbb",
        "",
        "a"
    };

    int numberOfStrings = sizeof(testStrings) / sizeof(testStrings[0]);

    for (int i = 0; i < numberOfStrings; i++) {
        if (parse(testStrings[i])) {
            printf("The string \"%s\" is valid.\n", testStrings[i]);
        } else {
            printf("The string \"%s\" is invalid.\n", testStrings[i]);
        }
    }

    return 0;
}

