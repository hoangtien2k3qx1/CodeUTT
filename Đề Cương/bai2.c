/*
    B2. Giai va bien luan PT bac 2 co dang a*x2 + b*x + c = 0
*/

#include<stdio.h>
#include<math.h>
#include<string.h>

void giaiPT_2(float a, float b, float c) {
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                printf ("\nPhuong trinh vo so nghiem");
            } else {
                printf ("\nPhuong trinh vo nghiem");
            }
        } else {
            printf("\nPhuong trinh co  nghiem duy nhat: x = %.3f", -c / b );
        }
    } else { // a != 0
        float delta = b*b - 4*a*c;
        if (delta > 0) {
            printf ("\nPhuong trinh co 2 nghiem phan biet: ");
            printf ("\nx1 = %.3f", (-b + sqrt(delta)) / (2*a) );
            printf ("\nx2 = %.3f", (-b - sqrt(delta)) / (2*a) );
        } else if (delta == 0) {
            printf ("\nPhuong trinh co nghiem kep: x1 = x2 = %.3f", -b / (2*a));
        } else {
            printf ("\nPhuong trinh vo nghiem!");
        }
    }
}


int main() {
    float a, b, c;
    printf ("Nhap vao a, b, c: ");
    scanf("%f%f%f", &a, &b, &c);

    giaiPT_2(a, b, c);


    return 0;
}