
/*
    Câu 11: Viết chương trình thực hiện các yêu cầu sau:
    1.	Khai báo lớp nhân sự với các thuộc tính: mã nhân viên, họ tên, năm sinh.
    Khai báo lớp công nhân kế thừa từ lớp nhân sự và thêm thuộc tính: ngày công.
    2.	Xây dựng các phương thức: nhập, xuất cho các đối tượng nhân sự, công nhân.
    Nhập vào n công nhân. Thực hiện tính tiền thưởng cho công nhân 100.000 với mỗi 
    ngày công làm thêm nếu ngày công lớn hơn 26. In ra màn hình danh sách các công 
    nhân được thưởng và số tiền thưởng tương ứng.

*/

#include<bits/stdc++.h>
using namespace std;

class NhanSu {
    protected:
        string manv, hoten;
        int namsinh;

    public:
        NhanSu() {};
        NhanSu(string manv, string hoten, int namsinh) : manv(manv), hoten(hoten), namsinh(namsinh) {};
        ~NhanSu() {};
};

class CongNhan : public NhanSu {
    private:
        int ngaycong;
        int tienthuong;
    public:
        CongNhan() {};
        CongNhan(string manv, string hoten, int namsinh, int ngaycong)
        : NhanSu(manv, hoten, namsinh), ngaycong(ngaycong) {};
        ~CongNhan() {};

        friend istream& operator >> (istream&, CongNhan&);
        friend ostream& operator << (ostream&, CongNhan);
        void DanhSachCongNhanDuocThuong(CongNhan*, int);
};

istream& operator >> (istream& input, CongNhan &cn) {
    cout << "\nNhap vao manv: "; getline(input, cn.manv);
    cout << "Nhap vao hoten: "; getline(input, cn.hoten);
    cout << "Nhap vao namsinh: "; input >> cn.namsinh;
    cout << "Nhap vao ngaycong: "; input >> cn.ngaycong;
    return input;
}

ostream& operator << (ostream& output, CongNhan cn) {
    output << "\nManv: " << cn.manv << endl;
    output << "Hoten: " << cn.hoten << endl;
    output << "Namsinh: " << cn.namsinh << endl;
    output << "Ngaycong: " << cn.ngaycong << endl;
    output << "TienThuong: " << (cn.ngaycong - 26) * 100000 << endl;
    return output;
}

void CongNhan::DanhSachCongNhanDuocThuong(CongNhan *arr, int n) {
    for(int i = 0; i < n; i++) {
        if (arr[i].ngaycong > 26) {
            cout << arr[i] << endl;
        }
    }
}

int main() {
    system("cls");
    int n; cout << "NHAP VAO N CONG NHAN: "; cin >> n;
    CongNhan *arr = new CongNhan[n];
    cout << "\n\t===> NHAP VAO THONG TIN CONG NHAN <===";
    for(int i = 0; i < n; i++) {
        cin.ignore();
        cin >> arr[i];
    }
    cout << "\n\t===> DANH SACH CONG NHAN DUOC THUONG THEM <===";
    arr->DanhSachCongNhanDuocThuong(arr, n);
    delete arr;
    return 0;
}
