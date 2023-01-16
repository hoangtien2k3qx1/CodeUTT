

#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int main(){
	char s[100];
	int i,s0,s1,s2,s3,s4,s5,s6,s7,s8,s9;
	cout<<"Nhap chuoi:"; gets(s);
	for(i=0;i<strlen(s);i++)
		if(s[i]==0)
			s0++;
		if(s[i]==1)
			s1++;
		if(s[i]==2)
			s2++;
		if(s[i]==3)
			s3++;
		if(s[i]==4)
			s4++;
		if(s[i]==5)
			s5++;
		if(s[i]==6)
			s6++;
		if(s[i]==7)
			s7++;
		if(s[i]==8)
			s8++;
		if(s[i]==9)
			s9++;	
		cout<<"\nSo cac chu so 0 la: "<<s0;
		cout<<"\nSo cac chu so 1 la: "<<s1;
		cout<<"\nSo cac chu so 2 la: "<<s2;
		cout<<"\nSo cac chu so 3 la: "<<s3;
		cout<<"\nSo cac chu so 4 la: "<<s4;
		cout<<"\nSo cac chu so 5 la: "<<s5;
		cout<<"\nSo cac chu so 6 la: "<<s6;
		cout<<"\nSo cac chu so 7 la: "<<s7;
		cout<<"\nSo cac chu so 8 la: "<<s8;
		cout<<"\nSo cac chu so 9 la: "<<s9;
		
}