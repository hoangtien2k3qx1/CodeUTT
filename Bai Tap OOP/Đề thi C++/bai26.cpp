/*
    Câu 26: Viết chương trình thực hiện các yêu cầu sau:
    1.	Khai báo lớp SP1 mô tả các đối tượng là số phức với các thuộc tính: phần thực, phần ảo.
    Xây dựng hàm tạo, phương thức nhập số phức, in số phức, tính module số phức
    2.	Xây dựng lớp SP2 kế thừa từ lớp SP1 và bổ sung:
    Nạp chồng các toán tử: = (gán), > (nhỏ hơn), == (so sánh bằng)
    3.	Viết chương trình chính ứng dụng lớp SP2 để nhập một danh sách các đối tượng là các 
    số phức (tối đa 10 phần tử). Tìm số phức có giá trị lớn nhất và đếm xem có bao nhiêu số 
    phức trong danh sách có giá trị bằng 3 + 4i.

*/

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class SoPhuc {
protected:
    T a, b;

public:
    SoPhuc(){};
    SoPhuc(T a, T b) : a(a), b(b){};
    virtual ~SoPhuc(){};

    template<typename U>
    friend istream& operator >> (istream &, SoPhuc<U> &);
    template<typename V>
    friend ostream& operator << (ostream &, SoPhuc<V>);
    
};

template<typename T, typename X>
class SoPhuc2 : public SoPhuc<T>  {
public:
    SoPhuc2<T, X>() {};
    SoPhuc2<T, X>(T a, T b) : SoPhuc<T>(a, b){};
    ~SoPhuc2<T, X>(){};

    // bool operator<(SoPhuc2<T, X> &);
    bool operator=(SoPhuc2<T, X> &);
    SoPhuc2<T, X> operator+ (SoPhuc2<T, X>);
    T TinhMuDunSoPhuc(SoPhuc2<T, X>);
    void SoPhucLonNhat(SoPhuc2<T, X> *, X);

    void NhapThongTinSoPhuc(SoPhuc2<T, X> *, X);
    void InThongTinSoPhucVuaNhap(SoPhuc2<T, X> *, X);
    void InDanhSachTongMudun(SoPhuc2<T, X> *, X);
    void SoPhucBangSoPhucChoTruoc(SoPhuc2<T, X> *, X);
};

template<typename T>
istream &operator >> (istream &input, SoPhuc<T> &sp) {
    cout << "\n\tPhan thuc a: ";
    input >> sp.a;
    cout << "\tPhan ao b: ";
    input >> sp.b;
    return input;
}

template<typename T>
ostream &operator << (ostream &output, SoPhuc<T> sp) {
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

template<typename T, typename X> 
T SoPhuc2<T, X>::TinhMuDunSoPhuc(SoPhuc2<T, X> sp) {
    sp.a = abs(sp.a);
    sp.b = abs(sp.b);
    T result = (T)(pow(sp.a, 2) + pow(sp.b, 2));
    return (T)sqrt(result);
}

// template<typename T, typename X> bool SoPhuc2<T, X>::operator<(SoPhuc2<T, X> &sp1)
// {
//     return (T)sqrt(pow(this->a, 2) + pow(this->b, 2)) < (T)sqrt(pow(sp1.a, 2) + pow(sp1.b, 2));
// }


template<typename T, typename X> 
bool SoPhuc2<T, X>::operator= (SoPhuc2<T, X> &sp1) {
    return this->TinhMuDunSoPhuc(*this) == sp1.TinhMuDunSoPhuc(sp1);
}


template<typename T, typename X>
SoPhuc2<T, X> SoPhuc2<T, X>::operator+ (SoPhuc2<T, X> sp) {
    SoPhuc2<T, X> sum;
    sum.a = this->a + sp.a;
    sum.b = this->b + sp.b;
    return sum;
}

template<typename T, typename X>
void SoPhuc2<T, X>::SoPhucBangSoPhucChoTruoc(SoPhuc2<T, X> *arr, X n) {
    X count = 0;
    T ans = (T)sqrt(pow(3, 2) + pow(4, 2));
    for(X i = 0; i < n; i++) {
        if (arr->TinhMuDunSoPhuc(arr[i]) == ans) {
            count++;
        }
    }
    cout << "\tSO LUONG SO PHUC BANG 3 + 4i:  " << count << endl;
}

template<typename T, typename X> 
void SoPhuc2<T, X>::SoPhucLonNhat(SoPhuc2<T, X> *arr, X n) {
    T Max = arr->TinhMuDunSoPhuc(arr[0]);
    X count = 0;
    for (X i = 0; i < n; i++) {
        if (arr->TinhMuDunSoPhuc(arr[i]) > Max) {
            Max = arr->TinhMuDunSoPhuc(arr[i]);
            count = i;
        }
    }
    cout << "\n\tSO PHUC CO MODUN LON NHAT: " << arr[count] << endl;
}


template<typename T, typename X> 
void SoPhuc2<T, X>::NhapThongTinSoPhuc(SoPhuc2<T, X> *arr, X n) {
    for (X i = 0; i < n; i++)
    {
        cout << "\nNhap vao so phuc thu " << i + 1 << ": ";
        cin >> arr[i];
    }
}

template<typename T, typename X> 
void SoPhuc2<T, X>::InThongTinSoPhucVuaNhap(SoPhuc2<T, X> *arr, X n) {
    cout << "\n\tDANH SACH SO PHUC VUA NHAP: " << endl;
    for (X i = 0; i < n; i++)
    {
        cout << "\t\tSo Phuc " << i + 1 << ": " << arr[i];
    }
}

template<typename T, typename X> 
void SoPhuc2<T, X>::InDanhSachTongMudun(SoPhuc2<T, X> *arr, X n) {
    cout << "\n\tDANH SACH TONG MUDUN SO PHUC: " << endl;
    for (X i = 0; i < n; i++)
    {
        cout << "\t\tMudun " << i + 1 << ": " << arr->TinhMuDunSoPhuc(arr[i]) << endl;
    }
}


int main()
{
    system("cls");
    SoPhuc2<float, int> sp;
    int n; cout << "\nNhap vao so N so phuc: "; cin >> n;
    SoPhuc2<float, int> *arr = new SoPhuc2<float, int>[n];

    sp.NhapThongTinSoPhuc(arr, n);
    cout << "\n___________________________________________\n";
    sp.InThongTinSoPhucVuaNhap(arr, n);
    sp.InDanhSachTongMudun(arr, n);
    sp.SoPhucLonNhat(arr, n);
    sp.SoPhucBangSoPhucChoTruoc(arr, n);
    cout << "\n___________________________________________\n";

    cin.get();
    return 0;
}
