#include <stdio.h>

int main(){
    int A[] = {12, 23, 34, 45, 56, 67, 78, 89, 90};
    int *P;
    P = A;
    printf("%d", &A[4]-3);
}