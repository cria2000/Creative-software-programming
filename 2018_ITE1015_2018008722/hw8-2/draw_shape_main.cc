#include<iostream>
#include<string>
#include"draw_shape.h"
using namespace std;
int main(){
	int c_height, c_width;
	int x,y;
	char brush;
	string cmd;
	cin>>c_height>>c_width;
	while(true){
		cin>>cmd;
		if(cmd=="quit") break;
		else{
			cin>>x>>y;
			if(cmd=="rect"){
				int height, width;
				cin>>height>>width>>brush;
				Rectangle r(x,y,height,width,brush);
				cout<<"Area: "<<r.GetArea()<<endl;
				cout<<"Perimeter: "<<r.GetPerimeter()<<endl;
				r.Draw(c_width, c_height);
			}
			else if(cmd=="square"){
				int width;
				cin>>width>>brush;
				Square s(x,y,width,brush);
				cout<<"Area: "<<s.GetArea()<<endl;
				cout<<"Perimeter: "<<s.GetPerimeter()<<endl;
				s.Draw(c_width, c_height);
			}
			else if (cmd=="diamond"){
				int dist;
				cin>>dist>>brush;
				Diamond d(x,y,dist,brush);
				cout<<"Area: "<<d.GetArea()<<endl;
				cout<<"Perimeter: "<<d.GetPerimeter()<<endl;
				d.Draw(c_width, c_height);
			}
		}
	}
	return 0;
}
