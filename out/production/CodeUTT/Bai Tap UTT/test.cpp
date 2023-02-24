
#include<iostream>
#include<cmath>
using namespace std;


void Nhap_Mang(int **arr, int m, int n) {
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }
}

void Xuat_Mang(int **arr, int m, int n) {
    for(int i=0; i<m; i++) {
        for(int j=0; i<n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    int **arr = new int*[m];
	for(int i = 0; i<m; i++)
   		arr[i] = new int[n];
           
    Nhap_Mang(arr, m, n);
    Xuat_Mang(arr, m, n);
    
    for(int i = 0; i<m; i++)
   		delete []arr[i];
	delete []arr;
    
    return 0;
}