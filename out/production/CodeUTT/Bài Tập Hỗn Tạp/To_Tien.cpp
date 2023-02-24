/*
    có 10$, 20$, 50$ để tổng 3 tờ tiền đó bằng 200$
*/

#include<iostream>

int main() {
    int count = 0;
    for (int i=0; i<=10; i++) {
        for (int j=0; j<=20; j++) {
            for (int k=0; k<=50; k++) {
                if (i*10 + j*20 + k*50 == 200) {
                    printf ("\nCan %d to 10(VND) \tCan %d to 20(VND) \tCan %d to 50(VND)",i, j, k);
                    count++;
                }
            }
        }
    }
    std::cout << std::endl;
    std::cout << "Tong can co " << count << " phuong an!" << std::endl;
    return 0;
}
