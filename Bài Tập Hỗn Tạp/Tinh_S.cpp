

// Tính S= 1^2 + 2^2 + ... + n^2;

#include<stdio.h>
#include<math.h>

int main() {
    int n, S = 0;
    do {
        printf ("\nNhap vao n = ");
        scanf ("%d", &n);
    } while(n < 0 && printf ("Error, Nhap lai n: "));

    for (int i=1; i<=n; i++) {
        S += pow(i, 2);
    }
    printf ("Tong S = %d", S);
    return 0;
}

