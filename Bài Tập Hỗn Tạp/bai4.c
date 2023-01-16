
#include<stdio.h>
#include<math.h>

int main() {
    float a, b, c, p;
    float chu_vi, dien_tich;
    scanf ("%f%f%f", &a, &b, &c);
    if (a < b + c && b < a + c && c < a + b) {
        if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a) {
            printf ("Day la tam gia vuong");
        } else if (a == b && b == c) {
            printf ("Day la tam giac deu");
        } else if (a == b || a == c || b == c) {
            printf ("Day la tam giac can");
        } else if (a*a > b*b + c*c || b*b > a*a + c*c || c*c > a*a + b*b) {
            printf ("Day la tam giac tu");
        } else {
            printf ("Day la tam giac nhon");
        }
    } else {
        printf ("Day khong phai 3 canh cua tam gia");
    }
    chu_vi = (a + b + c);
    p = chu_vi / 2;
    printf ("\nChu_vi : %.2f", chu_vi);
    dien_tich = sqrt(p*(p-a)*(p-b)*(p-c));
    printf ("\nDien tich : %.2f", dien_tich);


    return 0;
}

