
// số chính phương

#include<stdio.h>
#include<math.h>

int main() {
    int n;
    do {
        printf ("\nNhap vao n = ");
        scanf ("%d", &n);
    } while(n < 0 && printf ("Error, Nhap lai n: "));

    int s = sqrt((int)n);
    if (s*s == n) {
        printf ("%d la so chinh phuong!", n);
    } else {
        printf ("%d khong phai la so chinh phuong!", n);
    }
    return 0;
}