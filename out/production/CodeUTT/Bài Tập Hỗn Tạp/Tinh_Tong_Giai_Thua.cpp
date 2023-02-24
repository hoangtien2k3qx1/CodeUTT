
// Tính tổng a! + b! + c!

#include<stdio.h>
#include<math.h>

int Gia_Thua (int prameter) {
    if (prameter == 0 || prameter == 1) {
        return 1;
    }
    return prameter * Gia_Thua(prameter - 1);
}

int main() {
    int a, b, c;
    printf("Nhap vao a, b, c: ");
    scanf("%d%d%d", &a, &b, &c);
    printf("a! + b! + c! = %d", Gia_Thua(a) + Gia_Thua(b) + Gia_Thua(c));
    return 0;
}


