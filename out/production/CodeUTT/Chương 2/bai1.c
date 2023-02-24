
/*
    Viết chương trình nhập vào 3 hộ dân gồm có: chủ hộ, số đầu, số cuối yêu cầu

        a. tính thành tiền của các hộ dân. biết nếu Số điện tt = số cuối - số đầu
        thành tiền = số điện tt * đơn giá ( nếu số điện tt < 100. đơn giá  = 1500/1kw ,
        100 <= số điện tt < 200, thì đơn giá = 2000, số điện tt >= 200, thì đơn giá = 3000 )

        b. Đưa ra thông tin chủ hộ tiêu thụ điện nhiều nhất

*/

#include<stdio.h>
#include<string.h>
#include<conio.h>

struct hodan {
    char ten_chu_ho[20];
    int so_dau;
    int so_cuoi;
    int thanh_tien;
    int so_dien_tt;
} p1[3];

int main() {
    printf ("NHAP VAO THONG TIN 3 HO_DAN: ");
    for (int i=0; i<3; i++) {
        printf ("\nNhap vao ten_chu_ho %d: ", i+1); scanf ("%s", p1[i].ten_chu_ho);
        printf ("Nhap vao so_dau: "); scanf ("%d", &p1[i].so_dau);
        printf ("Nhap vao so_cuoi: "); scanf ("%d", &p1[i].so_cuoi);
    }
    for (int i=0; i<3; i++) {
        p1[i].so_dien_tt = p1[i].so_cuoi - p1[i].so_dau;
        if ( p1[i].so_dien_tt < 100) {
            p1[i].thanh_tien = p1[i].so_dien_tt * 1500;
        } else if (p1[i].so_dien_tt >= 100 && p1[i].so_dien_tt < 200) {
            p1[i].thanh_tien = p1[i].so_dien_tt * 2000;
        } else {
            p1[i].thanh_tien = p1[i].so_dien_tt * 3000;
        }
    }
    for (int i=0; i<3; i++) {
        printf ("\nThanh_tien cua ho dan %d: ", i + 1);
        printf ("%d ", p1[i].thanh_tien );
    }
    printf ("\nTHONG TIN CHU HO TIEU_THU_DIEN NHIEU NHAT: ");
    int Max = (p1[0].thanh_tien > p1[1].thanh_tien) ? p1[0].thanh_tien : p1[1].thanh_tien;
    Max = (Max > p1[2].thanh_tien) ? Max : p1[2].thanh_tien;
    printf ("%d", Max);


    getch();
    return 0;
}

