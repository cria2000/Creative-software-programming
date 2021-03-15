#include<iostream>
void sorting (int num,int *s){
	int temp;
	for(int i=0;i<num-1;i++){
		for(int j=0;j<num-1;j++){
			if(s[j]>s[j+1]){
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;}}}
		
}		


