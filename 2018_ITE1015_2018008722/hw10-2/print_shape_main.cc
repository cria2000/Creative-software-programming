#include<iostream>
#include<vector>
#include"print_shape.h"
using namespace std;
int main(){
	string ans;
	std::vector<Shape*> shapes;
	while(true){
		cin>>ans;
		if(ans=="c"){
			double c_radius;
			cin>>c_radius;
			shapes.push_back(new Circle(c_radius));
		}
		else if(ans=="r"){
			double r_height, r_width;
			cin>>r_height>>r_width;
			shapes.push_back(new Rectangle(r_height,r_width));
		}
		else if(ans=="0"){
			for(Shape *shape : shapes) cout<<shape->getTypeString()<<", "<<shape->getArea()<<", "<<shape->getPerimeter()<<endl;
			for(Shape *shape : shapes) delete shape;
			return 0;
		}
	}
}

