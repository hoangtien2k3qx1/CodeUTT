
/*
    Câu 16: Viết chương trình thực hiện các yêu cầu sau:
    1.	Khai báo lớp hình vuông với thuộc tính: độ dài cạnh 1.
    Khai báo lớp hình chữ nhật kế thừa từ lớp hình vuông và thêm thuộc tính: độ dài cạnh thứ 2.
    2.	Xây dựng các phương thức: nhập, xuất, tính chu vi, diện tích hình vuông, hình chữ nhật.
    3.	Nhập vào n hình vuông. In ra màn hình hình vuông có diện tích lớn nhất và vị trí của 
    hình vuông đó trong danh sách vừa nhập.

*/

#include<bits/stdc++.h>
using namespace std;


class HinhVuong {
    public:
        int dodai1;
    
    public:
        HinhVuong() {};
        HinhVuong(int dodai1) : dodai1(dodai1) {};
        ~HinhVuong() {};

        float ChuViHinhVuong(HinhVuong);
        float DienTichHinhVuong(HinhVuong);
        float DienTichLonNhat(HinhVuong, int);
};


class HinhChuNhat : public HinhVuong {
    private:
        int dodai2;
    public:
        HinhChuNhat() {}
        HinhChuNhat(int dodai1, int dodai2) : HinhVuong(dodai1), dodai2(dodai2) {}
        ~HinhChuNhat() {}

        void NhapThongTin(HinhChuNhat&);
        float ChuViHinhChuNhat(HinhChuNhat);
        float DienTichHinhChuNhat(HinhChuNhat);
        void ThongTinHinhVuong(HinhChuNhat*, int);

};


void HinhChuNhat::NhapThongTin(HinhChuNhat &hcn) {
    cout << "\nNhap vao dodai1: "; cin >> hcn.dodai1;
    cout << "Nhap vao dodai2: "; cin >> hcn.dodai2;
}

float HinhVuong::ChuViHinhVuong(HinhVuong hv) {
    return 4 * hv.dodai1;
}

float HinhVuong::DienTichHinhVuong(HinhVuong hv) {
    return hv.dodai1 * hv.dodai1;
}

float HinhChuNhat::ChuViHinhChuNhat(HinhChuNhat hcn) {
    return (hcn.dodai2 + hcn.dodai1) * 2;
}

float HinhChuNhat::DienTichHinhChuNhat(HinhChuNhat hcn) {
    return hcn.dodai2 * hcn.dodai1;
}

void HinhChuNhat::ThongTinHinhVuong(HinhChuNhat *arr, int n) {
    float Max = 0;
    int count = 0;
    for(int i = 0; i < n; i++) {
        if (arr->DienTichHinhVuong(arr[i]) > Max) {
            Max = arr->DienTichHinhVuong(arr[i]);
            count = i;
        }
    }
    cout << "\n________________________________________________\n";
    cout << "\nHinh Vuong Co Dien Tich Lon Nhat: " << arr->DienTichHinhVuong(arr[count]) << endl;
    cout << "Vi Tri Hinh Vuong: " << count + 1 << endl;
    cout << "\n________________________________________________\n";
}

int main() {
    int n; cout << "Nhap vao n Hinh Vuong: "; cin >> n;
    HinhChuNhat *arr = new HinhChuNhat[n];

    for(int i = 0; i < n; i++) {
        cout << "\nNHAP VAO THONG TIN DO DAI " << i + 1 << ": "; 
        arr->NhapThongTin(arr[i]);
    }
    
    arr->ThongTinHinhVuong(arr, n);
    
    return 0;
}