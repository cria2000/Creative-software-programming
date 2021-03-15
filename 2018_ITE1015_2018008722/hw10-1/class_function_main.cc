#include<iostream>
#include<vector>
#include"class_function.h"
using namespace std;
int main(){
	string ans;
	std::vector<A*> a;
	while(true){
		cin>>ans;
		if(ans=="B"){
			a.push_back(new B);}

		else if(ans=="C"){
			a.push_back(new C);}

		else if(ans=="BB"){
			a.push_back(new BB);}

		else if(ans=="0"){
			for(A *aa:a){
			       	aa->test1();
				aa->test2();
			}
			for(A *aa:a) delete aa;
			return 0;
		}
	}
}


