
// Bài 32: Hoàng Anh Tiến

#include <iostream>
#include <vector>
using namespace std;

class nguoi
{
private:
    string ten;
    int tuoi;
    string nghenghiep;

public:
    void nhap()
    {
        cin.ignore();
        cout << "\nnhap ten: ";
        getline(cin, ten);
        cout << "\nnhap nghenghiep: ";
        getline(cin, nghenghiep);
        cout << "\nnhap tuoi: ";
        cin >> tuoi;
    }
    void xuat()
    {
        cout << "\nten: " << ten;
        cout << "\nnghe nghiep: " << nghenghiep;
        cout << "\ntuoi: " << tuoi;
    }
};

class hodan
{
private:
    int songuoi;
    int sonha;
    vector<nguoi> a;

public:
    void nhaphd()
    {
        cin.ignore();
        cout << "\nnhap so nguoi: ";
        cin >> songuoi;
        cout << "\nnhap so nha: ";
        cin >> sonha;
    }
    void xuathd()
    {
        cout << "\nso nguoi: " << songuoi;
        cout << "\nso nha: " << sonha;
    }
};

class khupho
{
private:
    int sohodan;
    vector<hodan> b;

public:
    void nhapkp()
    {
        cout << "\nnhap sohodan: ";
        cin >> sohodan;
    }
    void xuatkp()
    {
        cout << "\nsohodan: " << sohodan;
    }
};

int main()
{
    int n;
    cout << "\n nhap n: ";
    cin >> n;
    vector<nguoi> duyet;
    vector<hodan> an;
    vector<khupho> nguyen;
    for (int i = 0; i < n; i++)
    {
        nguoi x;
        hodan y;
        khupho z;
        cout << "\n nhap " << i + 1 << ": " << endl;
        x.nhap();
        y.nhaphd();
        z.nhapkp();
        duyet.push_back(x);
        an.push_back(y);
        nguyen.push_back(z);
    }
    cout << "ten"
         << "\t <<"
            "tuoi"
         << "\t"
         << "nghenghiep"
         << "\t"
         << "songuoi"
         << "\t"
         << "sonha"
         << "\t"
         << "sohodan";
}
