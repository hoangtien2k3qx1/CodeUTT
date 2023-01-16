
// cấu 1:
#include<stdio.h>
#include<math.h>

int main() {
    int n, sum = 0;
    do {
        printf ("\nNhap vao n = ");
        scanf ("%d", &n);
    } while (n < 100 || n > 1000 && printf ("Error, Nhap lai: "));

    for (int i=100; i<n; i++) {
        if (i % 2 != 0) {
            printf ("%d ", i);
            sum += i;
        }
    }

    printf  ("\nTong So Le: %d", sum);
    return 0;
}