#include<iostream>

using namespace std;
int main(){
	int num;
	cin>>num;
	int* numPtr;
	numPtr=(int *)malloc(sizeof(int)*num);
	int a[num];
	*numPtr=*a;
	for(int i=0;i<num;i++){
		a[i]=i;
	cout<<a[i]<<" ";}
	cout<<endl;
	
	free(numPtr);
}

