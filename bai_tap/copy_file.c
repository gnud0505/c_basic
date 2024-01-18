#include <stdio.h>

int main(){
    FILE *fin, *fout;
    if((fin =  fopen("text.txt", "r")) == NULL){
        printf("Error");
        return 1;
    }
    if((fout =  fopen("text1.txt", "w")) == NULL){
        printf("Error");
        fclose(fin);
        return 1;
    }
    char str[1000];
    int count=0;
    while (fgets(str, 1000, fin) != NULL )
    {
        fputs(str, fout);
        count++;
        printf("%d %s", count, str);
    }
    

}