

/*
    a. xoá các ký tự khoảng trắng và các từ ngăn cách nhau bơi 1 khoảng trắng.
    b. đổi ký tự thường thành ký tự hoa
    c. đếm xem chuỗi có bao nhiêu từ
    d. dảo ngược các từ trong chuỗi

*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

// a
// Cách 1: dùng hàm strcpy
// char *Xoa_Khoang_Trang(char *str) {
//     int length = strlen(str);
//     while(str[0] == ' ') {
//         strcpy(&str[0], &str[1]);
//         str[length-- -1] = '\0';
//     }
//     for(int i=0; i<length-1; i++) {
//         if (str[i] == ' ' && str[i + 1] == ' ') {
//             strcpy(&str[i], &str[i + 1]);
//             i--;
//             str[length-- -1] = '\0';
//         }
//     }
//     while(str[length - 1] == ' ') {
//         strcpy(&str[length - 1], &str[length]);
//         str[length-- -1] = '\0';
//     } 
//     return str;
// }



// a
// Cách 2: dùng đổi chỗ thông thường
char xoa(char *a, int vt)
{
    int n = strlen(a);
    for (int i = vt; i <= n; i++)
    {
        a[i] = a[i + 1];
    }
    n--;
    return 0;
}

char *Xoa_Khoang_Trang(char *a)
{
    int i, n=strlen(a);
    for (i = 0; i < n; i++){
        if (a[0] == ' ') {
            xoa(a, 0);
            n--;
        }
        if (a[i] == ' ' && a[i + 1] == ' ') {
            xoa(a, i);
            i--;
            n--;
        }
        if (a[n-1] == ' ') {
            xoa(a, n-1);
            n--;
        }
    }
    return a;
}



// b.

char *Ky_Tu_Hoa(char *str) {
    for(int i=0; i<strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
    return str;
}


// c.
int Dem_So_Tu(char *str) {
    int count = 0;
    for(int i=0; i<strlen(str); i++)
        if (str[i] == ' ') count++;
    return count + 1;
}

// d.

char *Dao_Nguoc_Tu_Trong_Chuoi(char *str) {
    int length = strlen(str);
    int j = 0, count = 0;
    char *new_string = (char*) malloc(sizeof(char) * (length + 1));
    for(int i = length - 1; i >= 0; i--) {
        count++;
        if (str[i] == ' ') {
            for(int k = i; k < i + count; k++) {
                new_string[j++] = str[k + 1]; 
            }
            new_string[j - 1] = ' ';
            count = 0;
        }
        // vì từ cuối cùng là không chứ khoảng trắng, nên ta phải xét riêng từ cuối cùng ra 1 biến mới
        if (i == 0) {
            for(int k = i; k < i + count; k++) {
                new_string[j++] = str[k];
            }
        }
    }
    new_string[length] = '\0';
    return new_string;
}




int main() {
    char str[100];
    printf("Nhap vao chuoi: "); gets(str);
    
    printf("\nChuoi Da Xoa Khoang Trang: [%s]", Xoa_Khoang_Trang(str));
    printf("\nKy Tu Hoa: %s", Ky_Tu_Hoa(str));
    printf("\nSo Ky Tu Trong Chuoi: %d", Dem_So_Tu(str));
    printf("\nDao Tu Trong Chuoi: %s", Dao_Nguoc_Tu_Trong_Chuoi(str));

    return 0;
}