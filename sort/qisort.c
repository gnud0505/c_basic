#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*cmp_t)(const void *, const void *);
int icmp(const void *p1, const void *p2 ){
    return *(const int *)p1 - *(const int *)p2;
}

void vswap(char *p, char *q,int sz){
    for(int i=0; i<sz; i++){
        char tmp = *p;
        *p = *q;
        *q = tmp;
        ++p;
        ++q;
    }
}
void q2sort(void *a, int n, int sz, cmp_t cmp){
    if(n <= 1) return;
    void *left = a, *right = a + (n-2) * sz;
    void *v = a + (n-1) * sz;
    for(;;){
        while(cmp(left, v) < 0){
            left += sz;
        }
        while (cmp(right, v) >= 0 || right !=a)
        {
            right -= sz;
        }

        if(left >= right) break;
        //vswap
        vswap(left, right, sz);
    }
    vswap(left, v, sz);
    q2sort(a, (left-sz-a)/sz +1, sz, cmp);
    q2sort(left+sz, (v-left-sz)/sz+1, sz, cmp);
}