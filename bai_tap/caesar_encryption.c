#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    FILE *fin, *fout;
    int offset = atoi(argv[2]);
    if(argc != 4){
        printf("Error");
        return 1;
    }
    if((fin = fopen(argv[1], "r")) == NULL){
        printf("Error");
        return 1;
    }
    if((fin = fopen(argv[3], "a")) == NULL){
        printf("Error");
        return 1;
    }

    int c = fgetc(fin);
    printf("%c",c);
    while (c != EOF)
    {
    if(c != '\n'){
    c = c + offset;
    }
    printf("%c ", c);
    fputc(c, fout);
    c = fgetc(fin);
    }
    fclose(fin);
    fclose(fout);
    

}