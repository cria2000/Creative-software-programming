#include<iostream>
#include"draw_shape.h"
using namespace std;
double Rectangle::GetArea(){
	return (_height*_width);
}
int Rectangle::GetPerimeter(){
	return 2*(_height+_width);
}
void Rectangle::Draw(int canvas_width, int canvas_height){
	char canvas[canvas_width][canvas_height];
	cout<<" ";
	for(int i=0;i<canvas_width;i++) cout<<i%10;
	cout<<endl;
	for(int j=0;j<canvas_height;j++){
		cout<<j%10;
		for(int k=0;k<canvas_width;k++){
			if((j>_y||j==_y)&&(k>_x||k==_x)){
				if(j<_y+_height&&k<_x+_width)
					cout<<_brush;
				else cout<<".";
			}
			else cout<<".";
		}
		cout<<endl;
	}
}
double Square::GetArea(){
	return _width*_width;
}
int Square::GetPerimeter(){
	return 4*_width;
}
void Square::Draw(int canvas_width, int canvas_height){
	cout<<" ";
	for(int i=0;i<canvas_width;i++) cout<<i%10;
	cout<<endl;
	for(int j=0;j<canvas_height;j++){
		cout<<j%10;
		for(int k=0;k<canvas_width;k++){
			if((j>_y||j==_y)&&(k>_x||k==_x)){
				if(j<_y+_width&&k<_x+_width)
					cout<<_brush;
				else cout<<".";
			}
			else cout<<".";
		}
		cout<<endl;
	}
}
double Diamond::GetArea(){
	return (2*_distance)*(2*_distance)/2;
}
int Diamond::GetPerimeter(){
	return 4*(2*_distance);
}
void Diamond::Draw(int canvas_width, int canvas_height){
	char arr[canvas_height][canvas_width];
	char bru='.';
	for(int i=0;i<canvas_height;i++)
		for(int j=0;j<canvas_width;j++)
			arr[i][j]=bru;
	cout<<" ";
	for(int i=0;i<canvas_width;i++) cout<<i%10;
	cout<<endl;
	if(_y<canvas_height+1&&_x<canvas_width+1){
	for(int m=0;m<(2*_distance+1)/2;m++){
		for(int n=-m;n<m+1;n++){
			if(_x+n<canvas_width&&_x+n>-1){
			arr[_y+m][_x+n]=_brush;
			if((_y+(2*_distance)-m)<canvas_height&&(_x+n)<canvas_width){
			arr[_y+(2*_distance)-m][_x+n]=_brush;}
		}}}
	for(int m=-_distance;m<_distance+1;m++){
		if(_x+m<canvas_width&&_x+m>-1){
		arr[_y+_distance][_x+m]=_brush;}}}
	for(int j=0;j<canvas_height;j++){
		cout<<j%10;
		for(int k=0;k<canvas_width;k++){
			cout<<arr[j][k];}
		cout<<endl;
	}

}
jvi 
