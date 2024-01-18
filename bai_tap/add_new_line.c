#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fptr;
    if((fptr = fopen("text1.txt", "r+")) == NULL){
        printf("Error");
        return 1;
    }
    char str[1000];
    char str1[1000];
    int i=0;
    while (fgets(str, 1000, fptr) != NULL)
    {
        str1[i]= str[0];
        str1[i+1] = '\0';
        i++;
    }
    fprintf(fptr, "\n%s", str1);
    printf("%s", str1);
    fclose(fptr);
}