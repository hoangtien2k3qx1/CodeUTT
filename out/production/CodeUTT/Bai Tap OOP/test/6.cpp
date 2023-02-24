
#include<bits/stdc++.h>
using namespace std;

class matran {
private:
    int m, n;
    int **arr;

    void dynamic() {
        arr = new int*[m];
        for(int i = 0; i < n; i++) {
            arr[i] = new int[n];
        }
    }

public:
    matran() {}
    matran(int m, int n) {
        this->m = m;
        this->n = n;
    }
    ~matran() {}

    void nhap();
    void xuat();
    int TinhTong();

};

void matran::nhap() {
    cout << "Nhap vao m hang: "; cin >> m;
    cout << "Nhap vao n cot: "; cin >> n;

    dynamic();
    cout << "Nhap vao phan tu ma tran: " << endl;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << "arr["<<i<<"]["<<j<<"] = ";
            cin >> arr[i][j];
        }
    }
}

void matran::xuat() {
    cout << "Ma Tran Vua Nhap Vao: " << endl;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int matran::TinhTong() {
    int sum = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}


int main() {
    system("cls");


    matran mt;
    mt.nhap();
    mt.xuat();
    cout << mt.TinhTong();
    





}