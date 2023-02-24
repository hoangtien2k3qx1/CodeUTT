
/*
    Câu 12: Viết chương trình thực hiện các yêu cầu sau:
    1.	Khai báo lớp môn học với các thuộc tính: tên môn học, điểm chuyên cần (CC), điểm kiểm tra (KT), điểm thi (DT).
    Khai báo lớp sinh viên kế thừa từ lớp môn học và thêm các thuộc tính: họ tên, lớp, mã sinh viên.
    2.	Xây dựng các phương thức: nhập, xuất, tính điểm học phần cho một sinh viên.
    3.	Nhập vào n sinh viên. In ra màn hình thông tin các sinh viên bị cấm thi 
    (điểm chuyên cần dưới 5 hoặc điểm kiểm tra bằng 0).

*/

#include<bits/stdc++.h>
using namespace std;

class MonHoc {
    protected:
        string tenmh;
        int diemcc, diemkt, diemthi;
    public:
        MonHoc() {};
        MonHoc(string tenmh, int diemcc, int diemkt, int diemthi) : diemcc(diemcc), diemkt(diemkt), diemthi(diemthi) {};
        ~MonHoc() {};

};

class SinhVien : public MonHoc {
    private:
        string hoten, masv;
    public:
        SinhVien() {};
        SinhVien(string tenmh, int diemcc, int diemkt, int diemthi, string hoten, string masv)
        : MonHoc(tenmh, diemcc, diemkt, diemthi), hoten(hoten), masv(masv) {};

        friend istream& operator >> (istream&, SinhVien&);
        friend ostream& operator << (ostream&, SinhVien);
        void CheckSinhVien(SinhVien*, int);
};

istream& operator >> (istream& input, SinhVien &sv) {
    cout << "\nNhap vao Ho Ten: "; getline(input, sv.hoten);
    cout << "Nhap vao Ma SV: "; getline(input, sv.masv);
    cout << "Nhap vao Ten Mon Hoc: "; getline(input, sv.tenmh);
    cout << "Nhap vao Diem CC: "; input >> sv.diemcc;
    cout << "Nhap vao Diem KT: "; input >> sv.diemkt;
    cout << "Nhap vao Diem Thi: "; input >> sv.diemthi;
    return input;
}

ostream& operator << (ostream& output, SinhVien sv) {
    output << "\nHo TEN: " << sv.hoten << endl;
    output << "Ma SV: " << sv.masv << endl;
    output << "Ten Mon Hoc: " << sv.tenmh << endl;
    output << "Diem CC: " << sv.diemcc << endl;
    output << "Diem KT: " << sv.diemkt << endl;
    output << "Diem Thi: " << sv.diemthi << endl;
    output << "Diem Hoc Phan: " << sv.diemcc * 0.1 + sv.diemkt * 0.2 + sv.diemthi * 0.7 << endl;
    return output;
}

void SinhVien::CheckSinhVien(SinhVien *arr, int n) {
    for(int i = 0; i < n; i++) {
        if (arr[i].diemcc < 5 || arr[i].diemkt == 0) {
            cout << arr[i] << endl;
        }
    }
}

int main() {
    system("cls");
    int n; cout << "\tNHAP VAO N SINH VIEN: "; cin >> n;
    SinhVien *arr = new SinhVien[n];

    for(int i = 0; i < n; i++) {
        cout << "\nNHAP VAO SINH VIEN THU " << i + 1 << endl;
        cin.ignore();
        cin >> arr[i];
    }
    
    cout << "\n\t===> DANH SACH SINH VIEN PHAI THI LAI <===";
    arr->CheckSinhVien(arr, n);
    delete arr;
    
    return 0;
}
