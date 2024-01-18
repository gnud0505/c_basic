#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//san pham bao gom: masp (char[10]), gia (int) ,soluong (int)
typedef struct TreeNode {
    char ma_so[10];
    int so_luong;
    int gia_ban;
    struct TreeNode *left;
    struct TreeNode *right;
} *tree;


//tao cay rong
tree createNullTree() {
    return NULL;
}

//tao la
tree createLeaf(char ma_so[], int so_luong, int gia_ban) {
    tree tmp = (tree)malloc(sizeof(struct TreeNode));
    strcpy(tmp->ma_so, ma_so);
    tmp->so_luong = so_luong;
    tmp->gia_ban = gia_ban;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

//kiem tra cay rong
int isNullTree(tree t) {
    return (t == NULL);
}


//them mot node
tree insertBST(tree t, char ma_so[], int so_luong, int gia_ban) {
    if (isNullTree(t)) {
        return createLeaf(ma_so, so_luong, gia_ban);
    }

    if (strcmp(t->ma_so, ma_so) == 0) {
        t->so_luong += so_luong;
        return t;
    } else if (strcmp(t->ma_so, ma_so) > 0) {
        t->left = insertBST(t->left, ma_so, so_luong, gia_ban);
        return t;
    } else {
        t->right = insertBST(t->right, ma_so, so_luong, gia_ban);
        return t;
    }
}

//tim kiem
tree searchBST(tree t, char ma_so[]) {
    if (isNullTree(t)) {
        return NULL;
    }

    if (strcmp(t->ma_so, ma_so) == 0) {
        return t;
    } else if (strcmp(t->ma_so, ma_so) > 0) {
        return searchBST(t->left, ma_so);
    } else {
        return searchBST(t->right, ma_so);
    }
}

//node trai nhat
tree leftMost(tree t) {
    if (isNullTree(t)) {
        return NULL;
    } else {
        while (t->left != NULL) {
            t = t->left;
        }
    }
    return t;
}

//xoa node
tree removeBST(tree t, char ma_so[]) {
    if (isNullTree(t)) {
        return NULL;
    }

    if (searchBST(t, ma_so) != NULL) {
        if (strcmp(t->ma_so, ma_so) == 0) {
            if (t->right == NULL) {
                tree tmp = t->left;
                free(t);
                return tmp;
            }

            if (t->left == NULL) {
                tree tmp = t->right;
                free(t);
                return tmp;
            }

            t->so_luong = leftMost(t->right)->so_luong;
            strcpy(t->ma_so, leftMost(t->right)->ma_so);
            t->gia_ban = leftMost(t->right)->gia_ban;
            t->right = removeBST(t->right, t->ma_so);

            return t;
        } else if (strcmp(t->ma_so, ma_so) > 0) {
            t->left = removeBST(t->left, ma_so);
        } else {
            t->right = removeBST(t->right, ma_so);
        }
    } else {
        printf("San pham khong ton tai\n");
    }
    return t;
}

//giai phong cay
void freeTree(tree t) {
    if (t != NULL) {
        freeTree(t->left);
        freeTree(t->right);
        free(t);
    }
}

//in thong tin
void printProductInfo(tree node) {
    printf("%d %d\n", node->so_luong, node->gia_ban);
}

//them san pham
void addProduct(tree *root, char ma_so[], int so_luong, int gia_ban) {
    tree node = searchBST(*root, ma_so);
    if (node == NULL) {
        *root = insertBST(*root, ma_so, so_luong, gia_ban);
        printProductInfo(searchBST(*root, ma_so));
    } else {
        node->so_luong += so_luong;
        if (node->gia_ban == -1) {
            node->gia_ban = gia_ban;
        }
        printProductInfo(node);
    }
}

//cap nhat
void updateProduct(tree root, char ma_so[], int gia_moi) {
    tree node = searchBST(root, ma_so);
    if (node == NULL) {
        printf("San pham khong ton tai\n");
    } else {
        int gia_cu = node->gia_ban;
        node->gia_ban = gia_moi;
        printf("%d %d\n", gia_cu, node->gia_ban);
    }
}

//xoa
void deleteProduct(tree *root, char ma_so[]) {
    tree node = searchBST(*root, ma_so);
    if (node == NULL) {
        printf("San pham khong ton tai\n");
    } else {
        *root = removeBST(*root, ma_so);
        printf("Da xoa san pham\n");
    }
}

//tim kiem
void checkProduct(tree root, char ma_so[]) {
    tree node = searchBST(root, ma_so);
    if (node == NULL) {
        printf("San pham khong ton tai\n");
    } else {
        printProductInfo(node);
    }
}

//dat hang
void orderProduct(tree *root, char ma_so[], int so_luong) {
    tree node = searchBST(*root, ma_so);
    if (node == NULL) {
        printf("San pham khong ton tai\n");
    } else {
        if (so_luong > node->so_luong) {
            printf("Khong du so luong\n");
        } else if (node->gia_ban < 0) {
            printf("Khong the dat hang san pham chua co gia\n");
        } else {
            node->so_luong -= so_luong;
            int total_price = so_luong * node->gia_ban;
            printf("Da dat hang %d %d\n", node->so_luong, total_price);
        }
    }
}

int main() {
    int n, m;

    scanf("%d", &n);

    tree root = createNullTree();
    for (int i = 0; i < n; i++) {
        char ma_so[10];
        int so_luong, gia_ban;
        scanf("%s %d %d", ma_so, &so_luong, &gia_ban);
        root = insertBST(root, ma_so, so_luong, gia_ban);
    }

    scanf("%d", &m);

    for (int j = 0; j < m; j++) {
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char ma_so[10];
            int so_luong, gia_ban;
            scanf("%s %d", ma_so, &so_luong);
            gia_ban = -1;
            addProduct(&root, ma_so, so_luong, gia_ban);
        } else if (strcmp(command, "update") == 0) {
            char ma_so[10];
            int gia_ban;
            scanf("%s %d", ma_so, &gia_ban);
            updateProduct(root, ma_so, gia_ban);
        } else if (strcmp(command, "delete") == 0) {
            char ma_so[10];
            scanf("%s", ma_so);
            deleteProduct(&root, ma_so);
        } else if (strcmp(command, "check") == 0) {
            char ma_so[10];
            scanf("%s", ma_so);
            checkProduct(root, ma_so);
        } else if (strcmp(command, "order") == 0) {
            char ma_so[10];
            int so_luong;
            scanf("%s %d", ma_so, &so_luong);
            orderProduct(&root, ma_so, so_luong);
        }
    }

    freeTree(root);

    return 0;
}