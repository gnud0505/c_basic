#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str[100];
    char c = getchar();
    int count[26] ={0};
    while (c != '\n' && c != '\0')
    {
        if(c<='z' && c>='a') ++count[c-'a'];
        if(c<='Z' && c>='A') ++count[c-'A'];
        c=getchar();
    }
    for(int i= 0; i<26; i++){
        if(count[i]>0)
            printf("the letter %c appear %d time(s)", i+'a', count[i]);
    }
    
    
}