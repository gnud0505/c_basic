#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char a,b;
    char str[100];
    scanf("%c %c", &a, &b);
    fflush(stdin);
    gets(str);
    for(int i=0; i<strlen(str); i++){
        if(str[i] == a){
            str[i] = b;
        }
    }
    printf("%s", str);
}