
// dùng switch_case
////////
#include<stdio.h>
#include<conio.h>

void NhapVao(float a, float b, char x) {
    switch(x) {
        case '+':
            printf ("Tong %.4f + %.4f = %.4f", a, b, a + b);
            break;
        case '-':
            printf ("Hieu %.4f - %.4f = %f", a, b, a - b);
            break;
        case '*':
            printf ("Tich %.4f * %.4f = %.4f", a, b, a * b);
            break;
        case '/':
            printf ("Thuong %.4f / %.4f = %.4f", a, b, a / b);
            break;
        default:
            printf ("Error:");
            break;
    }
}

int main() {
    float a, b;
    printf ("Nhap vao a = "); scanf ("%f", &a);
    char x;
    fflush(stdin); // xóa bộ nhớ đệm ( nếu không có thì nó sẽ trôi câu lệnh )
    printf ("Nhap vao (+, -, *, /): ");
    x = getchar();
    printf ("Nhap vao b = ");
    scanf ("%f", &b);
    NhapVao(a, b, x);
    return  0;
}