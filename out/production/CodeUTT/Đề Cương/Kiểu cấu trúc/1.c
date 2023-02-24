
/*
    Cấu trúc sinh viên bao gồm masv, hoten, dtb. In ra dtb > 8, in ra tt sinh viên có mã = 002 và hoten = "anh".

*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

typedef struct Sinhvien {
    char masv[10];
    char name[20];
    float dtb;
} Sinhvien;

Sinhvien sinhvien(Sinhvien sv) {
    if (sv.dtb > 8) 
        printf("\ndtb: %d ", sv.dtb);
    if (strcmp((sv.masv), "002") == 0) 
        printf("\nMasv: %s", sv.masv);
    if (strcmp((sv.hoten), "anh") == 0) 
        printf("hoten: %s", sv.hoten);
}

int main() {
    Sinhvien sv;
    printf("Nhap vao masv: "); gets(sv. masv);
    printf("Nhap vao name: "); gets(sv.name);
    printf("Nhap vao tongdiem: "); scanf("%f", &sv.dtb);

    sinhvien(sv);

    return 0;
}