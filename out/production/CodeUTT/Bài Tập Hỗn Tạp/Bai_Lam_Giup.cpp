
//* Nhập - xuất - tính tổng - trung bình trong ma trận vuông cấp n

#include<conio.h>
#include<stdio.h>
#include<math.h>
#define MAX 100

void nhapmatran(int a[][MAX], int &n)
{
	do
	{
		printf("\nNhap n: ");
		scanf("%d",&n);
	} while(n<=0 || n>MAX);
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++)
		{
			printf("\nSo phan tu a[%d][%d] la: ",i,j);
			scanf("%d",&a[i][j]);
		}
    }
}

void xuatmatran(int a[][MAX], int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%5d",a[i][j]);
		}
		printf("\n");
	}
}

double Tong(int a[][MAX], int n) //! tổng các phần tử trên đường chéo chính của ma trận
{
	double sum=0;
	for(int i=0;i<n;i++)
		sum=sum+a[i][i];
	return sum;
}

double Tong_Phan_Tu (int a[][MAX], int n) { //! tổng các phần tử của ma trận
    int sum = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            sum += a[i][j];
        }
    }
    return sum;
}

double Tich(int a[][MAX], int n) //! tích các phần tử trên đường chéo chính của ma trận
{
	double tich = 1;
	for(int i=0;i<n;i++) 
		tich = tich * a[i][i];
	return tich;
}

double Tich_Phan_Tu (int a[][MAX], int n) { //! tích các phần tử ma trận
    double tich_2 = 1;
	for(int i=0;i<n;i++) {  
        for (int j=0; j<n; j++) { 
		    tich_2 = tich_2 * a[i][i];
        }
    }
	return tich_2;
}

double TrungBinh(int a[][MAX], int n) //! trung bình các phần tử trên đường chéo chính
{
	double avg;
	avg = double (Tong(a,n)/n);
	return avg;
}

int main()
{
	int a[MAX][MAX],n;
	nhapmatran(a,n);
	printf("\nNoi dung cua ma tran\n");
	xuatmatran(a,n);
	printf ("\nTong cac phan tu tren duong cheo chinh: %8.2f", Tong(a,n));
    printf ("\nTong cac phan tu trong ma tran: %8.2f", Tong_Phan_Tu(a, n));
	printf ("\nTich cac phan tu tren duong cheo chinh: %8.2f", Tich(a,n));
    printf ("\nTinh cac phan tu cua ma tran: %8.2f", Tich_Phan_Tu(a,n));
	printf ("\nTrung binh cac phan tu tren duong cheo chinh: %8.2f", TrungBinh(a,n));
    

	getch();
}