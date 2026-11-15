#include "23th_RepWords.h"
#include <stdio.h>
#include <string.h>

void findRepeatedWords(char *str) {
    char *words[MAX_WORDS];
    int counts[MAX_WORDS];
    int uniqueCount = 0;
    int hasRepeats = 0;

    const char *delimiters = " ,.!?;:-()\t\n\r";

    char *token = strtok(str, delimiters);

    while (token != NULL) {
        int foundIndex = -1;

        for (int i = 0; i < uniqueCount; i++) {
            if (strcmp(words[i], token) == 0) {
                foundIndex = i;
                break;
            }
        }

        if (foundIndex != -1) {
            counts[foundIndex]++;
        } else if (uniqueCount < MAX_WORDS) {
            words[uniqueCount] = token;
            counts[uniqueCount] = 1;
            uniqueCount++;
        }

        token = strtok(NULL, delimiters);
    }

    for (int i = 0; i < uniqueCount; i++) {
        if (counts[i] >= 2) {
            printf("Слово \"%s\" повторяется %d раз(а).\n", words[i], counts[i]);
            hasRepeats = 1;
        }
    }

    if (!hasRepeats) {
        printf("Повторяющихся слов не найдено.\n");
    }
}