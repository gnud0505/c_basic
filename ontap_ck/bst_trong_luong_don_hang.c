#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100000
#define MAX_ORDERS 10000

// Struct để lưu thông tin về mặt hàng
typedef struct {
    char code[10];
    int weight;
} Item;

// Struct để lưu thông tin về đơn hàng
typedef struct {
    int count;
    char codes[MAX_ITEMS][10];
    int quantities[MAX_ITEMS];
} Order;

// Struct để lưu thông tin về cây nhị phân
typedef struct TreeNode {
    Item item;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Hàm để tạo một nút mới cho cây nhị phân
TreeNode* createNode(Item item) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(newNode->item.code, item.code);
    newNode->item.weight = item.weight;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Hàm để thêm một mặt hàng vào cây nhị phân
TreeNode* insert(TreeNode* root, Item item) {
    if (root == NULL) {
        return createNode(item);
    }

    // So sánh mã số để xác định nơi thêm mặt hàng vào cây
    int compareResult = strcmp(item.code, root->item.code);

    if (compareResult < 0) {
        root->left = insert(root->left, item);
    } else if (compareResult > 0) {
        root->right = insert(root->right, item);
    }

    return root;
}

// Hàm để tìm một mặt hàng trong cây nhị phân
Item* search(TreeNode* root, const char* code) {
    if (root == NULL || strcmp(code, root->item.code) == 0) {
        return root == NULL ? NULL : &root->item;
    }

    if (strcmp(code, root->item.code) < 0) {
        return search(root->left, code);
    } else {
        return search(root->right, code);
    }
}

// Hàm để giải phóng bộ nhớ của cây nhị phân
void freeTree(TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    int n, m;
    scanf("%d", &n);

    // Đọc thông tin về mặt hàng và tạo cây nhị phân
    TreeNode* root = NULL;
    Item items[MAX_ITEMS];
    for (int i = 0; i < n; ++i) {
        scanf("%s %d", items[i].code, &items[i].weight);
        root = insert(root, items[i]);
    }

    scanf("%d", &m);

    // Xử lý từng đơn hàng
    for (int i = 0; i < m; ++i) {
        int k;
        scanf("%d", &k);

        // Tạo và đọc thông tin về đơn hàng
        Order order;
        order.count = k;
        for (int j = 0; j < k; ++j) {
            scanf("%s %d", order.codes[j], &order.quantities[j]);
        }

        // Tính tổng trọng lượng cho đơn hàng
        int totalWeight = 0;
        for (int j = 0; j < k; ++j) {
            Item* foundItem = search(root, order.codes[j]);
            if (foundItem != NULL) {
                totalWeight += order.quantities[j] * foundItem->weight;
            }
        }

        // Xuất kết quả cho đơn hàng
        printf("%d\n", totalWeight);
    }

    // Giải phóng bộ nhớ của cây nhị phân
    freeTree(root);

    return 0;
}
