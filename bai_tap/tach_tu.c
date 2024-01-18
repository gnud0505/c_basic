#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str[100];
    gets(str);
    char c;
    int x=0;
    for(int i=0; i<strlen(str); i++){
        c = str[i];
        if(c == ' '){
            if(x == 0){
                printf("\n");
                x=1;
            }
        }else {
            x=0;
            printf("%c",c);
        }
    }
}