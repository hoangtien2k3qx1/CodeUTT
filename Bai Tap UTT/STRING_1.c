
/*
    a. xóa các ký tự khoảng trắng và mỗi từ cách nhau 1 dấu cách. 
    b. Đếm xem chuỗi có bao nhiêu từ.
    c. đổi ký tự thường thành ký tự hoa.
    d. đảo ngược các từ trong chuỗi.
    e. Kiểm tra xâu đôi xứng.
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

// a. xóa các ký tự khoảng trắng và mỗi từ cách nhau 1 dấu cách.
char *Chuan_Hoa_Chuoi(char *str) {
    int length = strlen(str);
    // xóa khoảng trắng ở vị trí đầu chuỗi.
    while(str[0] == ' ') {
        strcpy(&str[0], &str[1]);
        length--;
    }
    // xóa khoản trắng ở vị trí thân chuỗi
    for(int i=0; i<strlen(str) - 1; i++) {
        if (str[i] == ' ' && str[i + 1] == ' ') {
            strcpy(&str[i], &str[i + 1]);
            i--;
            length--;
        } 
    }
    // xóa khoảng trắng ở cuối chuỗi
    while(str[length - 1] == ' ') {
        strcpy(&str[length - 1], &str[length]);
        length--;
    }
    return str;
}


// b. Đếm xem chuỗi có bao nhiêu từ.
int Dem_Tu(char *str) {
    int count = 0;
    Chuan_Hoa_Chuoi(str);
    for(int i=0; i<strlen(str); i++) {
        if (str[i] == ' ') {
            count++;
        }
    }
    return count + 1;
}


// c. đổi ký tự thường thành ký tự hoa.
char *Ky_Tu_Hoa(char *str) {
    for(int i=0; i<strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
    return str;
}

// d. đảo ngược các từ trong chuỗi.
char *daoNguocTuCoTrongChuoi(char *S) {
    char *ketQua = (char*) malloc(sizeof(char) * (strlen(S)));
    int j = 0;
    int dem = 0;
    for(int i = strlen(S) - 1; i >= 0; i--){
        dem++;
        if (S[i] == ' '){
            for(int k = i; k < i + dem; k++) { // (i + dem) = strlen(S);
                ketQua[j++] = S[k + 1]; 
            }
            ketQua[j - 1] = ' ';
            dem = 0;
        }
        if (i == 0){
            for(int k = i; k < i + dem; k++){
                ketQua[j++] = S[k];
            }
        }
    }
    ketQua[strlen(S)] = '\0';
    return ketQua;
}


// e. kiểm tra xâu đối xứng.
bool Kiem_Tra_Chuoi_Doi_Xung(char *str) {
    for(int i=0; i<=strlen(str)/2; i++) {
        if (str[i] != str[strlen(str) - i - 1]) {
            return false;
        }
    }
    return true;
}



int main() {
    char str[100];
    printf("Nhap vao chuoi str: "); fflush(stdin);
    gets(str);

    printf("\nChuoi Da Xoa: [%s]", Chuan_Hoa_Chuoi(str));
    printf("\nSo tu cua chuoi: %d", Dem_Tu(str));
    printf("\nDoi thanh ky tu HOA: %s", Ky_Tu_Hoa(str));
    printf("\nDao Nguoc Tu: %s",  daoNguocTuCoTrongChuoi(str));

    if (Kiem_Tra_Chuoi_Doi_Xung(str)) {
        printf("\nChuoi la doi xung!!!");
    } else {
        printf ("\nChuoi khong phai doi xung!!!");
    }
    
    return 0;
}