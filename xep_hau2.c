//xep hau
#include <stdio.h>
#include <stdlib.h>
int n;
#define MAX 1000
int a[MAX][MAX];

int check_hang(int x, int y){
    int hang = 0;
    for(int i=0; i<n; i++){
        if(a[x][i] == 1){
            hang++;
        }
    }
    if(hang > 1){
        return 0;
    }
    return 1;
}

int check_cot(int x, int y){
    int cot = 0;
    for(int i=0; i<n; i++){
        if(a[i][y] == 1){
            cot++;
        }
    }
    if(cot > 1){
        return 0;
    }
    return 1;
}

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
    if(cheo > 1) return 0;
    return 1;
}

void solution(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf(" %d", a[i][j]);
        }
        printf("\n");
    }
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    int empty_row =0, check_row = 0;
    for(int i=0; i<n; i++){
        check_row = 0;
        for(int j=0; j<n; j++){
            if(a[i][j] == 1){
            if(check_hang(i,j) == 0 || check_cot(i,j) == 0 || check_cheo(i,j) == 0 ){
                printf("-1");
                return 0;
            }
            }
            if(a[i][j] == 1 ){
                check_row = 1;
            }
        }
        if(check_row == 0){
            for(int y=0; y<n; y++ ){
                a[i][y] = 1;
                if(check_hang(i,y) == 1 && check_cot(i,y) == 1 && check_cheo(i,y) == 1 ){
                    a[i][y] = 1;
                    solution();
                    return 0;
                }
                a[i][y] = 0;
            }
        }
    }

    
    return 0;


}