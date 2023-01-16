
// câu 3: a
#include<stdio.h>
#include<conio.h>
#include<math.h>

int main() {
    float x, n, S = 0;
    do {
        printf ("\nNhap vao x = ");
        scanf ("%f", &x);
    } while (x < 0 && printf ("Error, Nhap lai: "));

    do {
        printf ("\nNhap vao n = ");
        scanf ("%f", &n);
    } while (n < 0 && printf ("Error, Nhap lai: "));

    for (int i=2; i<= n ; i++) {
        S += pow(x, (float) 1/i);
    }

    printf ("Tong S = %f", S);
    return 0;
}