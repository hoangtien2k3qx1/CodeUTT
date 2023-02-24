
// Nhập vào 3 số nguyên a, b, c . Kiểm tra xem có tạo thành tam giác không ? và là tam giác gì

#include<stdio.h>
#include<math.h>

void Check_Tam_Giac(int a, int b, int c) {
    if( a<b+c && b<a+c && c<a+b ){
        if( a*a==b*b+c*c || b*b==a*a+c*c || c*c== a*a+b*b)
            printf("Day la tam giac vuong");
        else if(a==b && b==c)
            printf("Day la tam giac deu");
        else if(a==b || a==c || b==c)
            printf("Day la tam giac can");
        else if(a*a > b*b+c*c || b*b > a*a+c*c || c*c > a*a+b*b)    
            printf("Day la tam giac tu");
        else
            printf("Day la tam giac nhon");
    }
    else
        printf("Ba canh a, b, c khong phai la ba canh cua mot tam giac");
}

int main() {
    int a, b, c;
    do {
        printf("\nNhap vao canh a = "); scanf("%d", &a);
        printf("Nhap vao canh b = "); scanf("%d", &b);
        printf("Nhap vao canh c = "); scanf("%d", &c);
    } while(a < 0 || b < 0 || c < 0 && printf("Nhap sai, nhap lai: "));

    Check_Tam_Giac(a, b, c);

    return 0;
}

