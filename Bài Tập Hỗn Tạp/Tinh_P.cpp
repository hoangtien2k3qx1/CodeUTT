
// Tính P = 100 + 1/10 - 1/20 + 1/30 - ... + 1/(10*n)

#include<stdio.h>
#include<math.h>

int main() {
    int n;
    float P1 = 0, P2 = 0, sum = 100;
    do {
        printf ("\nNhap vao n = ");
        scanf ("%d", &n);
    } while(n < 0 && printf ("Error, Nhap lai n: "));
    float P = 0;
    for (int i=1; i<=n; i++) {
        if (i % 2 == 0) {
            P1 -= (float) 1/(i * 10);
        } else {
            P2 += (float) 1/(i * 10);
        }
    }
    sum = sum + P1 + P2;
    
    printf ("Tong P = %f", sum);
    return 0;
}