#include <stdio.h>
#include <string.h>

#define SO_LUONG_SAN_PHAM 100000
#define SO_LUONG_YEU_CAU 10000

typedef struct {
    char ma_san_pham[10];
    int so_luong;
    int gia_ban;
} SanPham;

SanPham san_pham[SO_LUONG_SAN_PHAM];

void add(char ma_san_pham[], int so_luong, int gia_ban) {
    for (int i = 0; i < SO_LUONG_SAN_PHAM; i++) {
        if (strcmp(san_pham[i].ma_san_pham, ma_san_pham) == 0) {
            san_pham[i].so_luong += so_luong;
            printf("%d %d\n", san_pham[i].so_luong, san_pham[i].gia_ban);
            return;
        }
    }

    for (int i = 0; i < SO_LUONG_SAN_PHAM; i++) {
        if (san_pham[i].ma_san_pham[0] == '\0') {
            strcpy(san_pham[i].ma_san_pham, ma_san_pham);
            san_pham[i].so_luong = so_luong;
            san_pham[i].gia_ban = (gia_ban == -1) ? -1 : gia_ban;
            printf("%d %d\n", san_pham[i].so_luong, san_pham[i].gia_ban);
            return;
        }
    }

}

void update(char ma_san_pham[], int gia_moi) {
    for (int i = 0; i < SO_LUONG_SAN_PHAM; i++) {
        if (strcmp(san_pham[i].ma_san_pham, ma_san_pham) == 0) {
            int gia_cu = san_pham[i].gia_ban;
            san_pham[i].gia_ban = gia_moi;
            printf("%d %d\n", gia_cu, san_pham[i].gia_ban);
            return;
        }
    }

    printf("San pham khong ton tai\n");
}

void delete(char ma_san_pham[]) {
    for (int i = 0; i < SO_LUONG_SAN_PHAM; i++) {
        if (strcmp(san_pham[i].ma_san_pham, ma_san_pham) == 0) {
            san_pham[i].ma_san_pham[0] = '\0';
            printf("Da xoa san pham\n");
            return;
        }
    }

    printf("San pham khong ton tai\n");
}

void check(char ma_san_pham[]) {
    for (int i = 0; i < SO_LUONG_SAN_PHAM; i++) {
        if (strcmp(san_pham[i].ma_san_pham, ma_san_pham) == 0) {
            printf("%d %d\n", san_pham[i].so_luong, san_pham[i].gia_ban);
            return;
        }
    }

    printf("San pham khong ton tai\n");
}

void order(char ma_san_pham[], int so_luong) {
    for (int i = 0; i < SO_LUONG_SAN_PHAM; i++) {
        if (strcmp(san_pham[i].ma_san_pham, ma_san_pham) == 0) {
            if (san_pham[i].so_luong < so_luong) {
                printf("Khong du so luong\n");
                return;
            }

            if (san_pham[i].gia_ban < 0) {
                printf("Khong the dat hang san pham chua co gia\n");
                return;
            }

            san_pham[i].so_luong -= so_luong;
            int tong_gia_tri = so_luong * san_pham[i].gia_ban;
            printf("Da dat hang %d %d\n", san_pham[i].so_luong, tong_gia_tri);
            return;
        }
    }

    printf("San pham khong ton tai\n");
}

int main() {
    int so_luong_san_pham, so_luong_yeu_cau;
    char lenh[10], ma_san_pham[10];
    int so_luong, gia_ban;

    scanf("%d", &so_luong_san_pham);
    for (int i = 0; i < so_luong_san_pham; i++) {
        scanf("%s %d %d", ma_san_pham, &so_luong, &gia_ban);
        add(ma_san_pham, so_luong, gia_ban);
    }

    scanf("%d", &so_luong_yeu_cau);
    for (int i = 0; i < so_luong_yeu_cau; i++) {
        scanf("%s", lenh);

        if (strcmp(lenh, "add") == 0) {
            scanf("%s %d", ma_san_pham, &so_luong);
            add(ma_san_pham, so_luong, -1);
        } else if (strcmp(lenh, "update") == 0) {
            scanf("%s %d", ma_san_pham, &gia_ban);
            update(ma_san_pham, gia_ban);
        } else if (strcmp(lenh, "delete") == 0) {
            scanf("%s", ma_san_pham);
            delete(ma_san_pham);
        } else if (strcmp(lenh, "check") == 0) {
            scanf("%s", ma_san_pham);
            check(ma_san_pham);
        } else if (strcmp(lenh, "order") == 0) {
            scanf("%s %d", ma_san_pham, &so_luong);
            order(ma_san_pham, so_luong);
        }
    }

    return 0;
}
