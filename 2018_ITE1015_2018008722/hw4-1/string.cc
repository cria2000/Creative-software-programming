#include<iostream>
#include<string>
using namespace std;
int main(){
	string str1,str2;
	string addstr;
	cin>>str1>>str2;
	addstr=str1+str2;
	cout<<addstr<<endl;
	cout<<addstr[0]<<endl;
	cout<<addstr[addstr.length()-1]<<endl;
	return 0;
}


