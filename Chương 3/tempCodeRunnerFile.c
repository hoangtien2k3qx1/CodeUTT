
#include<stdio.h>
#include<conio.h>
#include<math.h>

// int main() {
//     int n, i=1;
//     scanf ("%d", &n);

//     table: 
//     printf ("%d x %d = %d\n",n, i, n * i );
//     i++;
//     if(i <=10) 
//     goto table;

//     // do {
//     //     printf ("%d x %d = %d\n", n, i, n * i);
//     //     i++;
//     // } while (i <= 10);

// }

int main() {
    int a;
    scanf ("%d", &a);
    for (int i=0; i<=3; i++) { 
        if (i==2) {
            continue; 
        }
        a += 1; // 6 // 7
        if (i > 1) {
            break;
        }
        printf ("\na = %d", a);
    }
}