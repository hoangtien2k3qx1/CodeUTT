/*
    Câu 25: Viết chương trình thực hiện các yêu cầu sau:
    1.	Khai báo lớp SP1 mô tả các đối tượng là số phức với các thuộc tính: phần thực, phần ảo.
    Xây dựng hàm tạo, phương thức nhập số phức, in số phức, tính module số phức
    2.	Xây dựng lớp SP2 kế thừa từ lớp SP1 và bổ sung:
    Nạp chồng các toán tử: = (gán), < (nhỏ hơn), + (cộng)
    3.	Viết chương trình chính ứng dụng lớp SP2 để nhập một danh sách các đối tượng 
    là các số phức (tối đa 10 phần tử). Tìm số phức có giá trị nhỏ nhất (theo module) 
    và tính tổng các số phức trong dãy số.

*/

#include <bits/stdc++.h>
using namespace std;

class SoPhuc {
protected:
    float a, b;

public:
    SoPhuc(){};
    SoPhuc(float a, float b) : a(a), b(b){};
    virtual ~SoPhuc(){};

    friend istream& operator >> (istream &, SoPhuc &);
    friend ostream& operator << (ostream &, SoPhuc);
};


class SoPhuc2 : public SoPhuc 
{
public:
    SoPhuc2() {};
    SoPhuc2(float a, float b) : SoPhuc(a, b){};
    ~SoPhuc2(){};

    // bool operator=(SoPhuc2<T, X> &);
    // bool operator<(SoPhuc2<T, X> &);
    SoPhuc2 operator+ (SoPhuc2);
    float TinhMuDunSoPhuc(SoPhuc2);
    void SoPhucNhoNhat(SoPhuc2 *, int);

    void NhapThongTinSoPhuc(SoPhuc2 *, int);
    void InThongTinSoPhucVuaNhap(SoPhuc2 *, int);
    void InDanhSachTongMudun(SoPhuc2 *, int);
    void TongTatCaCacSoPhuc(SoPhuc2 *, int);
};

istream &operator >> (istream &input, SoPhuc &sp) {
    cout << "\n\tPhan thuc a: ";
    input >> sp.a;
    cout << "\tPhan ao b: ";
    input >> sp.b;
    return input;
}

ostream &operator << (ostream &output, SoPhuc sp)
{
    if (sp.a == 0 && sp.b != 0)
        output << sp.a << "i" << endl;
    else if (sp.a != 0 && sp.b == 0)
        output << sp.a << endl;
    else if (sp.a == 0 && sp.b == 0)
        output << 0 << endl;
    else // a != 0 && b != 0
        output << sp.a << ((sp.b > 0) ? " + " : " - ") << abs(sp.b) << "i" << endl;
    return output;
}

float SoPhuc2::TinhMuDunSoPhuc(SoPhuc2 sp)
{
    sp.a = abs(sp.a);
    sp.b = abs(sp.b);
    float result = (float)(pow(sp.a, 2) + pow(sp.b, 2));
    return (float)sqrt(result);
}

// template<typename T, typename X> bool SoPhuc2<T, X>::operator=(SoPhuc2<T, X> &sp1)
// {
//     return this->TinhMuDunSoPhuc(sp1) == sp1.TinhMuDunSoPhuc(sp1);
// }

// template<typename T, typename X> bool SoPhuc2<T, X>::operator<(SoPhuc2<T, X> &sp1)
// {
//     return (T)sqrt(pow(this->a, 2) + pow(this->b, 2)) < (T)sqrt(pow(sp1.a, 2) + pow(sp1.b, 2));
// }


SoPhuc2 SoPhuc2::operator+ (SoPhuc2 sp) {
    SoPhuc2 sum;
    sum.a = this->a + sp.a;
    sum.b = this->b + sp.b;
    return sum;
}

void SoPhuc2::TongTatCaCacSoPhuc(SoPhuc2 *arr, int n) {
    SoPhuc2 Sum(0, 0);
    if (n % 2) {
        for(int i = 0; i < n; i+=2) {
            Sum = Sum + arr[i] + arr[i + 1];
        }
    } else {
        Sum = arr[0];
        for(int i = 0; i < n; i+=2) {
            Sum = Sum + arr[i] + arr[i + 1];
        }
    }
    cout << "\tTONG TAT CA CAC SO PHUC: " << Sum << endl;
}


void SoPhuc2::SoPhucNhoNhat(SoPhuc2 *arr, int n) {
    float Min = arr->TinhMuDunSoPhuc(arr[0]);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr->TinhMuDunSoPhuc(arr[i]) < Min) {
            Min = arr->TinhMuDunSoPhuc(arr[i]);
            count = i;
        }
    }
    cout << "\n\tSO PHUC CO MODUN NHO NHAT: " << arr[count] << endl;
}


void SoPhuc2::NhapThongTinSoPhuc(SoPhuc2 *arr, int n) {
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap vao so phuc thu " << i + 1 << ": ";
        cin >> arr[i];
    }
}

void SoPhuc2::InThongTinSoPhucVuaNhap(SoPhuc2 *arr, int n) {
    cout << "\n\tDANH SACH SO PHUC VUA NHAP: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "\t\tSo Phuc " << i + 1 << ": " << arr[i];
    }
}

void SoPhuc2::InDanhSachTongMudun(SoPhuc2 *arr, int n) {
    cout << "\n\tDANH SACH TONG MUDUN SO PHUC: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "\t\tMudun " << i + 1 << ": " << arr->TinhMuDunSoPhuc(arr[i]) << endl;
    }
}


int main()
{
    system("cls");
    SoPhuc2 sp;
    int n; cout << "\nNhap vao so N so phuc: "; cin >> n;
    SoPhuc2 *arr = new SoPhuc2[n];

    sp.NhapThongTinSoPhuc(arr, n);
    cout << "\n___________________________________________\n";
    sp.InThongTinSoPhucVuaNhap(arr, n);
    sp.InDanhSachTongMudun(arr, n);
    sp.SoPhucNhoNhat(arr, n);
    sp.TongTatCaCacSoPhuc(arr, n);
    cout << "\n___________________________________________\n";

    cin.get();
    return 0;
}
