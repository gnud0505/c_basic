#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

typedef struct {
    char tu[20];
    char hau_to[20];
} Word;

int compare(const void *p1, const void *p2) {
    const Word *word1 = (const Word *)p1;
    const Word *word2 = (const Word *)p2;
    int suffixComparison = strcmp(word1->hau_to, word2->hau_to);

    if (suffixComparison == 0) {
        return strcmp(word1->tu, word2->tu);
    }

    return suffixComparison;
}

int main() {
    char hau_to[20];
    scanf("%s", hau_to);
    Word words[MAX];
    int count = 0;
    while (count < MAX && scanf("%s", words[count].tu) == 1) {
        strcpy(words[count].hau_to, words[count].hau_to + strlen(words[count].tu) - strlen(hau_to));
        count++;
    }
    qsort(words, count, sizeof(words[0]), compare);

    for (int i = 0; i < count; i++) {
        if (strcmp(words[i].hau_to, hau_to) == 0) {
            printf("%s\n", words[i].tu);
        }
    }

    return 0;
}