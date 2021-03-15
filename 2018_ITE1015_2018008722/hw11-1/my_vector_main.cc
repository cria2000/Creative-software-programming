#include<iostream>
#include"my_vector.h"
#include<stdlib.h>
using namespace std;
int main(){
	int max_num;
	cin>>max_num;
	MyVector a(max_num);
	MyVector b(max_num);
	cout<<"enter a"<<endl;
	cin>>a;
	cout<<"enter b"<<endl;
	cin>>b;
	string vec_a, vec_b;
	string op;
	while(true){
		cin>>vec_a;
		if(vec_a=="quit")
			return 0;
		else{
			cin>>op>>vec_b;
			if(vec_b=="b"){
				if(op=="+"){
					MyVector c=a+b;
					cout<<c;
					//delete &c;
				}
				else if(op=="-"){
					MyVector c=a-b;
					cout<<c;
					//delete &c;
				}
			}
			else{
				int num=atoi(vec_b.c_str());
				if(op=="+"){
					MyVector c=a+num;
					cout<<c;
					//delete &c;
				}
				else if(op=="-"){
					MyVector c=a-num;
					cout<<c;
					//delete &c;
				}
			}
		}
	}
}
					

