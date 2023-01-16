#include<stdio.h>
#include<math.h>
#include<conio.h>

int Check (int arr[]) {
    int sum1 = 0;
    for (int i=0; i<4; i++) {
        if (arr[i] % 2 == 0) {
            sum1 += arr[i];
        } 
    }
    return sum1;
}

int Sole (int arr[]) {
    int sum2 = 0;
    for (int i=0; i<4; i++) {
        if (arr[i] % 2 != 0) {
            sum2 += arr[i]; 
        }
    }
    return sum2;
}   

int main() {
    int arr[4];
    printf("Input arr: ");
    for (int i=0; i<4; i++) {
        printf ("\narr[%d] = ", i);
        scanf ("%d", &arr[i]);
    }
    printf ("\nTong so chan %d", Check(arr));
    printf ("\nTong so le %d", Sole(arr));
    printf ("\n\n\n");
    return 0;
}