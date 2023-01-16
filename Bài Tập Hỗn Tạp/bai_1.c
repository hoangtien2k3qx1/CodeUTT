
#include<stdio.h>
#include<string.h>

int main() {
	char maho_1[10], tenho_1[30], maho_2[10], tenho_2[30];
	float Sodien_1, dongia, thanhtien_1, thanhtien_2;
	float Sodien_2;
	printf ("Nhap vao maho_1 : "); gets(maho_1);
	printf ("\nNhao vao maho_2 : "); gets(maho_2);
	printf ("\nNhap vao tenho_1 : "); gets(tenho_1);
	printf ("\nNhap vao tenho_2 : "); gets(tenho_2);
	printf("\nNhap vao sodien_1 : "); scanf ("%f", &Sodien_1);
	printf("\nNhap vao sodien_2 : "); scanf("%f", &Sodien_2);
	printf ("\nNhap vao dongia : "); scanf ("%f", &dongia);

	thanhtien_1 = Sodien_1 * dongia;
	thanhtien_2 = Sodien_2 * dongia;
	printf ("\nThanh Tien ho 1 = %.2f", thanhtien_1);
	printf ("\nThanh Tien ho 2 = %.2f", thanhtien_2);

	if (thanhtien_1 > thanhtien_2) {
		printf ("\nTen ho la : %s", tenho_1);
	} else {
		printf ("\nTen ho la : %s", tenho_2);
	}
	
	return 0;
}




