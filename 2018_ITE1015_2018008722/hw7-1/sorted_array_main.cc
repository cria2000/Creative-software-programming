#include<iostream>
#include"sorted_array.h"
#include<vector>
#include<stdlib.h>
#include<string.h>

using namespace std;
int main(){
	string answer;
	SortedArray();
	SortedArray sa;
	vector<int> arr;
	while(1){
		cin>>answer;
		if(answer=="ascend"){
			arr=sa.GetSortedAscending();
			for(int i=0;i<arr.size();i++)
				cout<<arr[i]<<" ";
			cout<<endl;
		}
		else if(answer=="descend"){
			arr=sa.GetSortedDescending();
			for(int i=0;i<arr.size();i++)
				cout<<arr[i]<<" ";
			cout<<endl;
		}
		else if(answer=="max"){
			cout<<sa.GetMax()<<endl;}
		else if(answer=="min"){
			cout<<sa.GetMin()<<endl;}
		else if(answer=="quit")
			return 0;
		else{
			sa.AddNumber(atoi(answer.c_str()));}
	}
	sa.~SortedArray();
}
