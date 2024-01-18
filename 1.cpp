#include <stdio.h>

typedef union generic_type{
    long l;
    double d;
    char *s;
    void *v;
    union generic_type *g;
    struct gsllist *gsl;
    struct vector *vec;
    struct rbmtree *rbm;
}gtype;

int main(){
    gtype g;
    scanf("%s", g.s);
    printf("%s", g.s);
    return 0;
}
