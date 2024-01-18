#include <stdio.h>
#define MAX 1000
int a[MAX][MAX], visited[MAX][MAX], n;
int hang[MAX];

int check(int i, int j){
    
}

void try(int i, int j){
    if(check(i,j)){
        a[i][j] = 1;
    }
    if(j < n-1){
        try(i , j+1);
    }
    if(i < n-1){
        try(i+1, 0);
    }
    solution();
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            a[i][j] = 0;
            visited[i][j]=0;
        }
    }

    
}