
// Tìm số hoàn hảo trong đoạn từ 1->n

#include<stdio.h>
#include<math.h>

int SoHoanHao(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            sum = sum + i;
        }
    }
    return sum;
}

int main()
{
    int n;
    printf("Nhap vao n = "); scanf("%d", &n);
    SoHoanHao(n);
    for(int i=1; i<=n; i++) {
        if (SoHoanHao(i) == i) {
            printf("%d ", i);
        }
    }
    return 0;
}
