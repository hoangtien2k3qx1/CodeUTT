
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int check(char *str) {
    int count;
    for(int i=0; i<strlen(str); i++) {
        if (str[i] == 'a') {
            count++;
        }
    }
    return count;
}


int main() {
    char str[50];
    printf("Input string str: ");
    gets(str);

    printf("%d", check(str));


    return 0;
}