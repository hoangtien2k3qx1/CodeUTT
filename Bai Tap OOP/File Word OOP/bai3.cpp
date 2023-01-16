
/*
    Câu 3: Viết chương trình thực hiện các yêu cầu sau:
        1.	Khai báo lớp date với các thuộc tính: ngày, tháng, năm.
        Xây dựng hàm tạo không đối, hàm tạo có đối, hàm hủy một đối tượng date.
        2.	Xây dựng các phương thức: nhập, xuất, chuẩn hóa một đối tượng date.
        Định nghĩa toán từ ++,-- để tăng, giảm một ngày. Thực hiện tăng, giảm một ngày 
        và in kết quả ra màn hình (kết quả phải được chuẩn hóa dưới dạng dd-mm-yyyy).
*/

#include<bits/stdc++.h>

template<typename T, typename X, typename Y> class Lop {
private:
    T day, month, year;
public:
    Lop() {}
    Lop(T day, T month, T year) : day(day), month(month), year(year) {}
    ~Lop() {}
    Y Nhap();                    
    Y XuatNgayTruocDo();         
    Y XuatNgaySauDo();          
};

template<typename T, typename X, typename Y> Y Lop<T, X, Y>::Nhap() {
    std::cout << "Nhap vao ngay: "; std::cin >> day;
    std::cout << "Nhap vao thang: "; std::cin >> month;
    std::cout << "Nhap vao nam: "; std::cin >> year;
}

int TimSoNgayTrongThang(int thang, int nam){
    switch(thang) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31; break;
        case 4: case 6: case 9 : case 11: return 30; break;
    default:
        return (nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0) ? 29 : 30; break;
    }
}

template<typename T, typename X, typename Y> Y Lop<T, X, Y>::XuatNgayTruocDo() {
    T newDay = day, newMonth = month, newYear = year;
    if (newYear > 0 && (newMonth > 0 && newMonth < 13) && (newDay > 0 && newDay <= (TimSoNgayTrongThang(newMonth, newYear))) ) {
        if (newDay < TimSoNgayTrongThang(newMonth, newYear)) {     
            newDay++;                                              
        } else if (newMonth < 12) {                                
            newDay = 1;                                           
            newMonth++;                                           
        } else {
            newDay = newMonth = 1;                                  
            newYear++;                                           
        }
    }
    X newDay1 = std::to_string(newDay);                             
	X newMonth1 = std::to_string(newMonth);                        
	X newYear1 = std::to_string(newYear);                         
	if (newDay1.length() == 1) {                                    
		newDay1 = "0" + newDay1;			                       
	}
	if (newMonth1.length() == 1) {                                
		newMonth1 = "0" + newMonth1;			
	}
    std::cout << "\nNgay Truoc Do: " << newDay1 << "-" << newMonth1 << "-" << newYear1 << std::endl;
}

template<typename T, typename X, typename Y> Y Lop<T, X, Y>::XuatNgaySauDo() {
    T newYear = year, newMonth = month, newDay = day;
    if (newYear > 0 && (newMonth > 0 && newMonth < 13) && (newDay > 0 && newDay <= (TimSoNgayTrongThang(newMonth, newYear))) ) {
        if (newDay == 1 && newMonth == 1) {
            newDay = 31;
            newMonth = 12;
            newYear--;
        } else if (newDay <= TimSoNgayTrongThang(newMonth, newYear)) {
            if (newDay == 1) {
                newDay = TimSoNgayTrongThang(newMonth - 1, newYear) + 1;
                newMonth--;
            }
            newDay--;
        }
    }
    X newDay1 = std::to_string(newDay);
	X newMonth1 = std::to_string(newMonth);
	X newYear1 = std::to_string(newYear);
	if (newDay1.length() == 1) {
		newDay1 = "0" + newDay1;			
	}
	if (newMonth1.length() == 1) {
		newMonth1 = "0" + newMonth1;			
	}
    std::cout << "Ngay Sau Do: " << newDay1 << "-" << newMonth1 << "-" << newYear1 << std::endl;
}

int main() {
    system("cls");             
    Lop<int, std::string, void> l;   
    l.Nhap();                   
    l.XuatNgayTruocDo();        
    l.XuatNgaySauDo();         
    std::cin.get();            
    return 0;                  
}

