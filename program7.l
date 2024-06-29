%{
#include <stdio.h>
#include <string.h>

// Define lists to store numbers and words
char numbers[100][50];
char words[100][50];
int num_count = 0;
int word_count = 0;
%}

%%

[0-9]+           {
                    strcpy(numbers[num_count++], yytext);
                 }
[a-zA-Z]+        {
                    strcpy(words[word_count++], yytext);
                 }
[ \t\n]+         ;   // Ignore whitespace
.                ;   // Ignore other characters

%%

int main(int argc, char **argv) {
    // Run the lexical analyzer
    yylex();
    
    // Print the lists of numbers and words
    printf("Numbers:\n");
    for (int i = 0; i < num_count; i++) {
        printf("%s\n", numbers[i]);
    }
    
    printf("Words:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s\n", words[i]);
    }
    
    return 0;
}

int yywrap() {
    return 1;
}
