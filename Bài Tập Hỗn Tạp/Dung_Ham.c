
// dùng hàm thực hiện các công việc sau

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void Nhap_a_b(int &a, int &b) {
    do {
        printf("\nNhap vao a, b: ");
        scanf("%d%d", &a, &b);
    } while (a < 0 || b < 0 && printf("Loi, Nhap lai a, b: "));
}

int Sum(int a, int b) {
    return a + b;
}

int UCLN(int a, int b) {
    if (a == 0) {
        return b;
    }
    return (UCLN(b % a, a));
}

void Hoan_Vi(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int Sum_Gia_Thua(int pragmeter) {
    if (pragmeter == 0 || pragmeter == 1) {
        return 1;
    }
    return pragmeter * Sum_Gia_Thua(pragmeter - 1);
}

int main() {
    int a, b;
    Nhap_a_b(a, b);
    printf("\nTong %d + %d =  %d", a, b, Sum(a, b));
    printf("\nUCLN(%d, %d) = %d", a, b, UCLN(a, b));
    Hoan_Vi(&a, &b);
    printf("\nHoan vi: a = %d, b = %d", a, b);
    printf("\nGiai Thua a! + b! = %d", Sum_Gia_Thua(a) + Sum_Gia_Thua(b))
    return 0;
}