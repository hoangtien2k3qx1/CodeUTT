
/*
    giai bất phương trình
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<conio.h>

void giaiBPT(float a, float b, float c, float d, float e, float f) {
    float D, Dx, Dy;
    D = a*e - b*d;
    Dx = c*e - b*f;
    Dy = a * f - c * d;
    if (D == 0) {
        if(Dx + Dy == 0) {
            printf ("Phuong trinh co vo so nghiem!!!");
        } else {
            printf ("\nPhuong trinh vo nghiem!");
        }
    } else {
        printf ("\nPhuong trinh co 2 nghiem: ");
        printf ("\nx1 = %.3f", Dx / D);
        printf ("\nx2 = %.3f", Dy / D);
    }
}


int main() {
    float a, b, c, d, e, f;
    printf ("Nhap vao a, b, c, d, e, f: ");
    scanf("%f%f%f%f%f%f", &a, &b, &c, &d, &e, &f);

    giaiBPT(a, b, c, d, e ,f);


    return 0;
}