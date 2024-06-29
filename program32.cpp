#include <stdio.h>
#include <string.h>

#define MAX_RULE_LENGTH 100

// Function to eliminate left factoring for a given non-terminal
void eliminateLeftFactoring(char non_terminal, char** productions, int num_productions) {
    char new_non_terminal = non_terminal + 1; // New non-terminal to replace left factoring
    int common_prefix_length = 0;

    // Find common prefix length
    while (productions[0][common_prefix_length] == productions[1][common_prefix_length]) {
        common_prefix_length++;
    }

    // Print original productions
    printf("%c -> %s %c'\n", non_terminal, productions[0] + common_prefix_length, new_non_terminal);
    printf("%c' -> %s | %s\n", new_non_terminal, productions[1] + common_prefix_length, productions[2] + common_prefix_length);
}

int main() {
    char* productions[3]; // Array to store up to 3 productions
    int num_productions = 0;
    char line[MAX_RULE_LENGTH];

    // Read grammar productions from stdin
    printf("Enter grammar rules (terminate with EOF):\n");
    while (fgets(line, sizeof(line), stdin) != NULL) {
        if (line[0] == '\n') {
            break; // Stop reading on empty line
        }
        line[strcspn(line, "\n")] = '\0'; // Remove newline character

        productions[num_productions] = strdup(line); // Store a copy of the line
        num_productions++;
    }

    // Process each non-terminal to eliminate left factoring
    for (int i = 0; i < num_productions; i++) {
        char non_terminal = productions[i][0];
        if (num_productions == 2 && productions[0][0] == productions[1][0] && productions[0][2] == productions[1][2]) {
            // Found left factoring for this non-terminal
            eliminateLeftFactoring(non_terminal, productions, num_productions);
            return 0;
        }
    }

    // No left factoring found
    printf("No left factoring found in the grammar.\n");

    return 0;
}

