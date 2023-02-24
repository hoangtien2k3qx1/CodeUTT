
// b
#include<stdio.h>
#include<math.h>

int main() {
    float x, n;
    float S = 99;
    do {
        printf ("\nNhap vao x = ");
        scanf ("%f", &x);
    } while (x < 0 && printf ("Error, Nhap lai: "));

    do {
        printf ("\nNhap vao n = ");
        scanf ("%f", &n);
    } while (n < 0 && printf ("Error, Nhap lai: "));


    for (int i=1; i<n; i++) {
        S -= (float) i/x;
    }

    printf ("Tong S = %f", S);
    return 0;
}