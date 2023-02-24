
// giải và biện luận pt: a*x + b = 0

#include<stdio.h>
#include<math.h>

int main() {
    float a,b;
    printf("nhap vao a = ");
    scanf("%d", &a);
    printf("\nnhap vao b = ");
    scanf("%d", &b);
    if (a == 0) {
        if (b == 0) {
            printf("phuong trinh vo so nghiem");
        }
        if (b != 0) {
            printf("phuong trinh vo nghiem");
        }
    }
    if (a != 0) {
        printf("\nx = %f", (float)-b / a);
    }
    return 0;
}