
/*
    Câu 14: Viết chương trình thực hiện các yêu cầu sau:
    1.	Khai báo lớp người với các thuộc tính: họ tên, năm sinh.
    Khai báo lớp giảng viên kế thừa từ lớp người và thêm các thuộc tính: 
    bộ môn công tác, môn đang giảng dạy.
    2.	Xây dựng các phương thức: nhập, xuất cho các đối tượng người, giảng viên.
    3.	Nhập vào n giảng  viên. Sắp xếp lại và in ra màn hình danh sách giảng viên 
    theo từng bộ môn công tác.

*/

#include<bits/stdc++.h>
using namespace std;

class Nguoi {
    protected:
        string hoten;
        int namsinh;
    public:
        Nguoi() {};
        Nguoi(string hoten, int namsinh) : hoten(hoten), namsinh(namsinh) {};
        ~Nguoi() {};

};

class GiangVien : public Nguoi {
    private:
        string BMCT, MGD;
    public:

        friend istream& operator >> (istream&, GiangVien&);
        friend ostream& operator << (ostream&, GiangVien);

};

istream& operator >> (istream& input, GiangVien &gv) {
    cout << "\nNhap vao Ho Ten: "; getline(input, gv.hoten);
    cout << "Nhap vao Bo Mon Cong Tac: "; getline(input, gv.BMCT);
    cout << "Nhap vao Mon Giang Day: "; getline(input, gv.MGD);
    cout << "Nhap vao Nam Sinh: "; input >> gv.namsinh;
    return input;
}

ostream& operator << (ostream& output, GiangVien gv) {
    output << "Ho Ten: " << gv.hoten << endl;
    output << "Bo Mon Cong Tac: " << gv.BMCT << endl;
    output << "Mon Giang Day: " << gv.MGD << endl;
    output << "Nam Sinh: " << gv.namsinh << endl;
    return output;
}

int main() {
    system("cls");

    int n; cout << "Nhap vao n Giang Vien: "; cin >> n;
    GiangVien *arr = new GiangVien[n];
    for(int i = 0; i < n; i++) {
        cout << "Nhap vao Giang Vien Thu " << i + 1 << ": " << endl;
        cin.ignore();
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++) {
        cout << "\nGiang Vien Thu " << i + 1 << endl;
        cout << arr[i];
    }

    return 0;
}