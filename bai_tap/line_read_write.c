#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fin, *fout;
    if((fin = fopen("text1.txt", "r")) == NULL){
        printf("Error");
    }
    fout = fopen("text2.txt", "w");
    char str[1000];
    while (fgets(str, 1000, fin) != NULL)
    {
        fprintf(fout, "%d %s", strlen(str)-1, str);
        printf("%d %s", strlen(str)-1, str);
    }
    
}