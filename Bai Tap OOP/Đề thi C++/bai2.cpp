
/*
    Bài 2: Viết chương trình thực hiện các yêu cầu sau:
        1.	Khai báo lớp đa thức với các thuộc tính: bậc đa thức, các hệ số tương ứng.
        2.	Xây dựng các phương thức: nhập, xuất một đối tượng đa thức.
        3.	Xây dựng phương thức cộng, trừ hai đa thức và in kết quả ra màn hình.
*/

#include<bits/stdc++.h>
using namespace std;

// !CÁCH 1:
// template<typename T>
// class DaThuc;
// template<typename T>
// istream &operator >> (istream &, DaThuc<T> &);
// template<typename T>
// ostream &operator << (ostream &, const DaThuc<T> &);

template <typename T> 
class DaThuc {
private:
    T n;        // bac cua da thuc
    T *a;       // mang chua he so da thuc

public:

    DaThuc() : n(0), a(NULL) {}

    DaThuc(T n) : n(n) {
        a = new T[n];
    }
    ~DaThuc() {
        n = 0;
        delete a;
    }

    // !CÁCH 1:
    // friend istream &operator >> <T>(istream &, DaThuc<T> &);
    // friend ostream &operator << <T>(ostream &, const DaThuc<T> &);

    // !CÁCH 2:
    template<typename U> friend istream &operator >> (istream &, DaThuc<U> &);
    template<typename U> friend ostream &operator << (ostream &, const DaThuc<U> &);
    DaThuc<T> operator+ (const DaThuc<T> &);
    DaThuc<T> operator- (const DaThuc<T> &);
};

template<typename T> istream &operator>>(istream &is, DaThuc<T> &d) {
    cout << "\nBac da thuc n = ";
    is >> d.n;
    d.a = new T[d.n + 1];
    for (T i = 0; i <= d.n; i++) {
        cout << "x^" << i << " = "; is >> d.a[i];
    }
    return is;
}

template<typename T> ostream &operator<<(ostream &os, const DaThuc<T> &d) {
    for (T i = 0; i <= d.n; i++) {   
        if (!i) 
            os << d.a[i];
        else if (i == 1) 
            os << d.a[i] << "x";
        else 
            os << d.a[i] << "x^" << i;
        if (i != d.n && d.a[i + 1] >= 0) {
            os << " + ";
        } else { 
            os << " ";
        }
    }
    return os;
}

template<typename T> DaThuc<T> DaThuc<T>::operator+ (const DaThuc<T> &d) {
    T Max = (n > d.n) ? n : d.n;        // tìm ra bậc lớn nhất của đa thức thứ nhất.
    T Min = (n < d.n) ? n : d.n;        // tìm ra bậc bé nhất của đa thức thứ hai.
    DaThuc<T> sum = DaThuc<T>(Max);     // gọi constructor có tham số để cấp phát động cho nó N phần tử.
    for (T i = 0; i <= Min; i++) {
        sum.a[i] = a[i] + d.a[i];
    }
    for (T i = Min + 1; i <= Max; i++) {
        sum.a[i] = (n == Max) ? a[i] : d.a[i];
    }
    return sum;
}

template<typename T> DaThuc<T> DaThuc<T>::operator- (const DaThuc<T> &d) {
    T Max = (n > d.n) ? n : d.n;    // tìm ra số mũ lớn nhất trong hai đa thức.
    T Min = (n < d.n) ? n : d.n;    // tìm ra số mũ bé nhất trong hai đa thức trên.
    DaThuc<T> sub = DaThuc<T>(Max); // gọi constructor có tham số để cấp phát động cho nó N phần tử.
    for (T i = 0; i <= Min; i++) {
        sub.a[i] = a[i] - d.a[i];
    }
    for (T i = Min + 1; i <= Max; i++) {
        sub.a[i] = (n == Max) ? a[i] : (-1)*d.a[i];
    }
    return sub;
}

int main() {
    system("cls");

    DaThuc<int> a, b;
    cout << "\nNhap da thuc a: "; cin >> a;
    cout << "\nNhap da thuc b: "; cin >> b;

    cout << "\n\ta: " << a;
    cout << "\n\tb: " << b;

    DaThuc<int> sum = a + b; cout << "\n\ta + b: " << sum;
    DaThuc<int> sub = a - b; cout << "\n\ta - b: " << sub;
    
    cin.get();
    return 0;
}
