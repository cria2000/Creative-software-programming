#include<iostream>
#include<string>

int add(int a,int b){
	return a+b;}

std::string add(std::string a,std::string b){
	return a+"-"+b;}
using namespace std;
int main(){
	int a,b;
	string str1,str2;
	cin>>a>>b>>str1>>str2;
	cout<<add(a,b)<<endl;
	cout<<add(str1,str2)<<endl;
}
