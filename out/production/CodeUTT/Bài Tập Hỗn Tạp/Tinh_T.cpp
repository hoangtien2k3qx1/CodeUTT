

// Tính T
#include<stdio.h>
#include<math.h>

int main() {
    int n;
    float T = 0;
    do {
        printf ("\nNhap vao n = ");
        scanf ("%d", &n);
    } while(n < 0 && printf ("Error, Nhap lai n: "));
    for (int i=1; i<=n; i++) {
        T += (float) 1/i;
    }
    printf ("Tong T = %f", T);
    return 0;
}