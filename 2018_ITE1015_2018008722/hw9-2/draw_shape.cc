#include<iostream>
#include"draw_shape.h"
using namespace std;
Canvas::Canvas(const size_t row, const size_t col){
	_row=row;
	_col=col;
	_canvas=new char*[row];
	for(int i=0;i<row;i++)
			_canvas[i]=new char[col]; 
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			_canvas[i][j]='.';
		}}

}
Canvas::~Canvas(){
	delete _canvas;
}
void Canvas::Resize(const size_t row, const size_t col){
	_row=row;
	_col=col;
	_canvas=new char*[row];
	for(int i=0;i<row;i++)
		_canvas[i]=new char[col];
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			_canvas[i][j]='.';
}
bool Canvas::DrawPixel(const int x, const int y, const char brush){
	if(x<_col&&y<_row){
	       _canvas[y][x]=brush;
	       return true;}
	else
		return false;

}
void Canvas::Print() const{
	cout<<" ";
	for(int i=0;i<_col;i++) cout<<i%10;
	cout<<endl;
	for(int i=0;i<_row;i++){
		cout<<i%10;

		for(int j=0;j<_col;j++){
			cout<<_canvas[i][j];}
		cout<<endl;}

}
void Canvas::Clear(){
	for(int i=0;i<_row;i++)
		for(int j=0;j<_col;j++)
			_canvas[i][j]='.';
}
Shape::Shape(int x, int y, char brush){
	_x=x;
	_y=y;
	_brush=brush;
}
Rectangle::Rectangle(int x,int y, int height, int width, char brush):Shape(x,y,brush){
	_height=height;
	_width=width;
}
void Rectangle::Draw(Canvas* canvas) const{
	if(canvas->DrawPixel(_x,_y,_brush)==true){
	for(int i=_y;i<_y+_height;i++)
		for(int j=_x;j<_x+_width;j++)
			if(i<canvas->_row&&j<canvas->_col)
			if((i>_y||i==_y)&&(j>_x||j==_x))
				if(i<_y+_height&&j<_x+_width)
					canvas->_canvas[i][j]=_brush;
	}
}
void Rectangle::printInfo() const{
	cout<<"rect "<<_x<<" "<<_y<<" " <<_height<<" " <<_width<<" " <<_brush<<endl;
}
UpTriangle::UpTriangle(int x, int y, int height, char brush):Shape(x,y,brush){
	_height=height;
}
void UpTriangle::Draw(Canvas* canvas) const{
	if(canvas->DrawPixel(_x,_y,_brush)==true){
	for(int i=0;i<(2*_height+1)/2;i++){
		for(int j=-i;j<i+1;j++){
			if(_x+j<canvas->_col&&_x+j>-1){
				canvas->_canvas[_y+i][_x+j]=_brush;}}}
	}
}
void UpTriangle::printInfo() const{
	cout<<"tri_up "<<_x<<" "<<_y<<" "<<_height<<" "<<_brush<<endl;
}
DownTriangle::DownTriangle(int x, int y, int height, char brush):Shape(x,y,brush){
	_height=height;
}
void DownTriangle::Draw(Canvas* canvas) const{
	if(canvas->DrawPixel(_x,_y,_brush)==true){
	for(int i=0;i<(2*_height+1)/2;i++)
		for(int j=-i;j<i+1;j++)
			if((_y-i)<canvas->_row&&(_x+j)<canvas->_col)
				canvas->_canvas[_y-i][_x+j]=_brush;}
}
void DownTriangle::printInfo() const{
	cout<<"tri_down "<<_x<<" "<<_y<<" "<<_height<<" "<<_brush<<endl;
}
Diamond::Diamond(int x, int y, int distance, char brush):Shape(x,y,brush){
	_distance=distance;
}
void Diamond::Draw(Canvas* canvas) const{
	if(canvas->DrawPixel(_x,_y,_brush)==true){
	for(int i=0;i<(2*_distance+1)/2;i++){
		for(int j=-i;j<i+1;j++){
			if(_x+j<canvas->_col&&_x+j>-1){
				canvas->_canvas[_y+i][_x+j]=_brush;
				if((_y+(2*_distance)-i)<canvas->_row&&(_x+j)<canvas->_col){
					canvas->_canvas[_y+(2*_distance)-i][_x+j]=_brush;}
			}}}
	for(int i=-_distance;i<_distance+1;i++)
		if(_x+i<canvas->_col&&_x+i>-1)
			canvas->_canvas[_y+_distance][_x+i]=_brush;
	}
}
void Diamond::printInfo() const{
	cout<<"diamond "<<_x<<" "<<_y<<" "<<_distance<<" "<<_brush<<endl;
}

