/*
    Câu 3: Viết chương trình thực hiện các yêu cầu sau:
        1.	Khai báo lớp date với các thuộc tính: ngày, tháng, năm.
        Xây dựng hàm tạo không đối, hàm tạo có đối, hàm hủy một đối tượng date.
        2.	Xây dựng các phương thức: nhập, xuất, chuẩn hóa một đối tượng date.
        Định nghĩa toán từ ++,-- để tăng, giảm một ngày. Thực hiện tăng, giảm một ngày 
        và in kết quả ra màn hình (kết quả phải được chuẩn hóa dưới dạng dd-mm-yyyy).
*/

#include<bits/stdc++.h>
#include<string>
using namespace std;

class Lop {
private:
    int ngay, thang, nam;

public:
    Lop() {}
    Lop(int ngay, int thang, int nam) {
        this->ngay = ngay;
        this->thang = thang;
        this->nam = nam;
    }
    ~Lop() {}

    void Nhap();
    void XuatNgayTruocDo();
    void XuatNgaySauDo();

};

void Lop::Nhap() {
    do {
        cout << "\nNhap vao ngay: "; cin >> ngay;
        cout << "Nhap vao thang: "; cin >> thang;
        cout << "Nhap vao nam: "; cin >> nam;
        if (ngay < 0 || ngay > 31 || thang < 0 || thang > 12 || nam < 0) {
            cout << "\nLoi roi, Nhap Lai!!!" << endl;
        }
    } while(ngay < 0 || ngay > 31 || thang < 0 || thang > 12 || nam < 0);
}

int TimNgayTrongThang(int thang, int nam) {
    switch(thang) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
            return 31; break;
        case 4: case 6: case 9: case 11: 
            return 30; break;
        default:
            return (nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0) ? 29 : 28;
    }
}

void Lop::XuatNgayTruocDo() {
    int xngay = ngay, xthang = thang, xnam = nam;
    if (xngay < TimNgayTrongThang(thang, nam)) {
        xngay++;
    } else if (xthang < 12) {
        xngay = 1;
        xthang++;
    } else {
        xngay = xthang = 1;
        xnam++;
    }

    string Xngay = to_string(xngay), Xthang = to_string(xthang);
    if (xngay < 10) {
        Xngay = "0" + Xngay;
    }
    if (xthang < 10) {
        Xthang = "0" + Xthang;
    }
    cout << "\nNgay Truoc Do: " << Xngay << "-" << Xthang << "-" << xnam << endl;
}

void Lop::XuatNgaySauDo() {
    int xngay = ngay, xthang = thang, xnam = nam;
    if (xngay == 1 && xthang == 1) {
        xngay = 31;
        xthang = 12;
        xnam--;
    } else if (xngay <= TimNgayTrongThang(thang, nam)) {
        if (xngay == 1) {
            xngay = TimNgayTrongThang(xthang - 1, nam) + 1;
            xthang--;
        }
        xngay--;
    }

    string Xngay = to_string(xngay), Xthang = to_string(xthang);
    if (xngay < 10) {
        Xngay = "0" + Xngay;
    }
    if (xthang < 10) {
        Xthang = "0" + Xthang;
    }
    cout << "\nNgay Truoc Do: " << Xngay << "-" << Xthang << "-" << xnam << endl;
}



int main() {
    system("cls");

    Lop l;
    l.Nhap();
    l.XuatNgayTruocDo();
    l.XuatNgaySauDo();

    return 0;
}