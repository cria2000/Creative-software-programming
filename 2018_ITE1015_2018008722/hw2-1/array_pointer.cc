#include<stdio.h>
int main(){
	double arr[5]={1.1,2.2,3.3,4.4,5.5};
	double* parr=arr;
	int a;

	for (a=0;a<5;a++){
		*(parr+a)=2*(*(parr+a));
		printf("%f\n",*(parr+a));

	}
	
}
