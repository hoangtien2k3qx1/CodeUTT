

// số đối xứng
#include<stdio.h>
#include<math.h>

int res, n;
int sodaonguoc(int n)
{
    int tmp;
    int res = 0;
    while (n > 0) // n != 0 
    {
        tmp = n % 10;
        res = res * 10 + tmp;
        n = n / 10;
    }
    return res;
}

int main() {
    printf ("Nhap vao n = ");
    scanf("%d", &n);
    int x = sodaonguoc(n);
    if (x == n) {
        printf ("La so doi xung");
    } else {
        printf ("Khong phai la so doi xung");
    }
    return 0;
}