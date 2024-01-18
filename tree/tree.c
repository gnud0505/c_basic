#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nnode{
    char key[256];
    struct nnode *left;
    struct nnode *rsib;
};

struct ntree {
    struct nnode *root;
    long size;
};

struct nnode *nnode(const char *key){
    struct nnode *n = malloc(sizeof(struct nnode));
    strcpy(n->key, key);
    n->left = NULL;
    n->rsib = NULL;
}

struct ntree *ntree(){
    struct ntree *t = malloc (sizeof(struct ntree));
    t->root = NULL;
    t->size =0;
}

struct nnode *nfind(struct ntree *t, const char *key){
    struct nnode *x = t->root;
    // duyet tat ca cac node trong x
    while (x)
    {
        if(strcmp(x->key, key) == 0){
            return x;
        }
    }
    
}

struct ntree *nadd(struct ntree *t, const char *pkey, const char *nkey){
    if(t->root == NULL){
        t->root = nnode(nkey);
        return t;
    }
    struct nnode *p = nfind(t, pkey);
    if(!p){
        return NULL;
    }
}

void nprint(struct ntree *t){
    // Xuat cac gia tri cua cay
}

void nheight(struct ntree *t){
    // Do do cao cua cay
}

int main(){

}