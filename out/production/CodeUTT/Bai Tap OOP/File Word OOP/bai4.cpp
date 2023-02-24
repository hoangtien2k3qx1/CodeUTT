/*
    Viết chương trình thực hiện các yêu cầu sau:
        1.	Khai báo lớp time với các thuộc tính: giờ, phút, giây.
        Xây dựng hàm tạo không đối, hàm tạo có đối, hàm hủy một đối tượng time.
        2.	Xây dựng các phương thức: nhập, xuất, chuẩn hóa một đối tượng time.
        3.	Định nghĩa toán từ ++,-- để tăng, giảm một giây. Thực hiện tăng, 
        giảm một giây và in kết quả ra màn hình (kết quả phải được chuẩn hóa 
        dưới định dạng 24 tiếng hh:mm:ss).
*/

#include<bits/stdc++.h>
using namespace std;

template<typename T, typename V, typename S>
class ThoiGian {
private:
    T hour, minute, second; 
public:
    ThoiGian() : hour(0), minute(0), second(0) {}
    ~ThoiGian() {
        hour = minute = second = 0;
    }
    V Input_Information();
    V Output_Second_Previous();
    V Output_Second_Next();
};

template<typename T, typename V, typename S>
V ThoiGian<T, V, S>::Input_Information() {
    do {
        cout << "Input Hour: "; cin >> hour;
        cout << "Input Minute: "; cin >> minute;
        cout << "Input Second: "; cin >> second;
        if (hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59) {
            cout << "\nErorr, Input Againt !!!: " << endl;
        }
    } while(hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59);
}

template<typename T, typename V, typename S>
V ThoiGian<T, V, S>::Output_Second_Previous() {
    T newSecond = second, newMinute = minute, newHour = hour;
    if (newSecond < 59) {
        newSecond++;
    } else if (newMinute < 59) {
        newSecond = 0;
        newMinute++;
    } else {
        newSecond = newMinute = 0;
        if (newHour == 23) {
            newHour = 0;
        } else {
            newHour++;
        }
    }

    S newSecond1 = to_string(newSecond), newMinute1 = to_string(newMinute), newHour1 = to_string(newHour);
    if (newSecond1.length() == 1) { newSecond1 = "0" + newSecond1; } 
    if (newMinute1.length() == 1) { newMinute1 = "0" + newMinute1; }
    if (newHour1.length() == 1) { newHour1 = "0" + newHour1; }

    cout << "\nSecond Previous: " << newHour1 << ":" << newMinute1 << ":" << newSecond1 << endl;
}

template<typename T, typename V, typename S>
V ThoiGian<T, V, S>::Output_Second_Next() {
    T newSecond = second, newMinute = minute, newHour = hour;
    if (newSecond == 0 && newMinute == 0) {
        newSecond = newMinute = 59;
        newHour--;
    } else if (newSecond == 0) {
        newSecond = 59;
        newMinute--;
    } else {
        newSecond--;
    }

    S newSecond1 = to_string(newSecond), newMinute1 = to_string(newMinute), newHour1 = to_string(newHour);
    if (newSecond1.length() == 1) { newSecond1 = "0" + newSecond1; } 
    if (newMinute1.length() == 1) { newMinute1 = "0" + newMinute1; }
    if (newHour1.length() == 1) { newHour1 = "0" + newHour1; }

    cout << "Second Next: " << newHour1 << ":" << newMinute1 << ":" << newSecond1 << endl;
}

int main() {
    system("cls");
    ThoiGian<int, void, string> t;
    t.Input_Information();
    t.Output_Second_Previous();
    t.Output_Second_Next();
    cin.get();
    return 0;
}