#include<iostream>
#include"my_vector.h"
using namespace std;
MyVector::MyVector(){
	max_num=0;
	a=0;
}
MyVector::MyVector(int _max_num){
	max_num=_max_num;
	a=new double[_max_num];
}
MyVector::~MyVector(){
	delete a;
	max_num=0;
}

MyVector& MyVector::operator=(const MyVector &b){
	max_num=b.max_num;
	for(int i=0;i<max_num;i++){
		a[i]=b.a[i];
	}
	return (*this);
}
MyVector MyVector::operator+(const MyVector &b){
	MyVector c(max_num);
	for(int i=0;i<max_num;i++){
		c.a[i]=b.a[i]+a[i];
	}
	return c;
}
MyVector MyVector::operator-(const MyVector &b){
	MyVector c(max_num);
	for(int i=0;i<max_num;i++){
		c.a[i]=a[i]-b.a[i];
	}
	return c;
}
MyVector MyVector::operator+(const int b){
	MyVector c(max_num);
	for(int i=0;i<max_num;i++){
		c.a[i]=a[i]+b;
	}
	return c;
}
MyVector MyVector::operator-(const int b){
	MyVector c(max_num);
	for(int i=0;i<max_num;i++){
		c.a[i]=a[i]-b;}
	return c;
}
ostream& operator<<(ostream& out, MyVector& b){
	for(int i=0;i<b.max_num;i++){
		out<<b.a[i]<<" ";
	}
	out<<endl;
	return out;
}
istream& operator>>(istream& in, MyVector& b){
	for(int i=0;i<b.max_num;i++){
		in>>b.a[i];
	}
	return in;
}




