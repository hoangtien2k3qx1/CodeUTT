
// Timf các số có 3 chữ số sao cho tổng các chữ số bằng 9

#include<stdio.h>
#include<math.h>

int Tinh_Tong(int a) {
    int sum = 0;
    while(a != 0) {
        sum = sum + (a % 10);
        a /= 10;
    }
    return sum;
}

int main() {
    for(int i=100; i<=999; i++) {
        if (Tinh_Tong(i) == 9) {
            printf("%d\t", i);
        }
    }
    return 0;
}