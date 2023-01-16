
/*
    Viết chương trình nhập vao dãy gồm k số nguyên
    a. Tính trung bình cộng các số không âm
    b. đếm các số lẻ

*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

// a. Tính trung bình cộng các số không âm
float TBC_undigits(int k, int arr[]) {
    float sum = 0, count = 0;
    for(int i=0; i<k; i++) {
        if (arr[i] > 0) {
            sum += arr[i];
            count++;
        }
    }
    return sum /= count;
}


// b. đếm các số lẻ
int Count_odd(int k, int arr[]) {
    int count = 0;
    for(int i=0; i<k; i++) {
        if (arr[i] & 1) {
            count++;
        }
    }
    return count;
}

int main() {
    int k, arr[100];
    printf("Nhap vao k = "); scanf("%d", &k);
    for(int i=0; i<k; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nTBC: %.3f", TBC_undigits(k, arr));

    printf("\nCount odd: %d", Count_odd(k, arr));
    

    return 0;
}