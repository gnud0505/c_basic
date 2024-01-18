#include <stdio.h>
#include <string.h>

typedef struct {
    char maso[10];
    int trongluong;
} MatHang;

typedef struct {
    int slmuchang;
    char masomuchang[10000][10];
    int slsanpham[10];
} DonHang;

int main() {
    long n, m;

    scanf("%ld", &n);

    MatHang mathang[n];
    for (int i = 0; i < n; i++) {
        scanf("%s %d", mathang[i].maso, &mathang[i].trongluong);
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
            for (int k = 0; k < n; k++) {
                if (strcmp(donhang.masomuchang[j], mathang[k].maso) == 0) {
                    tongtl += mathang[k].trongluong * donhang.slsanpham[j];
                    break;
                }
            }
        }

        printf("%d\n", tongtl);
    }

    return 0;
}
