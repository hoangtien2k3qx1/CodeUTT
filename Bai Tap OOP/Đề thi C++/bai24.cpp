/*
    Câu 24: 
    Viết chương trình thực hiện các yêu cầu sau:
    1.	Khai báo lớp PS1 cho các đối tượng là phân số với các thuộc tính: tử số, mẫu số.
    Xây dựng phương thức nhập phân số (mẫu số khác 0), in phân số, tối giản phân số.
    2.	Xây dựng lớp PS2 kế thừa từ lớp PS1 và bổ sung:
    Nạp chồng các toán tử: = (gán), > (lớn hơn), + (cộng).
    3.	Viết chương trình chính ứng dụng lớp PS2 để nhập một danh sách các đối tượng là 
    các phân số (tối đa 10 phần tử). Tìm phân số có giá trị lớn nhất, tính tổng các phân 
    số trong danh sách có giá trị lớn hơn 1/4.

*/

#include <bits/stdc++.h>
using namespace std;

class PhanSo1
{
protected:
    int tuso, mauso;

public:
    PhanSo1(int tuso, int mauso) : tuso(tuso), mauso(mauso){};
    PhanSo1() : tuso(0), mauso(1){};
    ~PhanSo1(){};
};

class PhanSo : public PhanSo1
{
public:
    PhanSo() : PhanSo1(tuso, mauso) {}
    PhanSo(int, int);
    ~PhanSo(){};

    friend istream &operator>>(istream &, PhanSo &);
    friend ostream &operator<<(ostream &, PhanSo);

    PhanSo rutgon(PhanSo &);

    // friend PhanSo operator= (PhanSo, PhanSo);
    friend PhanSo operator<(PhanSo &, PhanSo &);
    friend PhanSo operator+(PhanSo &, PhanSo &);
    friend PhanSo operator+(PhanSo);

    PhanSo TongTatCaPhanSoNhoHon1Phan4(const PhanSo *, const int);
    PhanSo PhanSoGiaTriLonNhat(PhanSo *&, const int); // Functuon protertype
};

PhanSo::PhanSo(int tuso, int mauso)
{
    this->tuso = tuso;
    this->mauso = mauso;
}

istream &operator>>(istream &input, PhanSo &ps)
{
    cout << "\nNhap tuso: ";
    input >> ps.tuso;
    cout << "Nhap mauso: ";
    input >> ps.mauso;
    return input;
}

ostream &operator<<(ostream &output, PhanSo ps)
{
    output << ps.tuso << "/" << ps.mauso << endl;
    return output;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

PhanSo PhanSo::rutgon(PhanSo &ps)
{
    int g = gcd(ps.tuso, ps.mauso);
    ps.tuso /= g;
    ps.mauso /= g;
    return ps;
}

PhanSo operator+(PhanSo &ps1, PhanSo &ps2)
{
    PhanSo tong(1, 1);
    tong.tuso = ps1.tuso * ps2.mauso + ps2.tuso * ps1.mauso;
    tong.mauso = ps1.mauso * ps2.mauso;
    tong.rutgon(tong);
    return tong;
}

PhanSo PhanSo::TongTatCaPhanSoNhoHon1Phan4(const PhanSo *arr, const int n)
{
    PhanSo sum(0, 1);
    for (int i = 0; i < n; i++)
    {
        float ans = (float)arr[i].tuso / arr[i].mauso;
        if (ans < (float)1/4)
        {
            sum.tuso = sum.tuso * arr[i].mauso + sum.mauso * arr[i].tuso;
            sum.mauso = sum.mauso * arr[i].mauso;
        }
    }
    sum.rutgon(sum);
    return sum;
}

PhanSo PhanSo::PhanSoGiaTriLonNhat(PhanSo *&arr, const int n)
{
    float Max = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        float ans = (float)arr[i].tuso / arr[i].mauso;
        if (ans > Max)
        {
            Max = ans;
            count = i;
        }
    }
    return arr[count];
}

int main()
{
    system("cls");
    int n;
    cout << "\nNHAP VAO N PHAN SO: ";
    cin >> n;
    PhanSo *arr = new PhanSo[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nNHAP VAO PHAN SO THU " << i + 1;
        cin >> arr[i];
    }

    cout << endl
         << setw(50) << "===> DANH SACH CAC PHAN SO VUA NHAP DA RUT GON <===" << endl;
    for(int i = 0; i < n; i++) {
        arr->rutgon(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << setw(30) << "Phan So " << i + 1 << ": " << arr[i];
    }
    cout << endl
         << setw(40) << "=> Tong Tat Ca Ca Phan So Nho Hon 1/2 La: " << arr->TongTatCaPhanSoNhoHon1Phan4(arr, n) << endl;
    cout << setw(40) << "=> Phan So Co Gia Tri Lon Nhat La: " << arr->PhanSoGiaTriLonNhat(arr, n) << endl;

    delete[] arr;
    cin.get();
    return 0;
}