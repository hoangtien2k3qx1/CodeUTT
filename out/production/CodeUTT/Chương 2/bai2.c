
/*
    Viết chương trình nhập vào 4 số a, b, c, d. In ra GTLL và GTNN

*/
#include<stdio.h>
#include<math.h>

int main() {
    int a, b, c, d;
    scanf ("%d%d%d%d", &a, &b, &c, &d);

    int max = (a>b)?a:b;
    max = (max>c)?max:c;
    max = (max>d)?max:d;

    int min = (a<b)?a:b;
    min = (min<c)?min:c;
    min = (min<d)?min:d;

    printf ("GTLL: %d", max);
    printf ("\nGTNN: %d", min);

    return 0;
}