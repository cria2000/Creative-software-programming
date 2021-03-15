#include<iostream>
#include"rectangle.h"
using namespace std;
int Rectangle::getWidth() const{
	return _width;
}
int Rectangle::getHeight() const{
	return _height;}
int Rectangle::getArea() const{
	return _width*_height;
}
int Rectangle::getPerimeter() const{
	return 2*(_width+_height);
}
void Square::print() const{
	cout<<getHeight()<<"x"<<getWidth()<<" Square"<<endl;
	cout<<"Area: "<<getArea()<<endl;
	cout<<"Perimater: "<<getPerimeter()<<endl;}
void NonSquare::print() const{
	cout<<getHeight()<<"x"<<getWidth()<<" NonSquare"<<endl;
	cout<<"Area: "<<getArea()<<endl;
	cout<<"Perimeter: "<<getPerimeter()<<endl;}

