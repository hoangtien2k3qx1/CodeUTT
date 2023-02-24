
// đảo ngược số nguyên n nhập từ bàn phím

// 12345 -> 54321
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<string.h>

int daoNguocSo(int n) {
    int res = 0, t;
    while(n != 0) {
        t = n % 10;
        res = res * 10 + t;
        n /= 10;
    }
    return res;
}

int main() {
    int n;
    printf ("Nhap vao n  = ");
    scanf ("%d", &n);
    printf ("%d", daoNguocSo(n));
    return 0;
}