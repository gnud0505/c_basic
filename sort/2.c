#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000


typedef struct {
    char word[20];
    char suffix[20];
} WordWithSuffix;

int suffixCompare(const void *p1, const void *p2) {
    const WordWithSuffix *word1 = (const WordWithSuffix *)p1;
    const WordWithSuffix *word2 = (const WordWithSuffix *)p2;
    int suffixComparison = strcmp(word1->suffix, word2->suffix);

    if (suffixComparison == 0) {
        return strcmp(word1->word, word2->word);
    }

    return suffixComparison;
}

int main() {
    char suffix[20];

    scanf("%s", suffix);

    WordWithSuffix words[MAX_WORDS];
    int wordCount = 0;

    while (wordCount < MAX_WORDS && scanf("%s", words[wordCount].word) == 1) {
        strcpy(words[wordCount].suffix, words[wordCount].word + strlen(words[wordCount].word) - strlen(suffix));
        wordCount++;
    }


    qsort(words, wordCount, sizeof(words[0]), suffixCompare);
    for (int i = 0; i < wordCount; i++) {
        if (strcmp(words[i].suffix, suffix) == 0) {
            printf("%s\n", words[i].word);
        }
    }

    return 0;
}