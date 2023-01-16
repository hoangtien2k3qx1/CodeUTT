
#include<stdio.h>

void hoanvi(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    hoanvi(&x, &y);
    printf("%d , %d", x, y);
}