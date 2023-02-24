
/*
    Viết chương trình nhập vào một dãy gồm n số nguyên
    a. Tìm phần tử nhỏ nhất trong dãy
    b. Sắp xếp mảng tăng dần

*/

#include<stdio.h>
#include<math.h>

// a. Tìm phần tử nhỏ nhất trong dãy
int Elements_Smallest_array(int n, int arr[]) {
    int min = arr[0];
    for(int i=0; i<n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
} 

// b. Sắp xếp mảng tăng dần
void Swap_Array_Ascending(int n, int arr[]) {
    for(int i=0; i<n-1; i++) {
        for(int j=n-1; j>i; j--) {
            if (arr[j-1] > arr[j]) {
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        } 
    }
}

int main() {
    int n;
    printf("Nhap vao n = "); scanf("%d", &n);
    int arr[100];
    for(int i=0; i<n; i++) {
        printf("arr[%d] = ", i); scanf("%d", &arr[i]);
    }

    printf("\nElements Smallest Array: %d", Elements_Smallest_array(n, arr));

    Swap_Array_Ascending(n, arr);
    printf("\nSwap_Array_Ascending: ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}