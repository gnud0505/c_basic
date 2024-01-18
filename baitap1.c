#include <stdio.h>

int main(){
    int n, k;
    scanf("%d %d", &k, &n);
    int A[n];
    for(int i=0; i<n; i++ ){
        scanf("%d", &A[i]);
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(A[i] < A[j]){
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
    int sum=0;
    for(int i=0; i<k; i++){
        sum = sum + A[i];
    }
    printf("%d", sum);
}