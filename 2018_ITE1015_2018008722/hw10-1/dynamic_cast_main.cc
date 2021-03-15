#include<iostream>
#include<vector>
#include"dynamic_cast.h"
using namespace std;
int main(){
	char ans;
	std::vector<B*> b;
	while(true){
		cin>>ans;
		if (ans=='B')
			b.push_back(new B);
		else if(ans=='C')
			b.push_back(new C);
		else if(ans=='D')
			b.push_back(new D);
		else if(ans=='0'){
			for(B *bb:b){
				if(dynamic_cast<D*>(bb)==NULL){
					if(dynamic_cast<C*>(bb)==NULL){
					}
					else dynamic_cast<C*>(bb)->test_C();
				}
				else dynamic_cast<D*>(bb)->test_D();
			}
			for(B *bb:b) delete bb;
			return 0;
		}
	}
}
					

