#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char product_name[100];
    double price;
}Product;

int main(){
    FILE *fptr;
    Product product[100];
    int i=0;
    if((fptr = fopen("product.txt", "r")) == NULL){
        printf("Error");
        return 1;
    }
    printf("No\tProduct Name\t\tPrice\n");
    while (fscanf(fptr,"%d %s %ld", &product[i].id, &product[i].product_name, &product[i].price) != EOF)
    {
        printf("%d\t%s\t%ld\n", product[i].id, product[i].product_name, product[i].price);
    }
    
}