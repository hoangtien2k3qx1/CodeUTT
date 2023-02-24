
// giải và biện luận phương trình bậc 2 : a*x^2 + b*x + c

#include <stdio.h>
#include <math.h>

void giaiPT(float a, float b, float c)
{
    float delta;
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                printf ("phuong trinh vo so nghiem");
            }
            if (c != 0)
            {
                printf ("phuong trinh vo nghiem");
            }
        }
        if (b != 0)
        {
            printf ("x = %.2f", -c / b);
        }
    }
    else
    { // a != 0
        delta = b * b - 4 * a * c;
        if (delta > 0)
        {
            printf ("\nphuong trinh co 2 nghiem phan biet x1, x2 : ");
            printf ("\nx1 = %.2f", (-b + sqrt(delta)) / (2 * a));
            printf ("\nx2 = %.2f", (-b - sqrt(delta)) / (2 * a));
        }
        if (delta == 0)
        {
            printf ("x = x1 = x2 = %.2f", -b / (2 * a));
        }
        if (delta < 0)
        {
            printf ("Phuong trinh vo nghiem");
        }
    }
}

int main()
{
    float a, b, c;
    printf ("Nhap vao a = "); scanf("%f", &a);
    printf ("Nhap vao b = "); scanf ("%f", &b);
    printf ("Nhap vao c = "); scanf ("%f", &c);

    giaiPT(a, b, c);

    return 0;
}
