

#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>

// Tinh bieu thuc: S = 100 - 10^(1*x) + 10^(2*x) - ... + 10^(n*x)
int Sum_Array_In_C (int x, int n) {
    int S, sum1 = 0, sum2 = 0;
    for (int i=1; i<=n; i++) {
        if(i % 2 != 0) {
            sum1 -= pow(10, i*x);
        } else {
            sum2 += pow(10, i*x);
        }
    }
    S = 100 - (sum1 + sum2);
    return S;// 100
}


// tính tổng CANBAC2(2) + CANBAC2(3) + ... + CANBAC2(n);
int Tinh_Sum (int n) {
    int sum = 0;
    for (int i=2; i<=n; i++) {
        sum += sqrt(i);
    }
    return sum;
}

int main() {
    int x, n;
    printf ("Nhap vao x: ");
    scanf ("%d", &x);
    printf ("Nhap vao n = ");
    scanf("%d", &n);

    printf ("%d", Sum_Array_In_C(x, n));
    printf ("\n\n%d", Tinh_Sum(n));

    return 0;
}