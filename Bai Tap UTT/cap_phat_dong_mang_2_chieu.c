
// cấp phát động mảng 2 chiều trong C

#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>

void Nhap_Ma_Tran_2_Chieu(int **arr, int m, int n) {
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void Xuat_Mang_2_Chieu(int **arr, int m, int n) {
    printf("\nCac Phan Tu Mang 2 Chieu: \n");
    for(int i=0; i<m; i++) {
        for(int j=0; j <n; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {    
    int m, n;
    printf("Nhap vao m = "); scanf("%d", &m);
    printf("Nhap vao n = "); scanf("%d", &n);

    int **arr = (int**) malloc(sizeof(int*) * m); // cấp phát động mảng con trỏ cấp 1
    for(int i=0; i<m; i++) {
        arr[i] = (int*) malloc(sizeof(int) * n);
    }

    Nhap_Ma_Tran_2_Chieu(arr, m, n);
    Xuat_Mang_2_Chieu(arr, m, n);

    for(int i=0; i<m; i++) {
        free(arr[i]);
    }
    free(arr);


    return 0;
}