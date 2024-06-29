#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void countCharactersWordsLines(FILE *fp, int *charCount, int *wordCount, int *lineCount) {
    char ch;
    int inWord = 0;
    *charCount = 0;
    *wordCount = 0;
    *lineCount = 0;

    while ((ch = fgetc(fp)) != EOF) {
        (*charCount)++;

        // Count lines
        if (ch == '\n') {
            (*lineCount)++;
        }

        // Count words
        if (isspace(ch)) {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            (*wordCount)++;
        }
    }

    // Adjust line count if the last line doesn't end with '\n'
    if (*charCount > 0 && ch != '\n') {
        (*lineCount)++;
    }
}

int main() {
    char filename[100];
    FILE *fp;
    int charCount, wordCount, lineCount;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    countCharactersWordsLines(fp, &charCount, &wordCount, &lineCount);

    printf("Number of characters: %d\n", charCount);
    printf("Number of words: %d\n", wordCount);
    printf("Number of lines: %d\n", lineCount);

    fclose(fp);

    return 0;
}

