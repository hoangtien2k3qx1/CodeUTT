
#include<stdio.h>
#include<math.h>


int Max_Min (int a, int b, int c, int d) {
    int Max = (a > b) ? a : b;
    Max = (Max > c) ? Max : c;
    Max = (Max > d) ? Max : d;
    return Max;
}

int MinInC(int a, int b, int c, int d) {
    int Min = (a < b) ? a : b;
    Min = (Min < c) ? Min : c;
    Min = (Min < d) ? Min : d;
    return Min;
}

int main() {
    int a, b, c, d;
    int Max = 0, Min = 0;
    printf ("Input a, b, c, d: ");
    scanf ("%d%d%d%d", &a, &b, &c, &d);

    printf ("%d", Max_Min(a, b, c, d));

    printf ("\n%d", MinInC(a, b, c, d));
    
    return 0;
}




