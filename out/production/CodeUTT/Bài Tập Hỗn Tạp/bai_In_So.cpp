
#include<stdio.h>
#include<math.h>
#include<conio.h>

void Fine_Element_Array () {
    for (int a = 0; a <= 9; a++) {
        for (int b = 0; b <=9; b++) {
            for (int c=0; c<=9; c++) {
                for (int d=0; d<=9; d++) {
                    if (a + b + c + d == 9) {
                        printf ("%d%d%d%d\t\t", a, b, c, d);
                    }
                }
            }
        }
    }
}

int main() {
    Fine_Element_Array();
    getch();
    return 0;
}