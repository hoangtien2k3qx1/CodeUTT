
// hoàm xóa khoảng trắng trong C

#include <stdio.h>
#include <string.h>

char *delete_space(char *str, char *result) {
    int pos = 0;
    const int len = strlen(str);
    for(int i=0; i<len; i++) {
        char c = *(str + i);
        if (c == '\r' || c == '\n' || c == ' ') {
            continue;
        }
        result[pos++] = c;
    }
    return result;
}

int main(void) {
    char str[100];
    printf("Nhap vao chuoi co khoang trang: ");
    gets(str);
    printf("[%s]\n", str);
    char result[100];
    printf("[%s]\n",(delete_space(str, result)));
}