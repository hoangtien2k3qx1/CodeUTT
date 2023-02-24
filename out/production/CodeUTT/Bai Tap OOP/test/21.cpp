/*
    Câu 21: Viết chương trình thực hiện các yêu cầu sau:
    1.	Khai báo lớp SP1 cho các đối tượng là số phức với các thuộc tính: phần thực, phần ảo.
    Xây dựng hàm tạo, phương thức nhập số phức, in số phức, tính module số phức.
    2.	Xây dựng lớp SP2 kế thừa từ lớp SP1 và bổ sung:
    Nạp chồng các toán tử: = (gán), < (so sánh nhỏ hơn theo module).
    3.	Viết chương trình chính ứng dụng lớp SP2 để nhập một danh sách các đối tượng là các 
    số phức (tối đa 10 phần tử). Sắp xếp lại danh sách đã nhập theo trật tự tăng dần của module.

*/

#include<bits/stdc++.h>
using namespace std;

class SP1 {
protected:
    float thuc, ao;
    
public:
    SP1() {}
    SP1(float thuc, float ao) {
        this->thuc = thuc;
        this->ao = ao;
    }
    ~SP1() {}

    friend istream& operator >> (istream&, SP1&);
    friend ostream& operator << (ostream&, SP1);

};


class SP2 : public SP1 {
public:

    // bool operator = (SP2);
    bool operator < (SP2 &);


    float tinhModun(SP2 );
    SP2 * sapxep(SP2 *&, int);


};


istream& operator >> (istream& in, SP1& sp) {
    cout << "Nhap phan thuc: "; in >> sp.thuc;
    cout << "Nhap phan ao: "; in >> sp.ao;

    return in;
}

ostream& operator << (ostream& output, SP1 sp) {
    if (sp.thuc == 0 && sp.ao != 0) 
        output << sp.thuc << "i" << endl;
    else if (sp.thuc != 0 && sp.ao == 0)
        output << sp.thuc << endl;
    else if (sp.thuc == 0 &&sp.ao == 0)
        output << 0 << endl;
    else // a != 0 && b != 0
        output << sp.thuc << ((sp.ao > 0) ? " + " : " - ") << abs(sp.ao) << "i" << endl;
    return output;
}


float SP2::tinhModun(SP2 sp) {
    sp.thuc = abs(sp.thuc);
    sp.ao = abs(sp.ao);
    return (float)sqrt(pow(sp.thuc, 2) + pow(sp.ao, 2));
}

bool SP2::operator < (SP2 &sp) {
    return this->tinhModun(*this) < sp.tinhModun(sp);
}

SP2 * SP2::sapxep(SP2 *&arr, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n ; j++) {
            if (arr[j] < arr[i]) {
                SP2 temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    return arr;
}

int main() {
    system("cls");

    int n; cout << "Nhap vao n so phuc: "; cin >> n;

    SP2 *arr = new SP2[n];

    for(int i = 0; i < n; i++) {
        cout << "\nNhap vao so phuc " << i + 1 << ": " << endl;
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++) {
        cout << "\nSo Phuc Thu " << i + 1 << ": " << arr[i] << endl;
    }

    arr->sapxep(arr, n);
    cout << "\nDANH SACH SO PHUC DA DUOC SAP XEO THEO MODUN: " << endl;
    for(int i = 0; i < n; i++) {
        cout << "\nSo Phuc Thu " << i + 1 << ": " << arr[i] << endl;
    }

    return 0;
}