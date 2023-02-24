
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>

#include<stdio.h>
#include<math.h>

bool nt(int a) {
    for (int i=2; i<=sqrt(a); i++) {
        if (a % i == 0) {
           return false;
        }
    }
    return a > 1;
}

float TBC(int n, int arr[]) {
    float count = 0;
    float sum = 0;
    for(int i=0; i<n; i++) {
        if (arr[i] < 0 && arr[i] % 3 == 0) {
            sum += arr[i];
            count++;
        }
    }
    float TBC = (float)sum / count;
    return TBC;
}

void sapxep(int n, int arr[]) {
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


int main() {
    int n;
    int arr[100];
    printf("Nhap vao n = ");
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        printf("arr[%d] = ", i );
        scanf("%d", &arr[i]);
    }

    printf("\nCac so nguyen to: ");
    for (int i=0; i<n; i++)  {
        if (nt(arr[i])) {
            printf("%d\t", arr[i]);
        }
    }

    printf("\nTBC: %f", TBC(n, arr));

    sapxep(n, arr);
    printf("\nMang sap xep: ");
    for(int i=0; i<n; i++) {
        printf("%d\t", arr[i]);
    }

    return 0;
}
