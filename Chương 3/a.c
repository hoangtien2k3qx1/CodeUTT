
// Tính : S = 1/10 + 1/20 + ... + 1/(10*n);


#include<stdio.h>
#include<math.h>

int main() {
    int n;
    printf ("Nhap vao n = ");
    scanf ("%d", &n);
    float s = 0;
    for (int i=1; i<=n; i++) {
        s = s + 1.0/(i*10);
    }
    printf ("Sum = %f", s);
    return 0;
}