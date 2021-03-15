#include<iostream>
#include "sort.h"
using namespace std;
int main(){
	int num;
	cin>>num;
	if(num==0||num<0){return 0;}
	int* input;
	input=(int*)malloc(sizeof(int)*num);
	for (int i=0;i<num;i++){
	cin>>input[i];}
	sorting(num,input);
	for(int j=0;j<num;j++){
		cout<<input[j]<<" " ;
	
	}
	cout<<endl;
	free(input);
}


	

	
