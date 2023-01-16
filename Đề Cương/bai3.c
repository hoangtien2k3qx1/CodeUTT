
/*
    kieêm tra n có phai so nguyen to ko

*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>

void songuyento(int n) {
    int count = 0;
    if (n < 2) {
        printf("\nkhong phai la so nguyen to!");
    }
    for(int i=2; i<n; i++) {
        if (n % i == 0) {
            count++;
        }
    }
    if (count == 0) {
        printf("\nla so nguyen to!");
    } else{
        printf ("\nKhong phai la so nguyen to!");
    }
}


int main() {
    int n;
    printf ("Nhap vao n = "); scanf("%d", &n);

    songuyento(n);

    return 0;
}

