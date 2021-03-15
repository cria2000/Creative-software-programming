#include<iostream>
#include"number.h"
using namespace std;
int main(){
	string ans;
	int num;
	while(ans!="quit"){
		cin>>ans;
		if(ans=="number"){
			cin>>num;
			Number number(num);
			cout<<"getNumber(): "<<number.getNumber()<<endl;}
		else if(ans=="square"){
			cin>>num;
			Square square;
			square.setNumber(num);
			square.getSquare();
			cout<<"getNumber(): "<<square.getNumber()<<endl;
			cout<<"getSquare(): "<<square.getSquare()<<endl;}
		else if(ans=="cube"){
			cin>>num;
			Cube cube;
			cube.setNumber(num);
			cube.getCube();
			cout<<"getNumber(): "<<cube.getNumber()<<endl;
			cout<<"getSquare(): "<<cube.getSquare()<<endl;
			cout<<"getCube(): "<<cube.getCube()<<endl;}}}


			
