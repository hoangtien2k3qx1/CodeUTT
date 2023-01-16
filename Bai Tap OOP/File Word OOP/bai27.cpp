/*
    Câu 27: Nhân viên trong một cơ quan được lĩnh lương theo các dạng khác nhau. Dạng người lao động hưởng lương từ ngân sách Nhà nước gọi là cán bộ, công chức (dạng biên chế). Dạng người lao động lĩnh lương từ ngân sách của cơ quan gọi là người làm hợp đồng. Như vậy, trong hệ thống cấp phát lương có 2 dạng: biên chế và hợp đồng. Hai loại đối tượng này có đặc tính chung là viên chức làm việc cho cơ quan. Trong bảng lương với mỗi viên chức, cần quản lý các thông tin: Mã số, họ tên, chức vụ. Ngoài ra với viên chức là biên chế cần biết thêm thông tin: Hệ số lương, với mỗi viên chức là hợp đồng cần biết thêm thông tin: số ngày làm việc trong tháng.
    Anh (Chị) hãy viết chương trình hướng đối tượng, trong đó xây dựng lớp cơ sở và các lớp dẫn xuất với các dữ liệu thành viên và các hàm cần thiết để thực hiện các yêu cầu sau: 
    1.	Nhập dữ liệu cho cán bộ, nhân viên trong biên chế và nhân viên hợp đồng. Dữ liệu được lưu trong mảng các đối tượng.
    2.	In ra màn hình bảng lương theo mẫu:

    BẢNG DANH SÁCH TIỀN LƯƠNG CÁN BỘ BIÊN CHẾ 
        STT              Họ tên            Hệ số lương                 Tiền lương
    BẢNG DANH SÁCH TIỀN LƯƠNG CÁN BỘ HỢP ĐỒNG
        STT              Họ tên            Số ngày làm việc            Tiền lương

    Biết rằng:  
        Tiền lương (cán bộ biên chế) = Hệ số lương x 830000 + PCCV - BHXH
        Tiền lương (cán bộ hợp đồng) = 1500000 + tiền tăng giờ - BHXH
		BHXH = 5% * Tiền lương	
		PCCV (phụ cấp chức vụ) được tính theo quy định: Giám đốc: 150000, Phó giám đốc: 100000, các chức vụ khác không có PCCV.
		Tiền tăng giờ: Nếu cán bộ hợp đồng làm việc trên 26 ngày /tháng thì mỗi ngày dôi ra được tính bồi dưỡng 100000 đ/ngày, làm việc dưới 26 ngày/tháng thì mỗi ngày nghỉ bị trừ 50000đ.


*/

#include<bits/stdc++.h>
using namespace std;

class BienChe{
public:
    string hoten;
    string chucvu;
    float hesoluong;
    long long tienluong = 0;

public:
    BienChe() {};
    BienChe(string hoten, string chucvu, float hesoluong) {
        this->hoten = hoten;
        this->chucvu = chucvu;
        this->hesoluong = hesoluong;
    }
    virtual ~BienChe() {};
    void NhapThongTinCanBoBienChe(BienChe *, int);
    void InThongInCanBoBienChe(BienChe *, int);
};


class HopDong : public BienChe {
public:
    int songaylamviec;
    float tientanggio;

public:
    HopDong() {};
    HopDong(string hoten, int songaylamviec, float tientanggio) {
        this->hoten = hoten;
        this->songaylamviec = songaylamviec;
        this->tientanggio = tientanggio;
    }
    ~HopDong() {};
    void NhapThongTinCanBoHopDong(HopDong *, int);
    void InThongTinCanBoHopDong(HopDong *, int);
};

