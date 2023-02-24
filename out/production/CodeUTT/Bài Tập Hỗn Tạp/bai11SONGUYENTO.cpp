

// kiểm tra số n nhập vào màn hình có phải là số nguyên tố hay không;

#include<stdio.h>
#include<math.h>
#include<conio.h>

int main() {
    int n, count = 0;
    do {    
        printf ("\nNhap vao n = ");
        scanf ("%d", &n);
    } while (n < 0 &&  printf ("Error:, nhap lai n:"));
    
    if (n < 2 ) {
        printf ("%d la so nguyen to", n);
        return 0;
    } else if (n == 2) {
        printf ("%d la so nguyen to", n);
        return 0;
    } else {
        for (int i=2; i<sqrt(n); i++) {
            if (n % i == 0) {
                count++;
            }
        }
        if (count > 0) {
            printf ("%d khong phai so nguyen to", n);
        } else {
            printf ("%d la so nguyen to", n);
        }
    }

    
    return 0;
}

    


