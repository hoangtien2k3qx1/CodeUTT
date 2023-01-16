
#include<stdio.h>
#include<math.h>


int main() {
    int n, i, sum = 0;
    do {
        printf ("\nNhap vao n = ");
        scanf("%d", &n);
        if (n < 100 || n > 1000) {
            printf ("Loi, Nhap lai n: ");
        }
    } while (n < 100 || n > 1000);

    for (int i=100; i <= n; i++) {
        while (i > 0) {
            sum += (i % 10);
            i /= 10;           
        }
        if (sum > 9) {
            printf ("%d\t", sum);
        }
    }

    return 0;
}