void BienChe::NhapThongTinCanBoBienChe(BienChe *arr, int n) {
    cout << "\n--- NHAP VAO THONG TIN CAC CAN BO BIEN CHE ---" << endl;
    for(int i = 0; i < n; i++) {
        cin.ignore();
        cout << "\n->Nhap Thong Tin Can Bo Bien Che " << i + 1 << ": " << endl;
        cout << "\t+ Nhap Ho Ten: "; getline(cin, arr[i].hoten);
        cout << "\t+ Nhap Chuc Vu (GD, PGD, NV): "; getline(cin, arr[i].chucvu);
        cout << "\t+ Nhap He So Luong: "; cin >> arr[i].hesoluong;
        if (arr[i].chucvu == "GD") {
            arr[i].tienluong += ((arr[i].hesoluong * 830000) + 150000);
        } else if (arr[i].chucvu == "PGD") {
            arr[i].tienluong += ((arr[i].hesoluong * 830000) + 100000);
        } else {
            arr[i].tienluong += ((arr[i].hesoluong * 830000));
        }
        long long result = arr[i].tienluong * (5/100);
        arr[i].tienluong -= result;
    }
}

void BienChe::InThongInCanBoBienChe(BienChe *arr, int n) {
    cout << "\n\t\t\t---> BANG DANH SACH TIEN LUONG CAN BO BIEN CHE <---" << endl;
    cout << setw(10) << "STT" << setw(20) << "Ho Ten" << setw(30) << "He So Luong" << setw(30) << "Tien Luong" << setw(35) << endl;
    for(int i = 0; i < n; i++) {
        cout << setw(9) << i + 1 << setw(29) << arr[i].hoten << setw(20) << arr[i].hesoluong << setw(30) << arr[i].tienluong << setw(35) << endl;
    }
}

void HopDong::NhapThongTinCanBoHopDong(HopDong *brr, int n) {
    cout << "\n--- NHAP VAO THONG TIN CAC CAN BO HOP DONG ---" << endl;
    for(int i = 0; i < n; i++) {
        cin.ignore();
        cout << "\n->Nhap Thong Tin Can Bo Hop Dong " << i + 1 << ": " << endl;
        cout << "\t+ Nhap Ho Ten: "; getline(cin, brr[i].hoten);
        cout << "\t+ Nhap So Ngay Lam Viec: "; cin >> brr[i].songaylamviec;

        if (brr[i].songaylamviec > 26) {
            brr[i].tienluong += (1500000) + (brr[i].songaylamviec - 26) * 100000;
        } else {
            brr[i].tienluong += (1500000) - (26 - brr[i].songaylamviec) * 50000;
        }
        long long result = brr[i].tienluong * (5/100);
        brr[i].tienluong -= result;
    }
}

void HopDong::InThongTinCanBoHopDong(HopDong *brr, int n) {
    cout << "\n\t\t\t---> BANG DANH SACH TIEN LUONG CAN BO HOP DONG <---" << endl;
    cout << setw(10) << "STT" << setw(20) << "Ho Ten" << setw(30) << "So Ngay Lam Viec" << setw(30) << "Tien Luong" << setw(35) << endl;
    for(int i = 0; i < n; i++) {
        cout << setw(9) << i + 1 << setw(29) << brr[i].hoten << setw(20) << brr[i].songaylamviec << setw(30) << brr[i].tienluong << setw(35) << endl;
    }
}

int main() {
    system("cls");

    int n; cout << "NHAP VAO N CAN BO BIEN CHE: "; cin >> n;
    BienChe * arr = new BienChe[n];
    arr->NhapThongTinCanBoBienChe(arr, n);

    int a; cout << "\nNHAP VAO N CAN BO HOP DONG: "; cin >> a;
    HopDong * brr = new HopDong[a];
    brr->NhapThongTinCanBoHopDong(brr, a);

    cout << "\n\t___________________________________________________________________\n";
    arr->InThongInCanBoBienChe(arr, n);
    cout << "\n\t___________________________________________________________________\n";
    brr->InThongTinCanBoHopDong(brr, a);
    cout << "\n\t___________________________________________________________________\n";

    cin.get();
    return 0;
}