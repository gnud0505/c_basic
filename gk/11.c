#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char maso[10];
    int trongluong;
} MatHang;

typedef struct TreeNode {
    MatHang data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* insertTreeNode(TreeNode* root, MatHang mat_hang) {
    if (root == NULL) {
        TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
        newNode->data = mat_hang;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    int compareResult = strcmp(mat_hang.maso, root->data.maso);

    if (compareResult < 0) {
        root->left = insertTreeNode(root->left, mat_hang);
    } else if (compareResult > 0) {
        root->right = insertTreeNode(root->right, mat_hang);
    }

    return root;
}

TreeNode* searchTreeNode(TreeNode* root, char maso[]) {
    if (root == NULL || strcmp(maso, root->data.maso) == 0) {
        return root;
    }

    if (strcmp(maso, root->data.maso) < 0) {
        return searchTreeNode(root->left, maso);
    } else {
        return searchTreeNode(root->right, maso);
    }
}

void freeTree(TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

typedef struct {
    int slmuchang;
    char masomuchang[10000][10];
    int slsanpham[10];
} DonHang;

int main() {
    long n, m;

    scanf("%ld", &n);

    MatHang mathang[n];
    TreeNode* root = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%s %d", mathang[i].maso, &mathang[i].trongluong);
        root = insertTreeNode(root, mathang[i]);
    }

    scanf("%ld", &m);

    for (int i = 0; i < m; i++) {
        DonHang donhang;

        scanf("%d", &donhang.slmuchang);

        for (int j = 0; j < donhang.slmuchang; j++) {
            scanf("%s %d", donhang.masomuchang[j], &donhang.slsanpham[j]);
        }

        int tongtl = 0;
        for (int j = 0; j < donhang.slmuchang; j++) {
            TreeNode* node = searchTreeNode(root, donhang.masomuchang[j]);
            if (node != NULL) {
                tongtl += node->data.trongluong * donhang.slsanpham[j];
            }
        }

        printf("%d\n", tongtl);
    }

    freeTree(root);

    return 0;
}
