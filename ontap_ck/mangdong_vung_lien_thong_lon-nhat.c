#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int m, n;
int **matrix;
int **visited;

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

    // Khởi tạo ma trận và visited
    matrix = (int **)malloc(m * sizeof(int *));
    visited = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
        visited[i] = (int *)malloc(n * sizeof(int));
    }

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

    // Giải phóng bộ nhớ
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
        free(visited[i]);
    }
    free(matrix);
    free(visited);

    return 0;
}
