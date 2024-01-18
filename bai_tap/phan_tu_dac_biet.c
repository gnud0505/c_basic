#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    int sum = 0;
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
        sum += A[i];
    }

    double tb=sum/n;
    int gan_tb = A[0];
    double dmin = abs(A[0] - tb);
    for(int i=1; i<n; i++){
        double d = abs(A[i]-tb);
        if(d<dmin){
            gan_tb = A[i];
            dmin = d;
        }
    }
    printf("%d", gan_tb);
    
}