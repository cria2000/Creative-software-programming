#include<iostream>
#include"animals.h"
using namespace std;
Animal::Animal(string _name, int _age){
	name=_name;
	age=_age;
}
Animal::~Animal(){
	name=" ";
	age=0;
}
void Animal::printInfo(){
}
Zebra::Zebra(string _name,int _age, int _numStripes):Animal(_name, _age){
	numStripes=_numStripes;
}
Zebra::~Zebra(){
	name=" ";
	age=0;
	numStripes=0;
}
void Zebra::printInfo(){
	cout<<"Zebra, Name: "<<name<<", Age: "<<age<<", Number of stripes: "<<numStripes<<endl;
}
Cat::Cat(string _name, int _age, string _favoriteToy):Animal(_name, _age){
	favoriteToy=_favoriteToy;
}
Cat::~Cat(){
	name=" ";
	age=0;
	favoriteToy=" ";
}
void Cat::printInfo(){
	cout<<"Cat, Name: "<<name<<", Age: "<<age<<", Favorite toy: "<<favoriteToy<<endl;
}


