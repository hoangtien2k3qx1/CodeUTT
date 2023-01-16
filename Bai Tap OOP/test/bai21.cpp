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

class SoPhuc {
    protected:
        float a, b;

    public:
        SoPhuc() {};
        SoPhuc(float a, float b): a(a), b(b) {};
        virtual ~SoPhuc() {};

        friend istream& operator >> (istream&, SoPhuc&);
        friend ostream& operator << (ostream&, SoPhuc);
        
};

class SoPhuc2 : public SoPhuc {
    public:
        SoPhuc2() : SoPhuc(a, b) {};
        ~SoPhuc2() {};

        // SoPhuc2& operator= (SoPhuc2&);
        bool operator< (SoPhuc2&);
        float TinhMuDunSoPhuc(SoPhuc2);
        SoPhuc2 * SapXepMuDun(SoPhuc2*&, int);

};

istream& operator >> (istream& input, SoPhuc &sp) {
    cout << "\nNhap vao phan thuc a: "; input >> sp.a;
    cout << "Nhap vao phan ao b: "; input >> sp.b;
    return input;
}

ostream& operator << (ostream& output, SoPhuc sp) {
    if (sp.a == 0 && sp.b != 0) 
        output << sp.a << "i" << endl;
    else if (sp.a != 0 && sp.b == 0)
        output << sp.a << endl;
    else if (sp.a == 0 &&sp.b == 0)
        output << 0 << endl;
    else // a != 0 && b != 0
        output << sp.a << ((sp.b > 0) ? " + " : " - ") << abs(sp.b) << "i" << endl;
    return output;
}

float SoPhuc2::TinhMuDunSoPhuc(SoPhuc2 sp) {
    sp.a = abs(sp.a);
    sp.b = abs(sp.b);
    float result = (float)(pow(sp.a, 2) + pow(sp.b, 2));
    return (float)sqrt(result);
}

// SoPhuc2& SoPhuc2::operator= (SoPhuc2 &sp1)  {
//     swap(*this, sp1);
// }

bool SoPhuc2::operator < (SoPhuc2 &sp1) {
    return this->TinhMuDunSoPhuc(*this) < sp1.TinhMuDunSoPhuc(sp1);
}

SoPhuc2 * SoPhuc2::SapXepMuDun(SoPhuc2 *&arr, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                SoPhuc2 temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}

int main() {
    system("cls");
    SoPhuc2 sp;
    int n; cout << "\nNhap vao so N so phuc: "; cin >> n;
    
    SoPhuc2 *arr = new SoPhuc2[n];

    for(int i = 0; i < n; i++) {
        cout << "\nNhap vao so phuc thu " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "\n\tDANH SACH SO PHUC VUA NHAP: " << endl;
    for(int i = 0; i < n; i++) {
        cout << "\t\tSo Phuc Thu " << i + 1 << ": " << arr[i];
    }

    cout << "\n\tDANH SACH TONG MUDUN SO PHUC: " << endl;
    for(int i = 0; i < n; i++) {
        cout << "\t\tMudun " << i + 1 << ": " << arr->TinhMuDunSoPhuc(arr[i]) << endl;
    }

    cout << "\n\tDANH SACH SO PHUC DA DUOC SAP XEP THEO MUDUN: " << endl;
    arr->SapXepMuDun(arr, n);
    for(int i = 0; i < n; i++) {
        cout << "\t\tSo Phuc " << i + 1 << ": " << arr[i];
    }

    cin.get();
    return 0;
} 
