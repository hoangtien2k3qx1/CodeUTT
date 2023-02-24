
/*
    x * 1000 + y * 2000 + z * 5000 = 200.000
    20 * 10000 = 200000 => x thuộc [0, 200]
    10 * 20000 = 200000 => y thuộc [0, 100]
    4 * 50000 = 200000 => z thuộc [0, 40]

*/
#include<stdio.h>
#include<conio.h>

int main() {
    int count = 0;
    for (int i=0; i<=20; i++) {
        for (int j=0; j<=10; j++) {
            for (int k=0; k<=4; k++) {
                if (i*10000 + j*20000 + k*50000 == 200000) {
                    printf ("\n%d to 1000(VND), %d to 2000(VND), %d to 5000(VND)",i, j, k);
                    count++;
                }
            }
        }
    }
    printf ("\n");
    printf("Tong can co %d phuong an.", count);

    getch();
    return 0;
}