#include<iostream>
#include<string>
void swap(int& n1,int& n2){
	int p;
	p=n1;
	n1=n2;
	n2=p;}
void swap(std::string& s1,std::string& s2){
	std::string p;
	p=s1;
	s1=s2;
	s2=p;}
int main(){
	int n1,n2;
	std::string s1,s2;
	std::cin>>n1>>n2>>s1>>s2;
	std::cout<<"n1: "<<n1<<", n2: "<<n2<<", s1: "<<s1<<", s2: "<<s2<<std::endl;
	swap(n1,n2);
	swap(s1,s2);
	std::cout<<"n1: "<<n1<<", n2: "<<n2<<", s1: "<<s1<<", s2: "<<s2<<std::endl;

}

