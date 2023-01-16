
/*
    Câu 17: Viết chương trình thực hiện các yêu cầu sau:
    1.	Khai báo lớp điểm với các thuộc tính: tọa độ x, tọa độ y.
    Khai báo lớp tam giác có thuộc tính 3 đỉnh là kiểu đối tượng điểm
    (lớp tam giác được gọi là lớp bao của lớp điểm) và thêm các thuộc tính: độ dài 3 cạnh.
    2.	Xây dựng các phương thức: nhập, xuất, tính khoảng cách 2 điểm (dùng hàm bạn),
    áp dụng tính độ dài 3 cạnh của tam giác; nhập, xuất 3 đỉnh của tam giác.
    3.	Nhập vào 1 tam giác. Kiểm tra tính chất của tam giác (thường, đều, vuông, cân, vuông cân).
    In kết quả ra màn hình.
*/

#include<bits/stdc++.h>
using namespace std;

class diem{
private:
    int x;
    int y;
public:

    diem(){}
    diem(int x, int y) : x(x), y(y){};
    
    void nhap(){
        cout << "nhap vao toa do x : "; cin >> x;
        cout << "nhap vao toa do y : "; cin >> y;
    }
    void xuat(){
        cout << "(" << x <<","<< y <<")" << "\t";
    }

    friend double dodai(diem A, diem B){
        return sqrt(pow(A.x - B.x,2) + pow(A.y - B.y,2));
    }
};

class tamgiac {
private:
    diem A, B, C;
    double ab, bc, ac;

public:
    tamgiac(){};
    tamgiac(double ab, double bc, double ac, float x1, int x2, int x3, int y1, int y2, int y3) : A(x1,y1) , B(x2,y2), C(x3,y3){
        this -> ab = ab;
        this -> bc = bc;
        this -> ac = ac;
    }

    void nhapdiem(){
        cout << "nhap toa do A" << endl ; A.nhap();
        cout << "nhap toa do B" << endl ; B.nhap();
        cout << "nhap toa do C" << endl ; C.nhap();

        ab = dodai(A, B);
        bc = dodai(B, C);
        ac = dodai(A, C);
    }
    
    void xuatdiem(){
        cout << "toa do A : "; A.xuat();
        cout << "toa do B : "; B.xuat();
        cout << "toa do C : "; C.xuat();
    }

    void check(){
        if(ab < ab + ac || bc < ac + ab || ac < ab + bc ){
            if(ab == ac || ab == bc || bc == ac){
                if(ab == ac && ab == bc && bc == ac){
                    cout << " la tam giac deu";
                }else if((ab == sqrt(pow(ac + bc,2))) || (bc == sqrt(pow(ab + ac,2))) || (ac = sqrt(pow(ab + bc,2)))){
                    cout << "la tam giac vuong can";
                }else 
                    cout << "la tam giac deu";
            }else if((ab == sqrt(pow(ac + bc,2))) || (bc == sqrt(pow(ab + ac,2))) || (ac = sqrt(pow(ab + bc,2)))){
                cout << "la tam giac vuong ";
            } else 
                cout << "la tam giac thuong ";
        } else
            cout << "khong la tam giac";
    }

};

int main(){
    tamgiac tg;
    tg.nhapdiem();
    tg.xuatdiem();
    tg.check();
    return 0;
}