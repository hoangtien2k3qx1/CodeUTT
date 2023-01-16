#include "bits/stdc++.h"

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

        ab = dodai(A,B);
        bc = dodai(B,C);
        ac = dodai(A,C);
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
}