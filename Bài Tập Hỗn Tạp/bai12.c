
// in ra các số từ lẻ 1 -> n

#include<stdio.h>

int main() {
    int n, count = 0;

    do {
        printf ("\nNhap vao n = ");
        scanf ("%d", &n);
    } while (n < 0 && printf ("Error, Nhap lai:"));

    for (int i = 1; i<=n; i++) {
        if (i & 1) { //! i % 2 == 1 // dùng bitwise AND kiểm tra số lẻ
            printf ("%d\t", i);
        }
    }

    return 0;
}