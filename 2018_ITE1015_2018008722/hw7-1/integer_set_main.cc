#include<iostream>
#include<vector>
#include"integer_set.h"
using namespace std;
int main(){
	string answer;
	int integer;
	IntegerSet();
	IntegerSet is;
	vector<int> is2;
	while(1){
		cin>>answer;
		if(answer=="quit") return 0;
		else if(answer=="add"){
			cin>>integer;
			is.AddNumber(integer);
			is2=is.GetAll();
			for(int i=0;i<is2.size();i++)
				cout<<is2[i]<<" ";
			cout<<endl;
		}
		else if(answer=="del"){
			cin>>integer;
			is.DeleteNumber(integer);
			is2=is.GetAll();
			for(int i=0;i<is2.size();i++)
				cout<<is2[i]<<" ";
			cout<<endl;}
		else if(answer=="get"){
			cin>>integer;
			cout<<is.GetItem(integer);
			cout<<endl;}

	}
	is.~IntegerSet();
}
