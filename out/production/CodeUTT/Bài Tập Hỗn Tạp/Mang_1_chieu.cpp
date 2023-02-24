
#include<stdio.h>
#include<math.h>

int n, arr[100], k, count = 0;

void Input_N (){
    do {
        printf ("Nhap vao n = ");
        scanf ("%d", &n);
    } while (n >= 100 && printf ("Error, Nhap lai n: "));
    printf ("\nNhap vao k = ");
    scanf ("%d", &k);
}

void Input_and_Output_Array () {
    for (int i=0; i<n; i++) {
        printf ("arr[%d] = ", i);
        scanf ("%d", &arr[i]);
    }
    printf ("\nElement array: ");
    for (int i=0; i<n; i++) {
        printf ("%d ", arr[i]);
    }
}

void Check_K () {
    for (int i=0; i<n; i++) {
        if (k == i) {
            printf ("\n%d xuat hien thu %d trong mang: ", k, i-1);
        }
    }
}

void swap_array () {
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf ("\nArray swap: ");
    for (int i=0; i<n; i++) {
        printf ("%d ", arr[i]);
    }
}

int main() {
    Input_N ();
    Input_and_Output_Array();
    Check_K();
    swap_array();
    return 0;
}