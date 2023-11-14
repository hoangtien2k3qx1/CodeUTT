
#include<bits/stdc++.h>
using namespace std;


class Time {
private:
    int hour, minute, second;

public:
    Time() {};
    Time() : hour(0), minute(0), second(0) {}
    ~Time() {};

    void Input_Information();
    void Output_Second_Previous();
    void Output_Second_Next();

};

void Input_Information() {
    do {
        cout << "Nhap vao gio: "; cin >> hour;
        cout << "Nhap vao phut: "; cin >> minute;
        cout << "Nhap vao giay: "; cin >> second;
        if (hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59) {
            cout << "\nNhap lai!!";
        }
    } while(hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59);
}

void Output_Second_Previous() { 
    int newHour = hour, newMinute = minute, newSecond = second;
    if (newSecond < 59) {
        newSecond++;
    } else if (newMinute < 59) {
        newSecond = 0;
        newMinute++;
    }


}


int main() {
    system("cls");


    return 0;
}