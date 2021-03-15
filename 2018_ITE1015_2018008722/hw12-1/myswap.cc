#include<iostream>
#include"myswap.h"
using namespace std;
int main(){
	int a=3;
	int b=1;
	double c=3.1;
	double d=1.5;
	string e="Hello";
	string f="World!";
	cout<<"a= "<<a<<" b= "<<b<<endl;
	myswap(a,b);
	cout<<"a= "<<a<<" b= "<<b<<endl;
	cout<<"c= "<<c<<" d= "<<d<<endl;
	myswap(c,d);
	cout<<"c= "<<c<<" d= "<<d<<endl;
	cout<<"e= "<<e<<" f= "<<f<<endl;
	myswap(e,f);
	cout<<"e= "<<e<<" f= "<<f<<endl;
}
