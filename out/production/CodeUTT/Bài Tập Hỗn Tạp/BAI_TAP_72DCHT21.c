
/*  // Bai tap: Hoang Anh Tien - 72DCHT21
    Nhập vào mảng gồm n phần tử:
    a. in mảng lên màn hình
    b. tính tổng các phần tử chẵn
    c. đếm các phần tử lẻ
    d. tính TBC các số chia hết cho 3
    e. in lên màn hình các số có giá trị âm
    f. in ra số có giá trị lớn nhất
    g. in ra số có giá trị bé nhất
    h. sắp xếp mảng tăng dần
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>

void In_Mang(int arr[], int n) {
    printf("a. Cac Phan Tu Cua Mang:\t");
    for(int i=0; i<n; i++) {
        printf("%d\t", arr[i]);
    }
}

int Tong_Pt_Chan(int arr[], int n) {
    int sum = 0;
    for(int i=0; i<n; i++) {
        if (arr[i] % 2 == 0) {
            sum += arr[i];
        }
    }
    return sum;
}

int Dem_Cac_Phan_Tu_Le(int arr[], int n) {
    int count = 0;
    for(int i=0; i<n; i++) {
        if (arr[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}

float TBC_Pt_Chia_Het_Cho_3(int arr[], int n) {
    float TBC, Sum = 0, count = 0;
    for(int i=0; i<n; i++) {
        if (arr[i] % 3 == 0) {
            Sum += arr[i];
            count++;
        }
    }
    TBC = (float)Sum/count;
    return TBC;
}

void In_Cac_So_Co_Gia_Tri_Am(int arr[], int n) {
    printf("\ne. Gia Tri Am:\t");
    for(int i=0; i<n; i++) {
        if (arr[i] < 0) {
            printf("%d\t", arr[i]);
        }
    }
}

int So_Co_Gia_Tri_Lon_Nhat(int arr[], int n) {
    int max = arr[0];
    for(int i=0; i<n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int So_Co_Gia_Tri_Nho_Nhat(int arr[], int n) {
    int min = arr[0];
    for(int i=0; i<n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}



void Sap_Xep_Mang_Tang_Dan(int arr[], int n) {
    printf("\nh. Mang Sap Xep Theo Thu Tu Tang Dan:\t"); // bubbleSort
    for(int i = 0; i < n-1; i++) {
        for(int j = n - 1; j > i; j--) {
            if (arr[j] < arr[j - 1]) {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
}

int main() {
    int arr[100], n;
    printf("Nhap vao n phan tu mang: n = ");
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("\n\n");
    printf("* ===================================================================== *\n");
    In_Mang(arr, n);
    printf("\nb. Tong Cac Phan Tu Chan:\t %d", Tong_Pt_Chan(arr, n));
    printf("\nc. So Phan Tu Le:\t %d",  Dem_Cac_Phan_Tu_Le(arr, n));
    printf("\nd. TBC So Chia Het Cho 3: %.3f", TBC_Pt_Chia_Het_Cho_3(arr, n));
    In_Cac_So_Co_Gia_Tri_Am(arr, n);
    printf("\nf. Gia Tri Lon Nhat:\t %d", So_Co_Gia_Tri_Lon_Nhat(arr, n));
    printf("\ng. Gia Tri Be Nhat:\t %d", So_Co_Gia_Tri_Nho_Nhat(arr, n));
    Sap_Xep_Mang_Tang_Dan(arr, n);
    
    return 0;
}


