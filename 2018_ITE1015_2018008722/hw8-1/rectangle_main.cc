#include<iostream>
#include"rectangle.h"
using namespace std;
int main(){
	string ans;
	int height;
	int width;
	while(ans!="quit"){
		cin>>ans;
		if(ans=="square"){
			cin>>width;
			Square square(width);
			square.print();}
		else if(ans=="nonsquare"){
			cin>>height>>width;
			NonSquare nonsquare(height,width);
			nonsquare.print();
		}}}

