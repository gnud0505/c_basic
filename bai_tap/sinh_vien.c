#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int stt;
    char mssv[10];
    char name[30];
    char sdt[15];
    float diem;
} SinhVien;

int main() {
    FILE *fptr, *fout;
    if ((fptr = fopen("sinh_vien.txt", "r")) == NULL) {
        printf("Error");
        return 1;
    }

    if ((fout = fopen("bangdiem.txt", "w")) == NULL) {
        printf("Error");
        fclose(fptr);
        return 1;
    }

    SinhVien sinhvien[100];
    int i = 0;

    while (fscanf(fptr, "%d %s %s %s", &sinhvien[i].stt, sinhvien[i].mssv, sinhvien[i].name, sinhvien[i].sdt) != EOF) {
        printf("Nhap diem %s: ", sinhvien[i].mssv);
        scanf("%f", &sinhvien[i].diem);
        i++;
    }

    for (int j = 0; j < i; j++) {
        fprintf(fout, "%d\t%s\t%s\t%s\t%f\n", sinhvien[j].stt, sinhvien[j].mssv, sinhvien[j].name, sinhvien[j].sdt, sinhvien[j].diem);
    }

    fclose(fptr);
    fclose(fout);

    return 0;
}
