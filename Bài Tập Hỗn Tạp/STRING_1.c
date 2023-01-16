
/*
    a. xóa các ký tự khoảng trắng và mỗi từ cách nhau 1 dấu cách. 
    b. Đếm xem chuỗi có bao nhiêu từ.
    c. đảo ngược các từ trong chuỗi.
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

// a. xóa các ký tự khoảng trắng và mỗi từ cách nhau 1 dấu cách.
char *Chuan_Hoa_Chuoi(char *str) {
    int length = strlen(str);
    // xóa khoảng trắng ở vị trí đầu chuỗi.
    while(str[0] == ' ') {
        strcpy(&str[0], &str[1]);
        str[length-- - 1] = '\0'; // length--;
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
    int length = strlen(str), count = 0;
    Chuan_Hoa_Chuoi(str);
    for(int i=0; i<length; i++) {
        if (str[i] == ' ') {
            count++;
        }
    }
    return count + 1;
}


// c. đảo ngược các từ trong chuỗi.
char *daoNguocTuCoTrongChuoi(char *S){
    //1. Khởi tạo mảng ketQua
    char *ketQua = (char*) malloc(sizeof(char) * (strlen(S) + 1));
    int j = 0;
    int dem = 0;

    //2. Duyệt từng ký tự bắt đầu từ cuối chuỗi
    for(int i = strlen(S); i >= 0; i--){
        if (i == strlen(S) || i == strlen(S)-1) //Xử lý ký tự '\0' bằng cách bỏ qua
            continue;

        //3. Đếm số lượng ký tự mình đi qua
        dem++;

        //4. Khi gặp khoảng trắng, thực hiện sao chép từ chuỗi qua mảng ketQua
        if (S[i] == ' '){
            for(int k = i; k < i + dem; k++) {
                ketQua[j] = S[k+1];
                j++;
            }
            ketQua[j-1] = ' ';
            dem = 0;
        }

        //5. Xử lý từ ở đầu câu
        if (i == 0){
            for(int k = i; k < i+dem; k++){
                ketQua[j] = S[k];
                j++;
            }
        }
    }

    ketQua[strlen(S)-1] = '\0';

    return ketQua;
}



int main() {
    char str[100];
    printf("Nhap vao chuoi str: "); fflush(stdin);
    gets(str);


    printf("\nChuoi Da Xoa: [%s]", Chuan_Hoa_Chuoi(str));
    printf("\nSo tu cua chuoi: %d", Dem_Tu(str));

    char *KetQua = daoNguocTuCoTrongChuoi(str);
    printf("\nDao Nguoc Tu: %s", KetQua);

 
    return 0;
}