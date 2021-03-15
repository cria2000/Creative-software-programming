#include<iostream>
#include"magic_square.h"
using namespace std;
int main(int argc,char *argv[]){
	int n=atoi(argv[1]);
	if(n<3||n%2==0){
		return 0;}
	int **square;
	square=(int **)malloc(sizeof(int *)*n);
	for(int i=0;i<n;i++){
		square[i]=(int *)malloc(sizeof(int)*n);
	}
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			square[a][b]=0;
		}}
	square=make_square(n,square);
	for(int j=0;j<n;j++){
		for(int k=0;k<n;k++){
			cout<<square[j][k]<<" ";
		}
	cout<<endl;}
	free(square);
}

		
