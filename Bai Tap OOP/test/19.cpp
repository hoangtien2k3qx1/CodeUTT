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
protected:
    int tuso, mauso;

public:
    PS1() {};
    PS1(int tuso, int mauso) {
        this->tuso = tuso;
        this->mauso = mauso;
    }
    ~PS1() {}

    friend istream& operator >> (istream&, PS1&);
    friend ostream& operator << (ostream&, PS1);

};


class PS2 : public PS1 {
public:

    bool operator = (PS2);
    bool operator < (PS2);

    void toigian(PS2 *, int);
    void sapxep(PS2 *, int);

};


istream& operator >> (istream& in, PS1 &ps) {
    cout << "Nhap tuso: "; in >> ps.tuso;
    cout << "Nhap mauso: "; in >> ps.mauso;
    return in;
}

ostream& operator << (ostream& out, PS1 ps) {
    out << ps.tuso << "/" << ps.mauso << endl;
    return out;
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

bool PS2::operator = (PS2 ps) {
    this->tuso = ps.tuso;
    this->mauso = ps.mauso;
}

bool PS2::operator < (PS2 ps) {
    return (this->tuso*1.0/this->mauso > ps.tuso*1.0/ps.mauso);
}

void PS2::sapxep(PS2 *arr, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {
                PS2 temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

int main() {
    system("cls");

    int n; cout << "Nhap vao n phan so: "; cin >> n;

    PS2 *arr = new PS2[n];

    for(int i = 0; i < n; i++) {
        cout << "\nNhap vao phan so thu " << i + 1 << ": " << endl;
        cin >> arr[i];
    }

    arr->toigian(arr, n);
    arr->sapxep(arr, n);

    for(int i = 0; i < n; i++) {
        cout << "\nPhan so " << i + 1 << ": ";
        cout << arr[i];
    }

    return 0;
}