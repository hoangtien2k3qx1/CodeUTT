
// Tính tổng T = x^1 + x^2 + x^3 + ... + x^n

#include<stdio.h>
#include<conio.h>
#include<math.h>

int main(){
    int n, x, T = 0, P = 1;
    printf("Nhap vao x = ");
    scanf ("%d", &x);
    printf ("Nhap vao n = ");
    scanf ("%d", &n);

    // cách 1:
    for(int i=1; i<=n; i++) {
        P *= x;
        T += P;
    }

    // cách 2:
    // for (int i=1; i<=n; i++) {
    //     T += pow(x, i);
    // }

    printf ("T = %d", T);
    getch();
    return 0;
}