
/*
    Nhập vào mảng 2 chiều: 
        a. in mảng
        b. Tính tổng các số lẻ là số âm
        c. Đếm phần tử có tận cùng bằng 3
        d. Tính tổng các phần tử nằm phía trên đường chéo chính ( tam giác trên )
        e. Tính tổng các phần tử trên cột k ( với k nhập từ bàn phím )
        f. sắp xếp mảng giảm đần.

*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>


void Nhap_Ma_Tran(int m, int n, int **arr) {
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}


// a. in mảng
void In_Mang(int m, int n, int **arr) {
    printf("\nMang Vua Nhap: \n");
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
} 

//  b. Tính tổng các số lẻ là số âm
int Tong_So_Le_Am(int m, int n, int **arr) {
    int sum = 0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if (arr[i][j] % 2 == -1) {
                sum += arr[i][j];
            }
        }
    }
    return sum;
}

//  c. Đếm phần tử có tận cùng bằng 3
int Dem_Phan_Tu_Le(int m, int n, int **arr) {
    int count = 0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if ((arr[i][j] % 2 == 1 || arr[i][j] % 2 == -1) && (arr[i][j] % 10 == 3 || arr[i][j] % 10 == -3)) {
                count++;
            }
        }
    }
    return count;
}


// d. Tính tổng các phần tử nằm phía trên đường chéo chính ( tam giác trên )
int Tong_Phan_Tu_Tren_Duong_Cheo_Chinh(int m, int n, int **arr) {
    int sum = 0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if (i < j) {
                sum += arr[i][j];
            }
        }
    }
    return sum;
}


// e. Tính tổng các phần tử trên cột k ( với k nhập từ bàn phím )
int Tong_Phan_Tu_Tren_Cot_K(int m, int n, int **arr) {
    int k, sum = 0;
    printf("\nNhap vao cot k: "); scanf("%d", &k);
    for(int i=0; i<m; i++) {
        sum += arr[i][k-1];
    }
    return sum;
}


// f. sắp xếp mảng giảm đần
void Sap_Xep_Mang_Giam_Dan(int m, int n, int **arr) {
    for(int i=0; i < m*n-1; i++) {
        for(int j = i + 1; j < m * n; j++) {
            if (arr[i/n][i%n] < arr[j/n][j%n]) {
                int temp = arr[i/n][i%n];
                arr[i/n][i%n] = arr[j/n][j%n];
                arr[j/n][j%n] = temp;
            }
        }
    }
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}



int main() {
    int m, n;
    printf("Nhap vao m, n: "); scanf("%d%d", &m, &n);
    int **arr = (int**) malloc(sizeof(int*) * m);
    for(int i=0; i<m; i++) {
        arr[i] = (int*) malloc(sizeof(int) * n);
    }
    
    Nhap_Ma_Tran(m, n, arr);

    In_Mang(m, n, arr);
    printf("\nTong Cac Phan Tu Le va La So Am: %d", Tong_So_Le_Am(m, n, arr));
    printf("\nCac Phan Tu Le Co Tan Cung La 3: %d", Dem_Phan_Tu_Le(m, n, arr));
    printf("\nTong Cac Phan Tu Nam Tren Duong Cheo Chinh: %d", Tong_Phan_Tu_Tren_Duong_Cheo_Chinh(m, n, arr));
    printf("\nTong Cac Phan Tu Tren Cot K: %d", Tong_Phan_Tu_Tren_Cot_K(m, n, arr));
    printf("\nSap Xep Mang Giam Dan: \n");
    Sap_Xep_Mang_Giam_Dan(m, n, arr);


    for(int i=0 i<m; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}