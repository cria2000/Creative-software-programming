#include<iostream>
#include"simple_shape.h"

using namespace std;
int main(){
	Circle cir;
	Square squ;
	string input;
	while(1){
	cout<<"shape?"<<endl;
	cin>>input;
	if(input=="C"){
		cin>>cir.onx>>cir.ony>>cir.rad;
		cir.make_circle();
	}
	else if(input=="R"){
		cin>>squ.lx>>squ.ly>>squ.rx>>squ.ry;
		squ.make_square();}
	else if(input!="C"||input!="R"){
	return 0;}}
}


