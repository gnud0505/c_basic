#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    FILE *fin, *fout;
    if((fin = fopen(argv[1], "r")) == NULL || argc != 3){
        printf("Error");
    }else{
        fout = fopen(argv[2], "w");
        char *str = (char*)malloc(1000*sizeof(char)) ;
        while (fgets(str, 1000, fin) != NULL)
        {
            fprintf(fout, "%s\n", str);
        }
        
    }
    fclose(fin);
    fclose(fout);
    return 0;
}