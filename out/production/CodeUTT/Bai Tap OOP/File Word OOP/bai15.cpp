
/*
    Câu 15: Viết chương trình thực hiện các yêu cầu sau:
    1.	Khai báo lớp cán bộ với các thuộc tính: mã cán bộ, mã đơn vị, họ tên, năm sinh.
    Khai báo lớp lương kế thừa từ lớp cán bộ và thêm các thuộc tính: phụ cấp, hệ số lương, bảo hiểm.
    2.	Xây dựng các phương thức: nhập, xuất cho các đối tượng cán bộ, lương.
    Nhập vào n cán bộ. Tính lương cho cán bộ theo công thức: 
    lương = hệ số lương * 290.000 + phụ cấp – bảo hiểm. In kết quả ra màn hình

*/

#include<bits/stdc++.h>
using namespace std;

class CanBo {
    public:
        string macb, madv, hoten;
        int namsinh;
    public:
        CanBo() {};
        CanBo(string macb, string madv, string hoten, int namsinh) 
        : macb(macb), madv(madv), hoten(hoten), namsinh(namsinh) {};
        ~CanBo() {};

};

class Luong : public CanBo {
    public:
        int phucap, hesoluong, baohiem;

    public:
        Luong() {};
        Luong(string macb, string madv, string hoten, int namsinh, int phucap, int hesoluong, int baohiem)
        : CanBo(macb, madv, hoten, namsinh), phucap(phucap), hesoluong(hesoluong), baohiem(baohiem) {};

        friend istream& operator >> (istream&, Luong&);
        friend ostream& operator >> (ostream&, Luong);

};


istream& operator >> (istream& input, Luong &l) {
    cout << "\nNhap vao Ho Ten: "; getline(input, l.hoten);
    cout << "Nhap vao Ma CB: "; getline(input, l.macb);
    cout << "Nhap vao Ma DV: "; getline(input, l.madv);
    cout << "Nhap vao NamSinh: "; input >> l.namsinh;
    cout << "Nhap vao Phu Cap: "; input >> l.phucap;
    cout << "Nhao vao He So Luong: "; input >> l.hesoluong;
    cout << "Nhap vao Bao Hiem: "; input >> l.baohiem;
    return input;
}


ostream& operator << (ostream& output, Luong l) {
    output << "\nHo Ten: " << l.hoten << endl;
    output << "Ma CB: " << l.macb << endl;
    output << "Ma DV: " << l.madv << endl;
    output << "Phu Cap: " << l.phucap << endl;
    output << "He So Luong: " << l.hesoluong << endl;
    output << "Bao Hiem: " << l.baohiem << endl;

    output << "LuonG Can Bo: " << l.hesoluong * 290000 + l.phucap - l.baohiem << endl;

    return output;
}


int main() {
    system("cls");
    int n; cout << "\nNHAP VAO N CAN BO: "; cin >> n;
    Luong *arr = new Luong[n];
    for(int i = 0; i < n; i++) {
        cin.ignore();
        cout << "\n\tNHAP VAO CAN BO THU " << i + 1 << ": " << endl;
        cin >> arr[i];
    }
    cout << "\n\t===> DANH SACH THONG TIN CAN BO <===";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}
