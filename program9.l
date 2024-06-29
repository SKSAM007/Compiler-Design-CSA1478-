%{
#include <stdio.h>
int max_length = 0;  // Variable to store the maximum length found
%}

%option noyywrap

%%
[a-zA-Z]+ {
    int len = yyleng;  // yyleng gives the length of the matched string
    if (len > max_length) {
        max_length = len;  // Update max_length if we found a longer word
    }
}

\n {
    // End of line, print the maximum length found for this line
    printf("Longest word length in this line: %d\n", max_length);
    max_length = 0;  // Reset for the next line
}

. {}  // Ignore all other characters

%%

int main() {
    // Flex-specific initialization
    yyin = stdin;  // Read from standard input
    yylex();  // Start processing
    
    return 0;
}
