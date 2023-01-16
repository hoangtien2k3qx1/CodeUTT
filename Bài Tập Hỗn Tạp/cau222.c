
// câu 2: 
#include<stdio.h>
#include<math.h>
#include<conio.h>

int main() {
    int n, count = 0;
    float sum = 0;
    do {
        printf ("\nNhap vao n = ");
        scanf ("%d", &n);
        if (n < 100) {
            printf ("Error, Nhap lai n: ");
        }
    } while (n < 100);


    for (int i=1; i<n; i++) {
        if ((i % 3 == 0) && (i % 6 == 0)) {
            printf ("%d ", i);
            count++;
            sum += i;
        }
    } 
    sum = (float)sum/count;
    printf ("\nTong TBC = %f", sum);
    return 0;
}