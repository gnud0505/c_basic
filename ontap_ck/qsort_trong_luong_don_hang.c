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

// Hàm so sánh để sử dụng với qsort
int compareItems(const void *a, const void *b) {
    return strcmp(((Item *)a)->code, ((Item *)b)->code);
}

int main() {
    int n, m;
    scanf("%d", &n);

    // Đọc thông tin về mặt hàng
    Item items[MAX_ITEMS];
    for (int i = 0; i < n; ++i) {
        scanf("%s %d", items[i].code, &items[i].weight);
    }

    // Sắp xếp mảng mặt hàng theo mã số
    qsort(items, n, sizeof(Item), compareItems);

    scanf("%d", &m);

    // Xử lý từng đơn hàng
    for (int i = 0; i < m; ++i) {
        Order order;
        scanf("%d", &order.count);

        // Đọc thông tin về mỗi mặt hàng trong đơn hàng
        for (int j = 0; j < order.count; ++j) {
            scanf("%s %d", order.codes[j], &order.quantities[j]);
        }

        // Tính tổng trọng lượng cho đơn hàng
        int totalWeight = 0;
        for (int j = 0; j < order.count; ++j) {
            // Sử dụng binary search thay vì duyệt tìm kiếm
            Item *foundItem = bsearch(order.codes[j], items, n, sizeof(Item), compareItems);
            if (foundItem != NULL) {
                totalWeight += order.quantities[j] * foundItem->weight;
            }
        }

        // Xuất kết quả cho đơn hàng
        printf("%d\n", totalWeight);
    }

    return 0;
}
