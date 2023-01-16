
// câu 3: b - HOÀNG ANH TIẾN - 72DCHT21

#include<stdio.h>
#include<math.h>
#include<conio.h>

#define e 2.7182818

float Tinh_P (float x, float n) {
    float sum1 = 0, sum2 = 0, Sum = 199;
    for (int i=1; i<=n; i+=2) {
        sum1 -= ( pow(e, i*x));
        
    }
    for (int i=2; i<=n; i+=2) {
        sum2 += (pow(e, i*x));
    }
    Sum = Sum + sum1 + sum2;
    return Sum;
}


int main() {

    float x, n;
    do {
        printf ("\nNhap vao x = ");
        scanf ("%f", &x);
    } while (x < 0 && printf ("Loi, Nhap lai x: "));

    do {
        printf ("\nNhap vao n = ");
        scanf ("%f", &n);
    } while (n < 0 && printf ("Loi, Nhap lai n: "));

    printf ("Tong P = %f", Tinh_P(x, n));

    return 0;
}