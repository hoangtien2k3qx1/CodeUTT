
// nhập vào số n. kiểm tra xem n có phải số nguyên tố hay không

#include <stdio.h>
#include<math.h>
#include<stdbool.h>

bool songuyento(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= (int)sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n, count = 0;
    do
    {
        printf("Nhap vao n (n > 0) = ");
        scanf("%d", &n);
    } while (n < 0 && printf("\nXin nhap lai!: "));
    
    if (songuyento(n)) {
        printf("\n%d la so nguyen to!", n);
    } else {
        printf("%d khong phai la so nguyen to!", n);
    }

    return 0;
}


