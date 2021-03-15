#include<iostream>
using namespace std;
int main(int argc,char* argv[]){
	int num=0;
	string str="";
	for(int i=1;i<argc;i++){
		if(atoi(argv[i])!=0){
			num=num+atoi(argv[i]);}
		if(atoi(argv[i])==0){
			str=str+argv[i];}
	}
	cout<<str<<endl<<num<<endl;}
