
/*
    Nhap vao 3 so a, b, c. kiem tra xem co tao thanh tam giac ko?, neu co la tam giac gi

*/

#include<stdio.h>
#include<math.h>
#include<string.h>

void Check_Tam_Giac(int a, int b, int c) {
    if (a + b > 0 && a + c > b && b + c  > a) {
        if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a) {
            printf("\nTam giac vuong");
        } else if (a == b || a == c) {
            printf ("\nTam giac can");
        } else if (a == b == c) {
            printf ("\nTam giac deu");
        } else if (a*a + b*b < c*c || a*a + c*c < b*b || b*b +c*c < a *a) {
            printf("\nTam giac tu");
        }
    } else {
        printf("\nKhong phai 3 can cau tam giac");
    }
}

int main() {
    int a, b, c;
    do {
        printf("\nNhap vao a, b, c: ");
        scanf("%d%d%d", &a, &b, &c);
        if (a < 0 || b < 0 || c < 0) {
            printf("Loi, xin nhap lai");
        }
    } while(a <= 0 || b <= 0 || c <= 0);


    Check_Tam_Giac(a, b, c);


    return 0;
}