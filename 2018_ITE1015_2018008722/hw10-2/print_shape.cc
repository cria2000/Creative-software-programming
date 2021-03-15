#include<iostream>
#include"print_shape.h"
#define PI 3.141592
using namespace std;
Circle::Circle(double radius){
	_radius=radius;
}
double Circle::getArea(){
	return PI*_radius*_radius;
}
double Circle::getPerimeter(){
	return 2*PI*_radius;
}
string Circle::getTypeString(){
	return "Circle";
}
Rectangle::Rectangle(double height, double width){
	_height=height;
	_width=width;
}
double Rectangle::getArea(){
	return _height*_width;
}
double Rectangle::getPerimeter(){
	return 2*(_height+_width);
}
string Rectangle::getTypeString(){
	return "Rectangle";
}
