

#include<stdio.h>
#include<math.h>
#include<conio.h>

float Tinh_S (int x, int n) {
    float Sum = 0;
    for (int i=2; i<=n; i++) {
        float t = pow(x, 1.0/i);
        Sum += (float)t/i;
    }
    return Sum;
}

int main() {

    int x, n;
    do {
        printf ("\nNhap vao x = ");
        scanf ("%d", &x);
    } while (x < 0 && printf ("Loi, Nhap lai x: "));

    do {
        printf ("\nNhap vao n = ");
        scanf ("%d", &n);
    } while (n < 0 && printf ("Loi, Nhap lai n: "));

    float Tong = Tinh_S(x, n);
    printf ("Tong S = %f", Tong);
    
    return 0;
}





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

    printf ("Tong P = %3.4f", Tinh_P(x, n));

    return 0;
}