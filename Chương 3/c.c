
// Tính Q = 100 + e^x + (e^x)/2 + (e^x)/3 + ... + (e^x)/n

#include<stdio.h>
#include<math.h>
#include<conio.h>

#define e 2.7182818

int main() {
    int x, n;
    float Q = 0, T = 0;
    printf ("Nhap vao x = "); scanf ("%d", &x);
    printf ("Nhap vao n = "); scanf ("%d", &n);

    // C1:
    T = pow(e, x);
    for (int i=1; i<=n; i++) {
        Q += T/i;
    }

    // C2:
    // for (int i=1; i<=n; i++) {
    //     Q += (pow(e, x))/i;
    // }

    Q += 100;
    printf ("Q = %f", Q);
    return 0;
}