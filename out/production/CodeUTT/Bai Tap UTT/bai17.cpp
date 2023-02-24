
/*
    Câu 17: Viết chương trình thực hiện các yêu cầu sau:
    1.	Khai báo lớp điểm với các thuộc tính: tọa độ x, tọa độ y.
    Khai báo lớp tam giác có thuộc tính 3 đỉnh là kiểu đối tượng điểm
    (lớp tam giác được gọi là lớp bao của lớp điểm) và thêm các thuộc tính: độ dài 3 cạnh.

    2.	Xây dựng các phương thức: nhập, xuất, tính khoảng cách 2 điểm (dùng hàm bạn),
    áp dụng tính độ dài 3 cạnh của tam giác; nhập, xuất 3 đỉnh của tam giác.

    3.	Nhập vào 1 tam giác. Kiểm tra tính chất của tam giác (thường, đều, vuông, cân, vuông cân).
    In kết quả ra màn hình.

*/

#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
class Diem
{
private:
    int x;
    int y;

public:
    Diem<T>() {}
    Diem<T>(T x, T y) : x(x), y(y) {}

    void nhap();
    void xuat();

    friend float distance(Diem<T> A, Diem<T> B)
    {
        return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
    }
};

template <typename T, typename X>
class TamGiac
{
private:
    X ab, bc, ac;
    Diem<T> A, B, C;

public:
    TamGiac<T, X>() {}
    TamGiac<T, X>(X ab, X bc, X ac, T x1, T y1, T x2, T y2, T x3, T y3)
        : A(x1, y1), B(x2, y2), C(x3, y3)
    {
        this->ab = ab;
        this->bc = bc;
        this->ac = ac;
    }

    void nhap();
    void xuat();

    X getAB() { return ab; }
    X getBC() { return bc; }
    X getAC() { return ac; }
};

template <typename T>
void Diem<T>::nhap()
{
    cout << "\tNhap x: ";
    cin >> x;
    cout << "\tNhap y: ";
    cin >> y;
    cout << endl;
}

template <typename T>
void Diem<T>::xuat()
{
    cout << "(" << x << "," << y << ")" << endl;
}

template <typename T, typename X>
void TamGiac<T, X>::nhap()
{
    cout << "Nhap Vao Toa Do Diem A(...) \n";
    A.nhap();
    cout << "Nhap Vao Toa Do Diem B(...) \n";
    B.nhap();
    cout << "Nhap Vao Toa Do Diem C(...) \n";
    C.nhap();
    ab = distance(A, B);
    bc = distance(B, C);
    ac = distance(A, C);
}

template <typename T, typename X>
void TamGiac<T, X>::xuat()
{
    cout << "Toa Do Dinh A la: ";
    cout << "A";
    A.xuat();
    cout << "Toa Do Dinh B la: ";
    cout << "B";
    B.xuat();
    cout << "Toa Do Dinh C la: ";
    cout << "C";
    C.xuat();
}

template <typename T, typename X>
void ChecTamGiac(TamGiac<T, X> check)
{
    float a = check.getAB();
    float b = check.getBC();
    float c = check.getAC();
    if (a < b + c && b < a + c && c < a + b)
    {
        if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b)
            cout << "\n=> Day La Tam Giac Vuong !\n\n";
        else if (a == b && b == c)
            cout << "\n=> Day La Tam Giac Deu !\n\n";
        else if (a == b || a == c || b == c)
            cout << "\n=> Day La Tam Giac Can !\n\n";
        else if (a * a > b * b + c * c || b * b > a * a + c * c || c * c > a * a + b * b)
            cout << "\n=> Day La Tam Giac Tu !\n\n";
        else
            cout << "\n=> Day La Tam Giac Nhon !\n\n";
    }
    else
    {
        cout << "\n=> Ba Canh A, B, C Khong Phai La 3 Canh Cua 1 Tam Giac !!!\n\n";
    }
}

int main()
{
    system("cls");
    TamGiac<int, float> tg;
    tg.nhap();
    tg.xuat();
    ChecTamGiac(tg);
    cin.get();
    return 0;
}
