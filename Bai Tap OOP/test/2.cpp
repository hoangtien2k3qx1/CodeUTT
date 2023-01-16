/*
    Bài 2: Viết chương trình thực hiện các yêu cầu sau:
        1.	Khai báo lớp đa thức với các thuộc tính: bậc đa thức, các hệ số tương ứng.
        2.	Xây dựng các phương thức: nhập, xuất một đối tượng đa thức.
        3.	Xây dựng phương thức cộng, trừ hai đa thức và in kết quả ra màn hình.
*/

#include<bits/stdc++.h>
using namespace std;

class dathuc {
private:
    int n;
    int *a;

public:
    dathuc() {
        n = 0;
        a = NULL;
    }
    dathuc(int n) {
        this->n = n;
        a = new int[n];
    }
    ~dathuc() {}

    void nhap(dathuc &d);
    void xuat(dathuc &d);
    dathuc operator+ (dathuc &d);
    dathuc operator- (dathuc &d);

};

void dathuc::nhap(dathuc &d) {
    cout << "Nhap vao bac cua da thuc: "; cin >> d.n;
    d.a = new int[d.n + 1];
    for(int i = 0; i <= d.n; i++) {
        cout << "\tx^" << i << "= "; 
        cin >> d.a[i];
    }
}

void dathuc::xuat(dathuc &d) {
    for(int i = 0; i <= d.n; i++) {
        cout << d.a[i] << "x^" << i;
        if (i != d.n) {
            cout << " + ";
        }
    }
}

dathuc dathuc::operator+ (dathuc &d) {
    int Max = (n > d.n) ? n : d.n;
    int Min = (n < d.n) ? n : d.n;

    dathuc sum = dathuc(Max);

    for(int i = 0; i <= Min; i++) {
        sum.a[i] = a[i] + d.a[i];
    }  
    for(int i = Min + 1; i <= Max; i++) {
        sum.a[i] = (n == Max) ? a[i] : d.a[i];
    }

    return sum;
}

dathuc dathuc::operator- (dathuc &d) {
    int Max = (n > d.n) ? n : d.n;
    int Min = (n < d.n) ? n : d.n;

    dathuc sub = dathuc(Max);

    for(int i = 0; i <= Min; i++) {
        sub.a[i] = a[i] - d.a[i];
    }
    for(int i = Min + 1; i <= Max; i++) {
        sub.a[i] = (n == Max) ? a[i] : (-1)*d.a[i];
    }
    return sub;
}


int main() {
    system("cls");

    dathuc a, b;

    a.nhap(a);
    b.nhap(b);


    cout << "\na: "; a.xuat(a);
    cout << "\nb: "; b.xuat(b);

    dathuc sum = a + b;
    cout << "\nsum: "; sum.xuat(sum);
    dathuc sub = a - b;
    cout << "\nsub: "; sub.xuat(sub);


    return 0;
}