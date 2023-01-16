/*

    câu lệnh goto trong c/c++ hoạt động  như thế nào
*/
#include<stdio.h>
#include<conio.h>

int main() {
    int i = 0;
    quaylai: printf ("\ni = %d", i, "\t");
    i += 1;
    if (i < 10){
        goto quaylai;
    }


    return 0;
}


