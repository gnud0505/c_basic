#include <stdio.h>
#include <stdlib.h>
int n;
#define MAX 1000
int a[MAX][MAX];
int check_cheo(int i, int j){
    int cheo = 0;
    for(int x=0; x<n; x++){
        for(int y=0; y<n; y++){
            if(a[x][y] ==1){
                if((i-j) == (x-y) || (i+j) == (x+y)){
                    cheo++;
                }
            }
        }
    }
    return cheo;
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    int hang = 0, cot = 0, cheo = 0;

    for(int i=0; i<n ; i++){
        hang = 0;
        for(int j=0; j<n; j++){
            if(a[i][j] == 1){
                hang++;
            }
        }
        if(hang > 1){
            printf("0");
            return 0;
        }
    }

    for(int i=0; i<n ; i++){
        cot = 0;
        for(int j=0; j<n; j++){
            if(a[j][i] == 1){
                cot++;
            }
        }
        if(cot > 1){
            printf("0");
            return 0;
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cheo = 0;
            if(a[i][j]==1){
                cheo = check_cheo(i, j);
            }
            if(cheo > 1){
                printf("0");
                return 0;
            }
        }
    }

    printf("1");
    return 0;


}