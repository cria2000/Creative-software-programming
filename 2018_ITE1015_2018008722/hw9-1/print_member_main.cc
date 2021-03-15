#include<iostream>
#include<vector>
#include"print_member.h"
using namespace std;
int main(){
	int a;
	double b;
	string c;
	cin>>a>>b>>c;
	vector<A*>objects;
	objects.push_back(new A(a));
	objects.push_back(new B(b));
	objects.push_back(new C(c));
	for (A *object : objects) object->print();
	for(A *object : objects) delete object;
	return 0;


}
