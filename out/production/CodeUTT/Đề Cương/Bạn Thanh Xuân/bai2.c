
/*
    Viết chương trình nhập vào một dãy gồm k số nguyên dương
    a. Tính trung bình cộng các số dương và chia hết cho 5
    b. Tìm phần tử nhỏ nhất, in kêt quả ra màn hình

*/

#include<stdio.h>
#include<math.h>

// a. Tính trung bình cộng các số dương và chia hết cho 5
float TBC(int k, int arr[]) {
    float sum = 0, count = 0;
    for(int i=0; i<k; i++) {
        if (arr[i] > 0 && !(arr[i] % 5)) {
            sum += arr[i];
            count++;
        }
    }
    sum /= count;
    return sum;
}

// b. Tìm phần tử nhỏ nhất, in kêt quả ra màn hình
int Elements_Smallest_array(int k, int arr[]) {
    int min = arr[0];
    for(int i=0; i<k; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
} 


int main() {
    int k;
    printf("Nhap vao k = "); scanf("%d", &k);
    int arr[100];
    for(int i=0; i<k; i++) {
        printf("arr[%d] = ", i); scanf("%d", &arr[i]);
    }

    printf("\nTBC: %.3f", TBC(k, arr));
    printf("\nElements Smallest Array: %d", Elements_Smallest_array(k, arr));

    return 0;
}