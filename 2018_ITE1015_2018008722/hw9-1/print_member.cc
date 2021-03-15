#include<iostream>
#include"print_member.h"
using namespace std;

A::A(int a){
	memberA=new int;
	*memberA=a;
	cout<<"new memberA"<<endl;
}
A::~A(){
	delete memberA;
	cout<<"delete memberA"<<endl;
}
B::B(double b) : A(1){
	memberB=new double;
	*memberB=b;
	cout<<"new memberB"<<endl;
}
B::~B(){
	delete memberB;
	cout<<"delete memberB"<<endl;
}
C::C(string c) : B(1.1){
	memberC=new string;
	*memberC=c;
	cout<<"new memberC"<<endl;
}
C::~C(){
	delete memberC;
	cout<<"delete memberC"<<endl;
}
void A::print(){
	cout<<"*memberA "<<*memberA<<endl;
}
void B::print(){
	A::print();
	cout<<"*memberB "<<*memberB<<endl;
}
void C::print(){
	B::print();
	cout<<"*memberC "<<*memberC<<endl;
}

