#include <stdio.h>

#define MAX_SIZE 10000

int m, n;
int matrix[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];

int max(int a, int b) {
    return (a > b) ? a : b;
}

int isValid(int row, int col, int prevValue) {
    return (row >= 0 && row < m && col >= 0 && col < n && matrix[row][col] == prevValue && !visited[row][col]);
}

int DFS(int row, int col, int prevValue) {
    int count = 1;
    visited[row][col] = 1;

    // Kiểm tra các ô kề nhau
    if (isValid(row - 1, col, prevValue)) // Trên
        count += DFS(row - 1, col, prevValue);

    if (isValid(row + 1, col, prevValue)) // Dưới
        count += DFS(row + 1, col, prevValue);

    if (isValid(row, col - 1, prevValue)) // Trái
        count += DFS(row, col - 1, prevValue);

    if (isValid(row, col + 1, prevValue)) // Phải
        count += DFS(row, col + 1, prevValue);

    return count;
}

int main() {
    // Nhập kích thước ma trận
    scanf("%d %d", &m, &n);

    // Nhập ma trận
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
            visited[i][j] = 0; // Khởi tạo mảng visited
        }
    }

    int maxConnectedRegion = 0;

    // Duyệt qua từng ô của ma trận
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                int currentRegion = DFS(i, j, matrix[i][j]);
                maxConnectedRegion = max(maxConnectedRegion, currentRegion);
            }
        }
    }

    // In ra kết quả
    printf("%d\n", maxConnectedRegion);

    return 0;
}
