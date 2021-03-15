#include <iostream>
#include <vector>
#include "print_info.h"
using namespace std;
void printObjectTypeInfo1(A *object){
	cout<<object->getTypeInfo()<<endl;
}
void printObjectTypeInfo2(A& object){
	cout<<object.getTypeInfo()<<endl;
}
int main(){
	vector<A*>objects;
	objects.push_back(new A);
	objects.push_back(new B);
	objects.push_back(new C);
	for(A *object : objects){
		printObjectTypeInfo1(object);
		printObjectTypeInfo2(*object);
	}
	for (A *object : objects) delete object;
	return 0;
}
