#include<iostream>
#include"sorted_array.h"
#include<vector>
#include<algorithm>
using namespace std;
SortedArray::SortedArray(){vector<int> numbers_;}
SortedArray::~SortedArray(){for(int i=0;i<numbers_.size();i++)
	numbers_.pop_back();}
void SortedArray::AddNumber(int num){
	numbers_.push_back(num);}
vector<int> SortedArray::GetSortedAscending() const{ 
	int temp;
	vector<int> numbers=numbers_;
	sort(numbers.begin(),numbers.end());
		return numbers;}
vector<int> SortedArray::GetSortedDescending() const{
	int temp;
	vector<int> numbers=numbers_;
	sort(numbers.rbegin(),numbers.rend());
		return numbers;}
int SortedArray::GetMax() const {
	vector<int> arr= GetSortedDescending();
	return arr[0];
}
int SortedArray::GetMin() const{
	vector<int> arr=GetSortedAscending();
	return arr[0];
}




