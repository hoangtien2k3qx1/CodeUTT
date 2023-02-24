
// nhập vào số n, in ra số chính phương từ 1 -> n

#include<stdio.h>
#include<math.h>

int main() {
    int n;
    printf("nhap vao n = ");
    scanf("%d", &n);

    int s = sqrt((int)n);
    if (s*s == n) {
        printf("%d la so chinh phuong", n);
    } else {
        printf("%d khong phai so chinh phuong", n);
    }
    return 0;
}