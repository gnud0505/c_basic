#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fin1, *fin2, *fout;
    if((fin1 = fopen("text1.txt", "r")) ==NULL || (fin2 = fopen("text2.txt", "r")) ==NULL || (fout = fopen("text3.txt", "w")) ==NULL){
        printf("Error");
        return 1;
    }
    char str1[1000], str2[1000];
    while(fgets(str1, 1000, fin1) != NULL && fgets(str2, 1000, fin2) != NULL){
        fputs(str1, fout);
        printf("%s", str1);
        fputs(str2, fout);
        printf("%s", str2);
    }
    if (str1!= NULL) fputs(str1,fout);

    while(fgets(str1, 1000, fin1) != NULL){
        fputs(str1, fout);
        printf("%s", str1);
    }
    while(fgets(str2, 1000, fin2) != NULL){
        fputs(str2, fout);
        printf("%s", str2);
    }
}