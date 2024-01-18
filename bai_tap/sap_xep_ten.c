#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getIndexName(char str[]){
    char c;
    for(int i=strlen(str)-1; i>=0; i++){
        c = str[i];
        if(c == ' ') return i+1;
    }
    return 0;
}

int main(){
    int n;
    scanf("%d", &n);
    char str[100][100];
    fflush(stdin);
    for(int i=0; i<n; i++){
        gets(str[i]);
    }
    int max=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
           if(strcmp(str[i], str[j])){
                char tmp[100];
                strcpy(tmp , str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], tmp);
            }
        }
    }
    for(int i=0; i<n; i++){
        printf("%s\n", str[i]);
    }
}