%{
#include <stdio.h>
%}

%%

^[aeiouAEIOU][a-zA-Z]*   { printf("Accepted string: %s\n", yytext); }
[a-zA-Z]+                { printf("Rejected string: %s\n", yytext); }
[ \t\n]+                 ;   // Ignore whitespace
.                        ;   // Ignore other characters

%%

int main(int argc, char **argv) {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
