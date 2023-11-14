/*
    Bài 22: Viết chương trình thực hiện các yêu cầu sau:
    1.	Khai báo lớp SP1 cho các đối tượng là số phức với các thuộc tính: phần thực, phần ảo.
    Xây dựng hàm tạo, phương thức nhập số phức, in số phức, tính module số phức.
    2.	Xây dựng lớp SP2 kế thừa từ lớp SP1 và bổ sung:
    Nạp chồng các toán tử = (gán), < (so sánh nhỏ hơn theo module)
    3.	Viết chương trình chính ứng dụng lớp SP2 để nhập một danh sách các đối tượng là các
    số phức (tối đa 10 phần tử). Tìm số phức có giá trị lớn nhất, nhỏ nhất.
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
class SoPhuc2 : public SoPhuc<T> 
{
public:
    SoPhuc2<T, X>() {};
    SoPhuc2<T, X>(T a, T b) : SoPhuc<T>(a, b){};
    ~SoPhuc2<T, X>(){};

    bool operator=(SoPhuc2<T, X> &);
    bool operator<(SoPhuc2<T, X> &);
    float TinhMuDunSoPhuc(SoPhuc2<T, X>);
    int SoPhucLonNhat(SoPhuc2<T, X> *, X);
    int SoPhucNhoNhat(SoPhuc2<T, X> *, X);

    void NhapThongTinSoPhuc(SoPhuc2<T, X> *, X);
    void InThongTinSoPhucVuaNhap(SoPhuc2<T, X> *, X);
    void InDanhSachTongMudun(SoPhuc2<T, X> *, X);
    void ThongTinSoPhucCoMudunLonNhat(SoPhuc2<T, X> *, X);
    void ThongTinSoPhucCoMudunNhoNhat(SoPhuc2<T, X> *, X);
};

template<typename T>
istream &operator >> (istream &input, SoPhuc<T> &sp)
{
    cout << "\n\tPhan thuc a: ";
    input >> sp.a;
    cout << "\tPhan ao b: ";
    input >> sp.b;
    return input;
}

template<typename T>
ostream &operator << (ostream &output, SoPhuc<T> sp)
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

template<typename T, typename X> float SoPhuc2<T, X>::TinhMuDunSoPhuc(SoPhuc2<T, X> sp)
{
    sp.a = abs(sp.a);
    sp.b = abs(sp.b);
    T result = (T)(pow(sp.a, 2) + pow(sp.b, 2));
    return (T)sqrt(result);
}

template<typename T, typename X> bool SoPhuc2<T, X>::operator=(SoPhuc2<T, X> &sp1)
{
    return this->TinhMuDunSoPhuc(sp1) == sp1.TinhMuDunSoPhuc(sp1);
}

template<typename T, typename X> bool SoPhuc2<T, X>::operator<(SoPhuc2<T, X> &sp1)
{
    return (T)sqrt(pow(this->a, 2) + pow(this->b, 2)) < (T)sqrt(pow(sp1.a, 2) + pow(sp1.b, 2));
}

template<typename T, typename X> int SoPhuc2<T, X>::SoPhucLonNhat(SoPhuc2<T, X> *arr, X n)
{
    T Max = arr->TinhMuDunSoPhuc(arr[0]);
    X count = 0;
    for (X i = 0; i < n; i++)
    {
        if (arr->TinhMuDunSoPhuc(arr[i]) > Max)
        {
            Max = arr->TinhMuDunSoPhuc(arr[i]);
            count = i;
        }
    }
    return count;
}

template<typename T, typename X> int SoPhuc2<T, X>::SoPhucNhoNhat(SoPhuc2<T, X> *arr, X n)
{
    T Min = arr->TinhMuDunSoPhuc(arr[0]);
    X count = 0;
    for (X i = 0; i < n; i++)
    {
        if (arr->TinhMuDunSoPhuc(arr[i]) < Min)
        {
            Min = arr->TinhMuDunSoPhuc(arr[i]);
            count = i;
        }
    }
    return count;
}

template<typename T, typename X> void SoPhuc2<T, X>::NhapThongTinSoPhuc(SoPhuc2<T, X> *arr, X n) {
    for (X i = 0; i < n; i++)
    {
        cout << "\nNhap vao so phuc thu " << i + 1 << ": ";
        cin >> arr[i];
    }
}

template<typename T, typename X> void SoPhuc2<T, X>::InThongTinSoPhucVuaNhap(SoPhuc2<T, X> *arr, X n) {
    cout << "\n\tDANH SACH SO PHUC VUA NHAP: " << endl;
    for (X i = 0; i < n; i++)
    {
        cout << "\t\tSo Phuc " << i + 1 << ": " << arr[i];
    }
}

template<typename T, typename X> void SoPhuc2<T, X>::InDanhSachTongMudun(SoPhuc2<T, X> *arr, X n) {
    cout << "\n\tDANH SACH TONG MUDUN SO PHUC: " << endl;
    for (X i = 0; i < n; i++)
    {
        cout << "\t\tMudun " << i + 1 << ": " << arr->TinhMuDunSoPhuc(arr[i]) << endl;
    }
}

template<typename T, typename X> void SoPhuc2<T, X>::ThongTinSoPhucCoMudunLonNhat(SoPhuc2<T, X> *arr, X n) {
    X i = arr->SoPhucLonNhat(arr, n);
    cout << "\n\tSO PHUC CO MODUN LON NHAT: " << arr[i] << endl;
}

template<typename T, typename X> void SoPhuc2<T, X>::ThongTinSoPhucCoMudunNhoNhat(SoPhuc2<T, X> *arr, X n) {
    X j = arr->SoPhucNhoNhat(arr, n);
    cout << "\tSO PHUC CO MODUN NHO NHAT: " << arr[j] << endl;
}


int main()
{
    system("cls");
    SoPhuc2<float, int> sp;
    int n; cout << "\nNhap vao so N so phuc: "; cin >> n;
    SoPhuc2<float, int> *arr = new SoPhuc2<float, int>[n];

    sp.NhapThongTinSoPhuc(arr, n);
    sp.InThongTinSoPhucVuaNhap(arr, n);
    sp.InDanhSachTongMudun(arr, n);
    sp.ThongTinSoPhucCoMudunLonNhat(arr, n);
    sp.ThongTinSoPhucCoMudunNhoNhat(arr, n);
   
    cin.get();
    return 0;
}
