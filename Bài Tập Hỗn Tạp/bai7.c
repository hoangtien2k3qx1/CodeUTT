
// in ra ma trận bằng ký tự *

#include<stdio.h>
#include<conio.h>

void LoopFor_InC (int m, int n, int a[][10]) {
    for (int i=0; i<m ;i++){
        for (int j=0; j<n; j++) {
            printf (" * ");
        }
        printf ("\n");
    }
}

int main() {
    int m, n, a[10][10];
    printf ("Input m = ");
    scanf ("%d", &m);
    printf ("Input n = ");
    scanf ("%d", &n);
    LoopFor_InC(m, n, a);

    getch();
    return 0;
}