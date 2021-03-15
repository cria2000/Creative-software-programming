#include<iostream>
#include"my_string.h"
#include<string.h>
using namespace std;
MyString::MyString(){
	len=50;
	a=new char[50];
}
MyString::MyString(const MyString& my_string){
	len=my_string.len;
	a=new char[50];
	strcpy(a,my_string.a);
}
MyString::~MyString(){
	delete a;
	len=0;
}
MyString& MyString::operator=(const MyString& b){
	a=b.a;
	len=b.len;
	return (*this);
}
MyString MyString::operator+(const MyString& b){
	MyString c;
	strcpy(c.a,a);
	strcat(c.a,b.a);
	c.len=strlen(c.a);
	return c;
}
MyString MyString::operator*(const int b){
	MyString c;
	for(int i=0;i<b;i++)
		strcat(c.a,a);
	c.len=strlen(c.a);
	return c;
}

ostream& operator<<(ostream& out, MyString& my_string){
	out<<my_string.a<<endl;
	return out;
}
istream& operator>>(istream& in, MyString& my_string){
	while(true){
		in>>my_string.a;
		if(strlen(my_string.a)>50){
			cout<<"Please enter within 50 characters"<<endl;
			//delete my_string.a;
			}
		else{
			return in;
		}
	}
	
}


