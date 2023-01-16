
#include "bits/stdc++.h"

using namespace std;

class sophuc{
    protected:
    float thuc;
    float ao;

    public:
    sophuc(){};
    sophuc(float thuc, float ao): thuc(thuc), ao(ao){};

    void nhap(){
        cout << "nhap vao phan thuc : "; cin >> thuc;
        cout << "nhap vao phan ao : "; cin >> ao;
    }

    void xuat(){
        cout << thuc << "+" << ao << "*i" << endl;
    }

    float modun(){
        return sqrt(ao*ao + thuc*thuc);
    }
};

class sophuc2 : public sophuc{
    private:
        float md;
    public: 
    sophuc2(){
        md = sophuc::modun();
    }
    sophuc2(float thuc, float ao) : sophuc(thuc,ao){};

    void operator = (sophuc2 &d){
        this -> thuc = d.thuc;
        this -> ao = d.ao;
    }

    bool operator < (sophuc2 &d){
        return md < d.md;
    }

    bool operator == (sophuc2 &d){
        if(thuc == d.thuc && ao == d.ao)
            return true;
        return false;
    }

    sophuc operator + (sophuc2 &d){
        sophuc2 sum;
        sum.thuc = thuc + d.thuc;
        sum.ao = ao + d.ao;

        return sum;
    }

    void max(sophuc2 *sp, int n){
        sophuc2 max = sp[0];
        for(int i = 0; i < n; i++){
            if (max.modun() < sp[i].modun()){
                max = sp[i];
            }
        }
        max.xuat();
    }

    void demsp(sophuc2 *sp,int n){
        int dem = 0;
        sophuc2 tg(3,4);
        for(int i = 0; i < n; i++){
            if (sp[i] == tg){
                dem ++;
            }
        } 
        cout << dem; 
    }
    sophuc2 tong(sophuc2 *sp, int n){
        sophuc2 sum(0,0);
        for(int i = 0; i < n; i++){
            sum = sp[i] + sum;
        }
        return sum;
    }
};

int main(){
    sophuc2 *sp;
    int n;
    cout << "nhap vao n : "; cin >> n;

    sp = new sophuc2[n];

    for(int i = 0; i < n; i++){
        sp[i].nhap();
    }
        for(int i = 0; i < n; i++){
        sp[i].xuat();
    }

    sp ->max(sp,n);

    sp -> demsp(sp,n);

    sp -> tong(sp,n);

}