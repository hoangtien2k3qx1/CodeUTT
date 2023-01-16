
#include<stdio.h>
#include<math.h>

int Tong_Le(int n, int arr[]) {
    int sum  = 0;
    for(int i=0; i<n; i++) {
        if (arr[i] < 0 && arr[i] % 2 == -1) {
            sum += arr[i];
        }
    }
    return sum;
}

int main() {
    int arr[100];
    int n;
    printf("nhap n = "); scanf("%d", &n);
    for(int i=0; i<n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("Sum = %d", Tong_Le(n, arr));

    return 0;
}