#include <stdio.h>

#define MAX_SIZE 1000

int m, n;

int isValid(int matrix[MAX_SIZE][MAX_SIZE], int visited[MAX_SIZE][MAX_SIZE], int i, int j) {
    return (i >= 0 && i < m && j >= 0 && j < n && matrix[i][j] && !visited[i][j]);
}

int d(int matrix[MAX_SIZE][MAX_SIZE], int visited[MAX_SIZE][MAX_SIZE], int i, int j) {
    int row[] = { -1, 0, 0, 1 };
    int col[] = { 0, -1, 1, 0 };

    visited[i][j] = 1;
    int count = 1;

    for (int k = 0; k < 4; ++k) {
        int newI = i + row[k];
        int newJ = j + col[k];

        if (isValid(matrix, visited, newI, newJ) && matrix[newI][newJ] == matrix[i][j]) {
            count += d(matrix, visited, newI, newJ);
        }
    }

    return count;
}

int find(int matrix[MAX_SIZE][MAX_SIZE]) {
    int visited[MAX_SIZE][MAX_SIZE] = {0}; 

    int max = 0; 

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!visited[i][j] && matrix[i][j] != 0) {
                int currentRegion = d(matrix, visited, i, j);
                if (currentRegion > max) {
                    max = currentRegion;
                }
            }
        }
    }
    return max;
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    scanf("%d %d", &m, &n);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("%d", find(matrix));

    return 0;
}