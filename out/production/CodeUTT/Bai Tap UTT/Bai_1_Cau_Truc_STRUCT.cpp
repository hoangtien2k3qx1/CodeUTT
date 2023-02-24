
/*
    Xây dựng cấu trúc nhân viên gồm: manv, hoten, tuoi.
    Viết chương trình nhâp vào thông tin nhân viên

    a. in thông tin danh sách nhân viên lên màn hình
    b. in các thông tin có  tuổi tư 55 - 60
    c. in ra Nhân Viên có manv = "001"

*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct NhanVien {
    char manv[20];
    char hoten[50];
    int tuoi;
} NhanVien;

void Print_Line(int n) {
    printf("\n");
    for(int i=0; i<n; i++)
        printf("_");
    printf("\n");
}

void Print_Thong_Tin(int i, NhanVien nv[]) {
    printf("\t\t%s", nv[i].manv);
    printf("\t\t\t%s", nv[i].hoten);
    printf("\t\t\t%d", nv[i].tuoi);
}

// a. in thông tin nhân viên ra màn hình
void Information_NhanVien(int n, NhanVien nv[]) {
    Print_Line(100);
    printf("\t\t\t---THONG TIN CAC NHAN VIEN--- ");
    printf("\nSTT\t\tMASV\t\t\tHO TEN\t\t\t\tTUOI");
    for(int i=0; i<n; i++) {
        printf("\n %d", i + 1);
        Print_Thong_Tin(i, nv);
    }
    Print_Line(100);
}

// b. in các thông tin có  tuổi tư 55 - 60
void Print_tuoi(int n, NhanVien nv[]) {
    printf("\t\t\t---NHAN VIEN CO TUOI TU 50 - 60t--- ");
    printf("\nSTT\t\tMASV\t\t\tHO TEN\t\t\t\tTUOI");
    for(int i=0; i<n; i++) {
        if (nv[i].tuoi >= 55 && nv[i].tuoi <= 60) {
            printf("\n %d", i + 1);
            Print_Thong_Tin(i, nv);
        }
    }
    Print_Line(100);
}


// c. in ra Nhân Viên có manv = "001"
void Check_Manv(int n, NhanVien nv[]) {
    printf("\t\t\t---NHAN VIEN CO MA [001]--- " );
    printf("\nSTT\t\tMASV\t\t\tHO TEN\t\t\t\tTUOI");
    char manv1[] = "001";
    for(int i=0; i<n; i++) {
        if (strcmp(manv1, nv[i].manv) == 0) {
            printf("\n %d", i + 1);
            Print_Thong_Tin(i, nv);
        }
    }
    Print_Line(100);
}


int main() {
    NhanVien nv[100];
    int n; // nhập vao số lượng nhân viên
    printf("Nhap vao so Nhan Vien: "); scanf("%d", &n);
    for(int i = 0; i < n; i++) { // nhập vào thông tin nhân viên.
        fflush(stdin);
        printf("\nNhap vao manv %d: ", i + 1); gets(nv[i].manv);
        printf("Nhap vao hoten: %d: ", i + 1); gets(nv[i].hoten);
        printf("Nhap vao tuoi: %d: ", i + 1); scanf("%d", &nv[i].tuoi); 
    }

    Information_NhanVien(n, nv);
    Print_tuoi(n, nv);
    Check_Manv(n, nv);

    return 0;
}

