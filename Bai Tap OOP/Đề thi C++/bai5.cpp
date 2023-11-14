
/*
    Câu 5: Viết chương trình thực hiện các yêu cầu sau:
        1.	Khai báo lớp người với các thuộc tính: họ tên, năm sinh.
        Khai báo lớp sinh viên kế thừa từ lớp người và thêm các
        thuộc tính: mã sinh viên, điểm trung bình.
        2.	Xây dựng các phương thức: nhập, xuất cho các đối tượng người, sinh viên.
        3.	Nhập vào n sinh viên. Sắp xếp lại và in ra màn hình danh sách sinh viên
        theo thứ tự giảm dần của điểm trung bình.

*/

#include <bits/stdc++.h>
using namespace std;

class nguoi {
protected:
    string hoten;
    int namsinh;

public:
    nguoi() {
        hoten = "";
        namsinh = 0;
    }
    nguoi(string hoten, int namsinh) {
        this->hoten = hoten;
        this->namsinh = namsinh;
    }
    ~nguoi() {}

};

class sinhvien : public nguoi {
private:
    string masv;
    float diemtb;

public:
    sinhvien(string hoten, int namsinh, string masv, float diemtb) {
        this->hoten = hoten;
        this->namsinh = namsinh;
        this->masv = masv;
        this->diemtb = diemtb;
    }

    sinhvien() {}
    ~sinhvien() {}
    
    void nhap(sinhvien *, int );
    void xuat(sinhvien *, int );
    void sapxep(sinhvien *, int );
    void xeploai(sinhvien *, int);
};


void sinhvien::nhap(sinhvien *arr, int n) {
    for(int i = 0; i < n; i++) {
        cin.ignore();
        cout << "\nNhap Vao Sinh Vien Thu " << i + 1 << endl;
        cout << "Nhap ho ten: "; getline(cin, arr[i].hoten);
        cout << "Nhap masv: "; getline(cin, arr[i].masv);
        cout << "Nhap namsinh: "; cin >> arr[i].namsinh;
        cout << "Nhap diemtb: "; cin >> arr[i].diemtb;
    }
}

void sinhvien::xuat(sinhvien *arr, int n) {
    cout << "\n_____________________________________________________" << endl;
    cout << "\nDANH SACH CAC SINH VIEN GIAM DAN THEO DTB" << endl;
    for(int i = 0; i < n; i++) {
        cout << "\nThong Tin Sinh Vien Thu " << i + 1 << ": " << endl;
        cout << "Ho Ten: " << arr[i].hoten << endl;
        cout << "Ma SV: " << arr[i].masv << endl;
        cout << "Nam Sinh: " << arr[i].namsinh << endl;
        cout << "Diem TB: " << arr[i].diemtb << endl;
    }
    cout << "\n_____________________________________________________" << endl;
}


void sinhvien::sapxep(sinhvien *arr, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if (arr[i].diemtb < arr[j].diemtb) {
                sinhvien temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sinhvien::xeploai(sinhvien *arr, int n) {
    for(int i = 0; i < n; i++) {
        cout << "\nSinh Vien Thu " << i + 1 << " Xep Loai: ";
        if (arr[i].diemtb < 4) {
            cout << "Yeu" << endl;
        } else if (arr[i].diemtb < 6.5) {
            cout << "Trung Binh" << endl;
        } else if (arr[i].diemtb < 8) {
            cout << "Kha" << endl;
        } else {
            cout << "Gioi" << endl;
        }
    }
}

int main() {
    
    system("cls");
    int n; cout << "Nhap vao n sinh vien: "; cin >> n;
    sinhvien *arr = new sinhvien[n];

    arr->nhap(arr, n);
    arr->sapxep(arr, n);
    arr->xuat(arr, n);
    arr->xeploai(arr, n);



    return 0;
}