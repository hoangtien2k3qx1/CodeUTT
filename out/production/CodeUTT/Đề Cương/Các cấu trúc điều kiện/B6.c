
// nhập vào n. tính tổng các số chẵn từ 1->n

#include<stdio.h>
#include<math.h>

int main() {    
    int n, sum = 0;
    printf("Nhap vao n = "); scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        if (!(i % 2)) {
            sum += i;
        }
    }
    printf("Sum = %d", sum);
    return 0;
}