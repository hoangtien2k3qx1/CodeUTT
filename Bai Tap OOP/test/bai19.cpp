/*
    Câu 19: Viết chương trình thực hiện các yêu cầu sau:
    1.	Khai báo lớp PS1 cho các đối tượng là phân số với các thuộc tính: tử số, mẫu số.
    Xây dựng phương thức nhập phân số (mẫu số khác 0), in phân số, tối giản phân số.
    2.	Xây dựng lớp PS2 kế thừa từ lớp PS1 và bổ sung:
    Nạp chồng các toán tử: = (gán), < (nhỏ hơn).
    3.	Viết chương trình chính ứng dụng lớp PS2 để nhập một danh sách các đối tượng 
    là các phân số (tối đa 10 phần tử). Tìm phân số có giá trị lớn nhất, nhỏ nhất.

*/

#include<bits/stdc++.h>
using namespace std;

class PS1 {
public:
    int tuso, mauso;

public:
    PS1() {};
    PS1(int tuso, int mauso) {
        this->tuso = tuso;
        this->mauso = mauso;
    }
    virtual ~PS1() {};

    friend istream& operator >> (istream&, PS1&);
    friend ostream& operator << (ostream&, PS1);

};

class PS2 : public PS1 {
public: 
    PS2() {};

    bool operator= (const PS2 &);
    bool operator> (const PS2&) const;
    bool operator< (const PS2&) const;

    void toigian(PS2 *, int);
    void SapXepDanhSachPhanSo(PS2*&, int);
    void InDanhSachPhanSoDaSapXep(PS2*, int);

};  

istream& operator >> (istream& input, PS1 &ps) {
    cout << "Nhap vao tuso: "; input >> ps.tuso;
    cout << "Nhap vao mauso: "; input >> ps.mauso;
    return input;
}

ostream& operator << (ostream& output, PS1 ps) {
    output << ps.tuso << "/" << ps.mauso << endl;
    return output;
}

bool PS2::operator = (const PS2 &ps) {
    this->tuso = ps.tuso;
    this->mauso = ps.mauso;
}

bool PS2::operator < (const PS2 &ps) const {
    return (this->tuso*1.0/this->mauso) < (ps.tuso*1.0/ps.mauso);
}

int gcd(int a, int b) {
    if (b == 0) 
        return a;
    return gcd(b, a % b);
}

void PS2::toigian(PS2 *arr, int n) {
    for(int i = 0; i < n; i++) {
        int g = gcd(arr[i].tuso, arr[i].mauso);
        arr[i].tuso /= g;
        arr[i].mauso /= g;
    }
}

void PS2::SapXepDanhSachPhanSo(PS2 *&arr, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main() {
    system("cls");
    int n; 
    do {
        cout << "\nNhap vao n phan so: ";
        cin >> n;
        if (n < 0 || n > 10) {
            cout << "\nLoi, Xin Nhap Lai !!!" << endl;
        }
    }while (n < 0 || n > 10);
    PS2 *arr = new PS2[n];
    cout << "\n--- NHAP DANH SACH PHAN SO: --- " << endl;
    for(int i = 0; i < n; i++) {
        cout << "Nhap vao phan so thu " << i + 1 << endl;
        cin >> arr[i];
    }

    arr->toigian(arr, n);
    arr->SapXepDanhSachPhanSo(arr, n);
    cout << "\nPHAN SO CO GIA TRI LON NHAT: " << arr[0] << endl;
    cout << "PHAN SO CO GIA TRI NHO NHAT: " << arr[n-1] << endl;

    return 0;
    cin.get();
}

