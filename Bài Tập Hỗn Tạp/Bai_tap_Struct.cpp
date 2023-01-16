
/*
    Xây dựng một cấu trúc sinh viên hồm:
    a. viết hàm nhập vào 1 danh sách gồm n nhân viên
    b. in danh sách nhân viên lên màn hình
    c. in ra thông tin nhân viên có lương cao nhất
    d. sắp xếp danh sách lương theo thứ tự giảm dần
    e. Tìm nhân viên có mã "001NV" . In kết quả lên màn hình.

*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct NhanVien{
    char manv[20];
    char hoten[30];
    float luong;
} NhanVien;

void print_line(int n) {
    printf("\n");
    for(int i=0; i<n; i++) {
        printf("_");
    }
    printf("\n");
}

void Nhap_Nhan_Vien(NhanVien &nv, int n) {
    fflush(stdin);
    printf("\nNhap vao manv: "); gets(nv.manv);
    printf("Nhap vao hoten: "); gets(nv.hoten);
    printf("Nhap vao luong: "); scanf("%f", &nv.luong);
}

// a. nhap vao danh sach gom n nhan vien.
void Nhap_vao_n_nhan_vien(NhanVien nv[], int n) {
    print_line(100);
    for(int i=0; i<n; i++) {
        printf("\nNhap vao Nhan Vien thu %d: ", i + 1);
        Nhap_Nhan_Vien(nv[i], n);
    }
    print_line(100);
}


void In_Nhan_Vien(NhanVien &nv, int i) {
    printf("\t\t%s", nv.manv);
    printf("\t\t\t%s", nv.hoten);
    printf("\t\t\t\t%f", nv.luong);
}

// b. in danh sach nhan vien len man hinh.
void In_Danh_Sach_Nhan_Vien(NhanVien nv[], int n) {
    print_line(100);
    printf("\n\t\t\t---Danh Sach Nhan Vien--- ");
    printf("\nSTT\t\tmanv\t\t\thoten\t\t\t\t\tluong");
    for(int i=0; i<n; i++) {
        printf("\n%d", i + 1);
        In_Nhan_Vien(nv[i], i);
    }
    print_line(100);
}

// c. thong tin nhan vien co luong cao nhat.
void Thong_Tin_Nhan_Vien_Luong_Cao_Nhat(NhanVien nv[], int n) {
    printf("\n\t\t\t---Nhan Vien Co Luong Cao Nhat--- ");
    printf("\nSTT\t\tmanv\t\t\thoten\t\t\t\t\tluong");
    int max = nv[0].luong;
    int temp;
    for(int i=0; i<n; i++) {
        if (nv[i].luong > max) {
            max  = nv[i].luong;
            temp = i;
        }
    }
    printf("\n%d", temp + 1);
    In_Nhan_Vien(nv[temp], temp);
    print_line(100);
}


// d. sắp xếp danh sách lương theo thứ tự giảm dần
void Swap_Luong_Giam_Dan(NhanVien nv[], int n) {
    printf("\n\t\t\t---Danh Sach Nhan Vien Luong Giam Dan--- ");
    printf("\nSTT\t\tmanv\t\t\thoten\t\t\t\t\tluong");
    for(int i=0; i<n-1; i++) {
        for(int j=i + 1; j <n; j++) {
            if (nv[i].luong < nv[j].luong) {
                NhanVien temp = nv[i];
                nv[i] = nv[j];
                nv[j] = temp;
            }
        }
    }
    for(int i=0; i<n; i++) {
        printf("\n%d", i + 1);
        In_Nhan_Vien(nv[i], i);
    }
    print_line(100);
}

// e. Tìm nhân viên có mã "001NV" . In kết quả lên màn hình.
void Tim_Nhan_Vien_Ma_001NV(NhanVien nv[], int n) {
    printf("\n\t\t\t---Nhan Vien Co Ma '001NV'---");
    printf("\nSTT\t\tmanv\t\t\thoten\t\t\t\t\tluong");
    char cantim[] = "001NV";
    for(int i=0; i<n; i++) {
        if (strcmp(cantim, nv[i].manv) == 0) {
            printf("\n%d", i + 1);
            In_Nhan_Vien(nv[i], i);
        }
    }
    print_line(100);
}




int main() {
    NhanVien nv[100];
    int n;
    printf("Nhap vao n nhan vien: n = ");
    scanf("%d", &n);


    Nhap_vao_n_nhan_vien(nv, n);
    In_Danh_Sach_Nhan_Vien(nv, n);
    Thong_Tin_Nhan_Vien_Luong_Cao_Nhat(nv, n);
    Swap_Luong_Giam_Dan(nv, n);
    Tim_Nhan_Vien_Ma_001NV(nv, n);


    return 0;
}




