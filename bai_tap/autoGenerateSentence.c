#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char article[20];
    char noun[20];
    char verd[20];
    char preposition[20];
}Word;


int main(){
    Word *wordList = (Word *)malloc(sizeof(Word) * 10);
    char *article[20] = {"the", "a", "one", "some", "any"},
        *noun[20] = {"boy", "girl", "dog", "town", "car"},
        *verd[20] = {"drove", "jumped", "ran", "walked", "skipped"},
        *preposition[20] = {"to", "from", "over", "under", "on"};
    for(int i=0; i<5; i++){
        strcpy(wordList[i].article, article[i]);
        strcpy(wordList[i].noun, noun[i]);
        strcpy(wordList[i].verd, verd[i]);
        strcpy(wordList[i].preposition, preposition[i]);
    }
    int randArticle1 = rand()%5,
        randNoun1 = rand()%5,
        randVerd = rand()%5,
        randArticle2 = rand()%5,
        randNoun2 = rand()%5;
    printf("%s %s %s %s %s", wordList[randArticle1].article, wordList[randNoun1].noun, wordList[randVerd].verd, wordList[randArticle2].article, wordList[randNoun2].noun);

}