
/*
    Câu 13: Viết chương trình thực hiện các yêu cầu sau:
        1.	Khai báo lớp ma trận với các thuộc tính: số hàng, số cột, các phần tử của ma trận.
        2.	Xây dựng các phương thức: nhập, xuất một đối tượng ma trận.
        3.	Nhập vào hai ma trận đồng cấp. Thực hiện cộng hai ma trận vừa nhập (dùng hàm bạn). In ra màn hình hai ma trận ban đầu và ma trận kết quả.

*/

#include<bits/stdc++.h>
using namespace std;

class MaTrix {
    private:
        int m, n;
        float arr[100][100];
        float brr[100][100];
        float crr[100][100];

    public:
        MaTrix() {
            this->m = m;
            this->n = n;
        }
        
        void inputArray();
        friend void Sum_Two_Matrix(MaTrix);

};

void MaTrix::inputArray() {
    cout << "Nhap vao so hang: "; cin >> m;
    cout << "Nhap vao so cot: "; cin >> n;

    cout << "\nNhap vao cac phan tu ma tran 1" << endl;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << "arr["<<i<<"]["<<j<<"] = ";
            cin >> arr[i][j];
        }
    }

    cout << "\nNhap vao cac phan tu ma tran 2" << endl;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << "brr["<<i<<"]["<<j<<"] = ";
            cin >> brr[i][j];
        }
    }
}

void Sum_Two_Matrix(MaTrix matrix) {
    for(int i = 0; i < matrix.m; i++) {
        for(int j = 0; j < matrix.n; j++) {
            matrix.crr[i][j] = matrix.arr[i][j] + matrix.brr[i][j];
        }
    }
    for(int i = 0; i < matrix.m; i++) {
        for(int j = 0; j < matrix.n; j++) {
            cout << matrix.crr[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    system("cls");
    MaTrix arr;
    arr.inputArray();

    cout << "Tong 2 ma tran tren: " << endl; 
    Sum_Two_Matrix(arr);

    return 0;
}

