#include <stdio.h>

long C(int k, int n){
    if(k==0) return 1;
    if(k==n) return 1;
    return C(k, n-1) + C(k-1, n-1);
}

int main(){
    int k, n;
    scanf("%d %d", &k, &n);
    printf("%ld", C(k,n));
}