#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HLEFT(i) (((i) << 1) + 1)
#define HRIGHT(i) (((i) << 1) + 2)

typedef struct {
    char time[20];
    char loai[4];
    char nd[256];
} Web;

// Hàm so sánh giữa hai thông báo Web
int compare(Web* a, Web* b) {
    // So sánh theo mức độ Loại thông báo giảm dần
    int typeComparison = strcmp(a->loai, b->loai);
    if (typeComparison != 0) {
        if (strcmp(a->loai, "ERRO") == 0) return 1;
        if (strcmp(a->loai, "WARN") == 0 && strcmp(b->loai, "ERRO") == 0) return -1;
        if (strcmp(a->loai, "INFO") == 0 && strcmp(b->loai, "ERRO") == 0) return -1;
        if (strcmp(a->loai, "INFO") == 0 && strcmp(b->loai, "WARN") == 0) return -1;
    }

    // So sánh theo thời điểm tăng dần
    int timeComparison = strcmp(a->time, b->time);
    if (timeComparison != 0) {
        return timeComparison;
    }

    // So sánh theo nội dung tăng dần
    return strcmp(a->nd, b->nd);
}

// Hàm đổi chỗ hai thông báo Web
void swap(Web *a, Web *b) {
    Web temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm điều chỉnh heap xuống
void heapShiftDown(long i, long n, Web *web) {
    for (;;) {
        long lc = HLEFT(i), rc = HRIGHT(i), root = i;
        if (lc < n && compare(&web[root], &web[lc]) < 0) {
            root = lc;
        }
        if (rc < n && compare(&web[root], &web[rc]) < 0) {
            root = rc;
        }

        if (root == i) {
            break;
        }
        swap(&web[i], &web[root]);
        i = root;
    }
}

// Hàm tạo heap
void makeHeap(long n, Web *web) {
    for (long i = n / 2; i >= 0; --i) {
        heapShiftDown(i, n, web);
    }
}

int main() {
    Web *web = (Web *)malloc(10000 * sizeof(Web));
    int i = 0;

    // Đọc dữ liệu từ bàn phím
    while (i < 10000) {
        fgets(web[i].time, 20 * sizeof(char), stdin);
        web[i].time[strlen(web[i].time) - 1] = '\0'; // Loại bỏ ký tự '\n'

        fgets(web[i].loai, 4 * sizeof(char), stdin);
        web[i].loai[strlen(web[i].loai) - 1] = '\0'; // Loại bỏ ký tự '\n'

        fgets(web[i].nd, 256 * sizeof(char), stdin);
        web[i].nd[strlen(web[i].nd) - 1] = '\0'; // Loại bỏ ký tự '\n'

        char c = getchar();
        if (c == EOF || c == '\n') break;
        i++;
    }

    int n = i;
    if (n > 0) {
        makeHeap(n, web);

        // In ra kết quả đã sắp xếp
        for (int i = 0; i < n; i++) {
            printf("%s\n %s\n %s\n", web[i].time, web[i].loai, web[i].nd);
            swap(&web[0], &web[n - i - 1]);
            heapShiftDown(0, n - i - 1, web);
        }
    }

    free(web);
    return 0;
}
