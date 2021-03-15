#include<iostream>
#include<vector>
#include"shapes.h"
using namespace std;
int main(){
	double t_width;
	double t_height;
	double r_width;
	double r_height;
	std::vector<Shape *> shapes;
	cin>>t_width>>t_height>>r_width>>r_height;
	shapes.push_back(new Triangle(t_width,t_height));
	shapes.push_back(new Rectangle(r_width, r_height));
	for(Shape *shape : shapes) cout<<shape->getArea()<<endl;
	for(Shape *shape : shapes) delete shape;
}
