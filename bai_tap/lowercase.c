#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fptr1, *fptr2;
    if((fptr1 = fopen("text.txt", "r")) == NULL){
        printf("Error");
    }else{
        fptr2 = fopen("text1.txt", "w");
        char c = fgetc(fptr1);
        while(c != EOF){
            if(c >= 'A' && c <= 'Z'){
                c = c - 'A' + 'a';
            }
            fputc(c, fptr2);
            c = fgetc(fptr1);
        }
        

    }
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}