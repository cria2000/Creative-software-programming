#include<iostream>
#include<vector>
#include"integer_set.h"
#include<algorithm>
using namespace std;
IntegerSet::IntegerSet(){vector<int> numbers_;}
IntegerSet::~IntegerSet(){numbers_.clear();}
void IntegerSet::AddNumber(int num){
	int j=0;
	for(int i=0;i<numbers_.size();i++)
		if(numbers_[i]==num)
			j+=1;
	if(j==0)
		numbers_.push_back(num);
	sort(numbers_.begin(),numbers_.end());
}
void IntegerSet::DeleteNumber(int num){
	for(int i=0;i<numbers_.size();i++){
		if(numbers_[i]==num)
			numbers_.erase(numbers_.begin()+i);}}
int IntegerSet::GetItem(int pos) const{
	if(pos<numbers_.size())
		return numbers_[pos];
	else return -1;}
vector<int> IntegerSet::GetAll() const{
	return numbers_;}
