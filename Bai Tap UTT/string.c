

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

// xoa khoang trang
char *Xoa_Khoang_Trang(char *str) {
    int length = strlen(str);
    // xoa khoang trang dau chuoi
    while(str[0] == ' ') {
        strcpy(&str[0], &str[1]);
        length--;
    }
    for(int i=0; i<strlen(str) - 1; i++) {
        if (str[i] == ' ' && str[i + 1] == ' ') {
            strcpy(&str[i], &str[i + 1]);
            i--;
            length--;
        }
    }

    while(str[length - 1] == ' ') {
        strcpy(&str[length-1], &str[length]);
        length--;
    }
    return str;
}

// dem so ky tu chuoi
int Count_Elements(char *str) {
    Xoa_Khoang_Trang(str);
    int count = 0;
    for(int i=0; i<strlen(str); i++) {
        if (str[i] == ' ') {
            count++;
        }
    }
    return count + 1;
}


// ky tu hoa
char *Ky_Tu_Hoa(char *str) {
    int length = strlen(str);
    for(int i=0; i<length; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
    return str;
}

//  đảo các tư trong chuỗi
char *Dao_Tu(char *str) {
    int length = strlen(str), count = 0, j = 0;
    char *ans = (char*) malloc(sizeof(char) * length);
    for(int i=length - 1; i >= 0; i--) {
        count++;
        if (str[i] == ' ') {
            for(int k = i; k < i + count; k++) {
                ans[j++] = str[k + 1];
            }
            ans[j - 1] = ' ';
            count = 0;
        }
        if (i == 0) {
            for(int k = i; k < i + count; k++) {
                ans[j++] = str[k];
            }
        }
    }
    ans[length] = '\0';
    return ans;
}


int main() {
    char str[100];
    printf("Nhap vao chuoi: ");
    gets(str);

    printf ("\nXoa Khoang Trang: [%s] ", Xoa_Khoang_Trang(str));
    printf("\nChuoi co so tu: %d", Count_Elements(str));
    printf("\nKy Tu Hoa: %s", Ky_Tu_Hoa(str));
    printf("\nDao Tu: %s", Dao_Tu(str));

    return 0;
}