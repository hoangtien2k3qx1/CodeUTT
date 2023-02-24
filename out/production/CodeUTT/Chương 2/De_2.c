

#include<stdio.h>
#include<math.h>
#include<conio.h>


int main() {
    int n, sum = 0;
    do {
        printf ("\nNhap vao n(n>100) = ");
        scanf ("%d", &n);
        if (n > 100) {
            printf ("Loi, Nhap lai n: ");
        }
    } while ( n > 100);

    for (int i=0; i<=n; i++) {
        if (i % 3 == 0 || i % 9 == 0) {
            printf ("%d ", i);
            sum += i;
        }
    }
    printf ("\nTong cac so chia het cho 3 tan cung la 9: %d", sum);

    return 0;
}