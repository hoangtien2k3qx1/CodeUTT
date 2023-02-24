
// giải và biện luận phương trình bậc 4 có dạng: a*x^4 + b*x^2 + c = 0

#include<stdio.h>
#include<math.h>

void GiaiPhuongTrinhBac_1(float a, float b)
{
    if (a == 0)
    {
        if (b == 0)
            printf("Phuong Trinh VSN");
        else
            printf("Phuong Trinh VN");
    }
    else
    {
        printf("Phuong Trinh co nghiem duy nhat x = %.2f", (float)-b / a);
    }
}

void GiaiPhuongTrinhBac_2(float a, float b, float c, int &TypeResult, float &x1, float &x2, float &x)
{
    if (a == 0)
    {
        TypeResult = -1;

        GiaiPhuongTrinhBac_1(b, c);
    }
    else
    {
        float delta = b * b - 4 * a * c;

        if (delta < 0)
        {
            TypeResult = 0;
        }
        else
        if (delta == 0)
        {
            TypeResult = 1;
            x = -b / 2 * a;
        }
        else
        {
            TypeResult = 2;
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);

        }
    }
}

void GiaiPhuongTrinhBac_4(float a, float b, float c)
{
    int TypeResult = 0;
    float x1 = 0, x2 = 0, x = 0, x3 = 0, x4 = 0;

    int flag = 0;

    if (a == 0) //  bX^2 + c = 0
    {
        GiaiPhuongTrinhBac_2(b, 0, c, TypeResult, x1, x2, x);
        flag = 1;
    }
    else
    {
        GiaiPhuongTrinhBac_2(a, b, c, TypeResult, x1, x2, x);
        flag = 0;
    }

    if (TypeResult == 0) 
    {
        printf("Phuong trinh VN");
    }

    if (TypeResult == 1) 
    {
        if (flag == 0) 
        {
            if (x > 0)
            {
                x1 = sqrt(x);
                x2 = -sqrt(x);

                printf("Phuong trinh Co nghiem \n");
                printf("x1 = %.2f", x1 );
                printf("x2 = %.2f", x2 );
            }
            else
            {
                printf("Phuong trinh Co nghiem kep x1 = x2 = %.2f", x);
            }
        }
        else
        {
            printf("Phuong trinh Co nghiem kep x1 = x2 = %f", x);
        }
    }

    if (TypeResult == 2) 
    {
        if (flag == 0) 
        {
            if (x1 >= 0)
            {
                printf("x1 = %.2f", sqrt(x1));
                printf("x2 = %.2f", -sqrt(x1));
            }

            if (x2 >= 0)
            {
                printf("x3 = %.2f", sqrt(x2));
                printf("x4 = %.2f", -sqrt(x2));
            }

            if (x1 < 0 && x2 < 0)
                printf("Phuong Trinh VN");

        }
        else
        {
            printf("Phuong trinh co 2 nghiem phan biet :\n");
            printf( "x1 = %.2f", x1);
            printf( "x2 = %.2f", x2);
        }
    }
}

int main()
{
    float a, b, c;
    printf ("Nhap vao a = "); scanf("%f", &a);
    printf ("Nhap vao b = "); scanf ("%f", &b);
    printf ("Nhap vao c = "); scanf ("%f", &c);

    GiaiPhuongTrinhBac_4(a, b, c);
    
    return 0;
}