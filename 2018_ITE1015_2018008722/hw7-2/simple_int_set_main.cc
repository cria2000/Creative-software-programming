#include<iostream>
#include<string>
#include<algorithm>
#include"simple_int_set.h"
using namespace std;

bool PerseSet(const string& str, set<int> *s){
	if(str.find("{")!=0) return false;	
	if(str.find("}")!=str.size()-1) return false;
	if(str.find(' ')!=1) return false;	
	if(str[str.size()-2]!=' ') return false;
	string a=str;
	int location;
	a.erase(0,1);
	a.pop_back();
	int size=count(a.begin(),a.end(),' ');
	for(int i=0;i<size-1;++i){
		location=a.find(" ");
		a.erase(location,1);
		int location1=a.find(" ");
		string b=a;
		b.erase(location1,(b.size()-1));
		(*s).insert(atoi(b.c_str()));
		a.erase(location,(location1-location));
	}
	return true;
}

size_t GetOperator(const string& str){
	auto op_pos=str.find_first_of("+");
	if(op_pos==string::npos) op_pos=str.find_first_of("*");
	if(op_pos==string::npos){
		auto temp=str.find_first_of("-");
		while(temp!=string::npos&&str.at(temp+1)!=' ')
			temp=str.find_first_of("-",temp+1);
		op_pos=temp;}
	return op_pos;
}
bool InputSet(set<int> *s0,set<int> *s1,string& op){
	s0->clear(),s1->clear();
	string line;
	getline(cin,line);
	auto op_pos=GetOperator(line);
	if(op_pos==string::npos) return false;
	else op=line.at(op_pos);
	return PerseSet(line.substr(0,op_pos - 1),s0)&&PerseSet(line.substr(op_pos+2),s1);
}
void PrintSet(set<int>& s){
	cout<<"{";
	for(auto it=s.begin();it!=s.end();++it) cout<<" "<<*it;
	cout<<" }"<<endl;}
int main(){
	set<int> s0,s1;
	string op;
	while(true){
		bool valid=InputSet(&s0,&s1,op);
		if(!valid) break;
		auto res = (op == "+") ? SetUnion(s0,s1):
			(op == "-") ? SetDifference(s0, s1):
			SetIntersection(s0, s1);
		PrintSet(res);
	}
	return 0;}


