%{
#include <stdio.h>

// Define counters for positive and negative numbers
int positive_count = 0;
int negative_count = 0;
%}

%%

"-"[0-9]+      { negative_count++; }
[0-9]+         { positive_count++; }
[ \t\n]+       ;   // Ignore whitespace
.              ;   // Ignore other characters

%%

int main(int argc, char **argv) {
    // Run the lexical analyzer
    yylex();
    
    // Print the counts
    printf("Positive numbers: %d\n", positive_count);
    printf("Negative numbers: %d\n", negative_count);
    
    return 0;
}

int yywrap() {
    return 1;
}
