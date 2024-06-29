#include <stdio.h>
#include <string.h>

#define MAX_RULE_LENGTH 100
#define MAX_PRODUCTIONS 10

void eliminateLeftRecursion(char non_terminal, char** productions, int num_productions) {
    char new_non_terminal = non_terminal + 1; // New non-terminal to replace left recursion

    // Process each production
    for (int i = 0; i < num_productions; i++) {
        if (productions[i][0] == non_terminal) {
            // Found a left-recursive production A -> A alpha
            // Replace it with A -> beta NewA and NewA -> alpha NewA | epsilon

            char beta[MAX_RULE_LENGTH];
            strcpy(beta, productions[i] + 3); // Copy beta part (after "-> ")

            // Print A -> beta NewA
            printf("%c -> %s %c'\n", non_terminal, beta, new_non_terminal);

            // Print NewA -> alpha NewA | epsilon
            printf("%c' -> %c' %s | epsilon\n", new_non_terminal, non_terminal, beta);
        } else {
            // Regular production without left recursion
            printf("%s\n", productions[i]);
        }
    }
}

int main() {
    char productions[MAX_PRODUCTIONS][MAX_RULE_LENGTH];
    int num_productions = 0;
    char line[MAX_RULE_LENGTH];

    // Read grammar productions from stdin
    printf("Enter grammar rules (terminate with EOF):\n");
    while (fgets(line, sizeof(line), stdin) != NULL) {
        if (line[0] == '\n') {
            break; // Stop reading on empty line
        }
        line[strcspn(line, "\n")] = '\0'; // Remove newline character

        strcpy(productions[num_productions], line);
        num_productions++;
    }

    // Process each production to eliminate left recursion
    for (int i = 0; i < num_productions; i++) {
        char non_terminal = productions[i][0];
        if (productions[i][3] == non_terminal) {
            // Found left recursion for this non-terminal
            // Pass productions as char**
            eliminateLeftRecursion(non_terminal, (char**)productions, num_productions);
            return 0;
        }
    }

    // No left recursion found
    printf("No left recursion found in the grammar.\n");

    return 0;
}

