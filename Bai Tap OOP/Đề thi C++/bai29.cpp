
/*
    Câu 29: Khởi động C++, tạo tập tin có tên D:\Bai1.CPP, sau đó viết chương trình thực hiện yêu cầu: Xây dựng lớp ps (phân số) có các thành phần:
   - Các thuộc tính: tu, mau.
   - Hàm tạo để thiết lập giá trị ban đầu cho các thuộc tính.
   - Hàm nhap để nhập dữ liệu vào cho 2 dữ liệu thuộc tính.
   - Hàm hienthi để in kết quả của 2 thuộc tính lên màn hình.
   - Quá tải các toán tử ==, >  để so sánh 2 phân số, + để cộng hai phân số.
   Sau đó xử lý thực hiện các công việc :
   a) Nhập n phân số từ bàn phím.
   b) In ra màn hình n phân số vừa nhập.
   c) In ra màn hình tổng của n phân số đã nhập (sau khi rút gọn phân số tổng).
   d) In ra màn hình phân số có giá trị lớn nhất.
   e) Nhập một phân số từ bàn phím và tìm xem phân số đó đã có trong n phân số đã nhập ở trên không ?

*/

#include<bits/stdc++.h>
using namespace std;

class PhanSo {
    public:
        int tuso, mauso;
    public:
        PhanSo() : tuso(0), mauso(1) {}
        PhanSo(int tuso, int mauso) {
            this->tuso = tuso;
            this->mauso = mauso;
        }

        friend istream& operator >> (istream& , PhanSo& );
        friend ostream& operator << (ostream& , PhanSo ); 

        void rutgon();

        friend PhanSo operator+ (PhanSo, PhanSo);
        PhanSo TongTatCaPhanSo(PhanSo*, int);  // Functuon protertype
        int PhanSoGiaTriLonNhat(PhanSo*, int);

};

istream& operator >> (istream& input, PhanSo &ps) {
    cout << "\nNhap tuso: "; input >> ps.tuso;
    cout << "Nhap mauso: "; input >> ps.mauso;
    return input;
}

ostream& operator << (ostream& output, PhanSo ps) {
    cout << ps.tuso << "/" << ps.mauso << endl;
    return output;
}

int gcd(int a, int b) {
    if (b == 0) 
        return a;
    return gcd(b, a % b);
}

void PhanSo::rutgon() {
    PhanSo ps;
    int g = gcd(ps.tuso, ps.mauso);

    ps.tuso /= g;
    ps.mauso /= g;

}

PhanSo operator + (PhanSo ps1, PhanSo ps2) {
    PhanSo tong(0, 1);
    tong.tuso = ps1.tuso * ps2.mauso + ps2.tuso * ps1.mauso;
    tong.mauso = ps1.mauso * ps2.mauso;
    
    int g = gcd(tong.tuso, tong.mauso);

    tong.tuso /= g;
    tong.mauso /= g;

    return tong;
}

PhanSo PhanSo::TongTatCaPhanSo(PhanSo *arr, int n) {
    PhanSo sum(0, 1);
    if (n % 2 == 0){
        for(int i = 0; i < n; i+=2) {
            sum = sum + arr[i] + arr[i + 1];
        }
    } else {
        sum = arr[0];
        for(int i = 1; i < n; i+=2) {
            sum = sum + arr[i] + arr[i + 1];
        }
    }
    return sum;
}


int PhanSo::PhanSoGiaTriLonNhat(PhanSo *arr, int n) {
    int count = 0;
    float ans = (float)arr[0].tuso/arr[0].mauso;
    for(int i = 0; i < n; i++) {
        float index = (float)arr[i].tuso/arr[i].mauso;
        if (index > ans) {
            ans = index;
            count = i;
        }
    }
    return count;
}

int main() {
    system("cls");

    int n; cout << "NHAP VAO N PHAN SO: "; cin >> n;
    PhanSo *arr = new PhanSo[n];

    for(int i = 0; i < n; i++) {
        cout << "\nNHAP VAO PHAN SO THU " << i + 1;
        cin >> arr[i];
    }

    cout << "\n\t===> DANH SACH CAC PHAN SO VUA NHAP <===" << endl;
    for(int i = 0; i < n; i++) {    
        cout << "\t\tPhan So " << i + 1  << ": " << arr[i];
    }

    cout << "\n\t\tTong Tat Ca Ca Phan So: " << arr->TongTatCaPhanSo(arr, n) << endl;

    int count = arr->PhanSoGiaTriLonNhat(arr, n);
    cout << "\t\tPhan So Co Gia Tri Lon Nhat: " << arr[count].tuso << "/" << arr[count].mauso << endl;

    cout << "\nNHAP VAO PHAN SO MOI CAN SO SANH: " << endl;
    PhanSo brr;
    cout << "Nhap vao tuso: "; cin >> brr.tuso;
    cout << "Nhap vao mauso: "; cin >> brr.mauso;
    
    for(int i = 0; i < n; i++) {
        if ((float)brr.tuso/brr.mauso == (float)arr[i].tuso/arr[i].mauso) {
            cout << "\n\t=> Phan So Moi Vua Nhap Da Co Trong N Phan So !!!" << endl;
            return 0;
        }
    }
    cout << "\n\t=> Phan So Moi Vua Nhap Khong Co Trong N Phan So !!!" << endl;

    cin.get();
    return 0;
}