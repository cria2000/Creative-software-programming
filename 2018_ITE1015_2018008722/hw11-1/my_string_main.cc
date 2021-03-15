#include<iostream>
#include"my_string.h"
#include<stdlib.h>
using namespace std;
int main(){
	MyString a, b;
	string str_a, str_b, op;
	cout<<"enter a"<<endl;
	cin>>a;
	cout<<"enter b"<<endl;
	cin>>b;
	while(true){
		cin>>str_a;
		if(str_a=="quit")
			return 0;
		else if(str_a=="a"){
			cin>>op>>str_b;
			if(op=="+"){
				if(str_b=="a"){
					MyString c=(a+a);
					cout<<c;
					
				}
				else if(str_b=="b"){
					MyString c=(a+b);
					cout<<c;
				}
				
			}
			
			else if(op=="*"){
				int num=atoi(str_b.c_str());
				MyString c=(a*num);
				cout<<c;
		//		delete &c;
			}

		}
		else if(str_a=="b"){
			cin>>op>>str_b;
			if(op=="+"){
				if(str_b=="a"){
					MyString c=(b+a);
					cout<<c;
				}
				else if(str_b=="b"){
					MyString c=(b+b);
					cout<<c;
				}
			}
			else if(op=="*"){
				int num=atoi(str_b.c_str());
				MyString c=(b*num);
				cout<<c;
			}
		}
	}
}

	

