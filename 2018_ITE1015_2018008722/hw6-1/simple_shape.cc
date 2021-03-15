#include<iostream>
#define PI 3.14
#include"simple_shape.h"
using namespace std;

void Circle::make_circle(){
	double r1=rad*rad*PI;
	double r2=2*PI*rad;
	cout<<"area: "<<r1;
	cout<<", perimeter: "<<r2<<endl;}
void Square::make_square(){
	int l1=rx-lx;
	int l2=ly-ry;
	cout<<"area: "<<(l1*l2)<<", perimeter: "<<(2*l1)+(2*l2)<<endl;}

