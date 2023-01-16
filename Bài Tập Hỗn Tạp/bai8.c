// Tính giai thừa của n! = ?
#include<stdio.h>

// int giaiThua(int n)
// {
//     int T = 1;
//     if (n == 0 || n == 1) {
//         return 1;
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         T = T * i;
//     }
//     return T;
// }

int giaiThua(int n) {
    if (n==0 || n==1) {
        return 1;
    }
    return n * giaiThua(n-1);
}

int main() {
    int n;
    printf ("Nhap vao n = ");
    scanf ("%d", &n);
    printf ("%d! = %d",n, giaiThua(n));
    return 0;
}