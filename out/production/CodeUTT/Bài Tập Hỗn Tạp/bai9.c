

// tính trung bình cộng các số chẵn từ 1->10

#include<stdio.h>

int Sum_Array(int n){
    int i, T = 0, count = 0, sum;
    for (i=1; i<=10; i++) {
        if (i % 2 == 0) {
            T += i;
            count++;
        }
    }
    sum = T / count;
    return sum;
}

int main() 
    int n;
    printf ("Nhap vao n = ");
    scanf ("%d", &n);
    printf ("Sum = %d", Sum_Array(n));

    return 0;
}