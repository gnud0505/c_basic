#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char ma_san_pham[10];
    int so_luong;
    int gia_ban;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(char ma_san_pham[], int so_luong, int gia_ban) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->ma_san_pham, ma_san_pham);
    newNode->so_luong = so_luong;
    newNode->gia_ban = gia_ban;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, char ma_san_pham[], int so_luong, int gia_ban) {
    if (root == NULL) {
        return createNode(ma_san_pham, so_luong, gia_ban);
    }

    if (strcmp(ma_san_pham, root->ma_san_pham) < 0) {
        root->left = insert(root->left, ma_san_pham, so_luong, gia_ban);
    } else if (strcmp(ma_san_pham, root->ma_san_pham) > 0) {
        root->right = insert(root->right, ma_san_pham, so_luong, gia_ban);
    } else {
        root->so_luong += so_luong;
        printf("%d -1\n", root->so_luong);
    }

    return root;
}

Node *search(Node *root, char ma_san_pham[]) {
    if (root == NULL || strcmp(ma_san_pham, root->ma_san_pham) == 0) {
        return root;
    }

    if (strcmp(ma_san_pham, root->ma_san_pham) < 0) {
        return search(root->left, ma_san_pham);
    }

    return search(root->right, ma_san_pham);
}

void update(Node *root, char ma_san_pham[], int gia_moi) {
    Node *node = search(root, ma_san_pham);

    if (node != NULL) {
        int gia_cu = node->gia_ban;
        node->gia_ban = gia_moi;
        printf("%d %d\n", gia_cu, node->gia_ban);
    } else {
        printf("San pham khong ton tai\n");
    }
}

Node *deleteNode(Node *root, char ma_san_pham[]) {
    if (root == NULL) {
        return root;
    }

    if (strcmp(ma_san_pham, root->ma_san_pham) < 0) {
        root->left = deleteNode(root->left, ma_san_pham);
    } else if (strcmp(ma_san_pham, root->ma_san_pham) > 0) {
        root->right = deleteNode(root->right, ma_san_pham);
    } else {
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }

        strcpy(root->ma_san_pham, temp->ma_san_pham);
        root->so_luong = temp->so_luong;
        root->gia_ban = temp->gia_ban;

        root->right = deleteNode(root->right, temp->ma_san_pham);
    }

    return root;
}


int isProductExist(Node *root, char ma_san_pham[]) {
    Node *node = search(root, ma_san_pham);
    return (node != NULL);
}

int main() {
    Node *root = NULL;
    int so_luong_san_pham, so_luong_yeu_cau;
    char lenh[10], ma_san_pham[10];
    int so_luong, gia_ban;

    scanf("%d", &so_luong_san_pham);
    for (int i = 0; i < so_luong_san_pham; i++) {
        scanf("%s %d %d", ma_san_pham, &so_luong, &gia_ban);
        root = insert(root, ma_san_pham, so_luong, gia_ban);
    }

    scanf("%d", &so_luong_yeu_cau);
    for (int i = 0; i < so_luong_yeu_cau; i++) {
        scanf("%s", lenh);

        if (strcmp(lenh, "add") == 0) {
            scanf("%s %d", ma_san_pham, &so_luong);

            if (isProductExist(root, ma_san_pham)) {
                Node *node = search(root, ma_san_pham);
                node->so_luong += so_luong;
                printf("%d %d\n", node->so_luong, node->gia_ban);
            } else {
                printf("%d -1\n", so_luong);
            }
        } else if (strcmp(lenh, "update") == 0) {
            scanf("%s %d", ma_san_pham, &gia_ban);
            update(root, ma_san_pham, gia_ban);
        } else if (strcmp(lenh, "delete") == 0) {
            scanf("%s", ma_san_pham);
            if (isProductExist(root, ma_san_pham)) {
                root = deleteNode(root, ma_san_pham);
                printf("Da xoa san pham\n");
            } else {
                printf("San pham khong ton tai\n");
            }
        } else if (strcmp(lenh, "check") == 0) {
            scanf("%s", ma_san_pham);
            Node *node = search(root, ma_san_pham);
            if (node != NULL) {
                printf("%d %d\n", node->so_luong, node->gia_ban);
            } else {
                printf("San pham khong ton tai\n");
            }
        } else if (strcmp(lenh, "order") == 0) {
            scanf("%s %d", ma_san_pham, &so_luong);
            Node *node = search(root, ma_san_pham);
            if (node != NULL) {
                if (node->so_luong < so_luong) {
                    printf("Khong du so luong\n");
                } else if (node->gia_ban < 0) {
                    printf("Khong the dat hang san pham chua co gia\n");
                } else {
                    node->so_luong -= so_luong;
                    int tong_gia_tri = so_luong * node->gia_ban;
                    printf("Da dat hang %d %d\n", node->so_luong, tong_gia_tri);
                }
            } else {
                printf("San pham khong ton tai\n");
            }
        }
    }

    free(root);

    return 0;
}
