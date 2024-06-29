%{
#include <stdio.h>
%}

%%

^[6-9][0-9]{9}$   { printf("%s is a valid mobile number\n", yytext); }
^[0-9]{10}$       { printf("%s is an invalid mobile number (should start with 7, 8, or 9)\n", yytext); }
.                 { printf("%s is an invalid mobile number (should be 10 digits)\n", yytext); }

%%

int main() 
{
    printf("Enter mobile numbers (one per line, press Ctrl+D to end input):\n");
    yylex();
    return 0;
}

int yywrap() 
{
    return 1;
}
