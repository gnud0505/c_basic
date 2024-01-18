#include <stdio.h>
#include <stdlib.h>

// Prototypes
int check_hang(int **x, int a, int b);
int check_cot(int **x, int a, int b);
int check_khoi(int **x, int a, int b);
void solution(int **x);
int try(int **x, int a, int b);

int check_hang(int **x, int a, int b){
    for(int i=0; i<b; i++){
        if(x[a][b] == x[a][i]) return 1;
    }
    return 0;
}

int check_cot(int **x, int a, int b){
    for(int i=0; i<a; i++){
        if(x[a][b] == x[i][b]) return 1;
    }
    return 0;
}

int check_khoi(int **x, int a, int b){
    int I = a/3, J = b/3;
    int tmp = -1;
    for(int i=0; i<=2; i++){
        for(int j=0; j<=2; j++){
            if(x[a][b] == x[3*I+i][3*J+j] ) tmp ++;
        }
    }
    return tmp;
}

int try(int **x, int a, int b){
    for(int i=1; i<=9; i++){
        x[a][b] = i;
        if(check_hang(x,a,b) == 0 && check_cot(x,a,b) == 0 && check_khoi(x,a,b) == 0){
            if(a == 8 && b == 8){ 
                solution(x);
                return 0;
            }
            else{
                if(b ==8) try(x,a+1,0);
                try(x,a,b+1);
            }
        }
    }
    x[a][b] = 0;
    return 1;
}

void solution(int **x){
    for(int i = 0; i<9; i++){
        for(int j=0; j<9; j++){
            printf("%d ", x[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int **x = (int **)malloc(9 * sizeof(int *));
    for (int i = 0; i < 9; i++) {
        x[i] = (int *)malloc(9 * sizeof(int));
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            x[i][j] = 0;
        }
    }
    try(x,0,0);
}