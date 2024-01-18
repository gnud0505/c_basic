#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char loai[4];
    // Các trường dữ liệu khác
} Web;

// Hàm so sánh tùy chỉnh dựa trên mức độ loại thông báo
int compareByType(const void *a, const void *b) {
    const Web *webA = (const Web *)a;
    const Web *webB = (const Web *)b;

    if (strcmp(webA->loai, "ERRO") == 0) return -1;
    if (strcmp(webB->loai, "ERRO") == 0) return 1;
    if (strcmp(webA->loai, "WARN") == 0) return -1;
    if (strcmp(webB->loai, "WARN") == 0) return 1;
    if (strcmp(webA->loai, "INFO") == 0) return -1;
    if (strcmp(webB->loai, "INFO") == 0) return 1;

    return 0; // Trường hợp còn lại
}

int main() {
    // Khai báo và khởi tạo mảng Web
    Web webArray[] = {
        {"WARN"}, {"INFO"}, {"ERRO"}, {"ERRO"}, {"WARN"}, {"INFO"}
        // Thêm các dữ liệu khác nếu cần
    };
    size_t n = sizeof(webArray) / sizeof(webArray[0]);

    // Sắp xếp mảng sử dụng hàm so sánh tùy chỉnh
    qsort(webArray, n, sizeof(Web), compareByType);

    // In ra kết quả
    for (size_t i = 0; i < n; ++i) {
        printf("%s\n", webArray[i].loai);
        // In ra các trường dữ liệu khác nếu cần
    }

    return 0;
}
