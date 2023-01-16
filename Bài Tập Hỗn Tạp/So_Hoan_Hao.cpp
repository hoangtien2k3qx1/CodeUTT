

// số hoàn hảo

#include<stdio.h>
#include<math.h>
#include<stdbool.h>

int n, sum = 0;

int SoHoanHao () {
    for (int i=1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}

bool Check_N () {
    SoHoanHao();
    if (sum == n) {
        printf ("%d la so hoan hao!", n);
    } else {
        printf ("%d khong phai la so hoan hao!", n);
    }
}

int main() {
    do {
        printf ("\nNhap vao n = ");
        scanf ("%d", &n);
    } while ((n < 0 || n > 5000) && printf ("Error, Nhap lai n:"));
    Check_N();
    return 0;
}