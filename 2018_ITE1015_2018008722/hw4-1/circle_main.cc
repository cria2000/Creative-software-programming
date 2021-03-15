#include<iostream>
#include"circle.h"

using namespace std;
int main(){

	double rad;
	cin>>rad;
	cout<<fixed;
	cout.precision(6);
	cout<<"Perimeter : "<<getCirclePerimeter(rad)<<endl;
	cout<<"Area : "<<getCircleArea(rad)<<endl;}

