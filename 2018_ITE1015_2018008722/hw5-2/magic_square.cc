#include<iostream>
int** make_square(int n,int** square){
	int i=0;
	int j=((n-1)/2);
	square[i][j]=1;
	for(int num=2;num<(n*n)+1;num++){
		if((i-1)<0&&(j+1)!=n){
			if(square[n-1][j+1]==0){
				square[n-1][j+1]=num;
				i=n-1;
				j=j+1;}
			else if(square[n-1][j+1]!=0){
				square[i+1][j]=num;
				i=i+1;}}
		else if((i-1)==0&&(j+1)==n){
			if(square[i-1][0]==0){
				square[i-1][0]=num;
				i=i-1;
				j=0;}
			else if(square[i][0]!=0){
				square[i+1][j]=num;
				i=i+1;}}
		else if((i-1)>0&&(j+1)==n){
			if(square[i-1][0]==0){
				square[i-1][0]=num;
				i=i-1;
				j=0;}
			else if(square[i][0]!=0){
				square[i+1][0]=num;
				i=i+1;}}
		else if((i-1)<0&&(j+1)==n){
			if(square[n-1][0]==0){
				square[n-1][0]=num;
				i=n-1;
				j=0;}
			else if(square[n-1][0]!=0){
				square[i+1][j]=num;
				i=i+1;}}
		else if((i-1)==0&&(j+1)<n){
			if(square[i-1][j+1]==0){
				square[i-1][j+1]=num;
				i=i-1;
				j=j+1;}
			else if(square[i-1][j+1]!=0){
				square[i+1][j]=num;
				i=i+1;}}
		else if((i-1)>0&&(j+1)<n){
			if(square[i-1][j+1]==0){
				square[i-1][j+1]=num;
				i=i-1;
				j=j+1;}
			else if(square[i-1][j+1]!=0){
				square[i+1][j]=num;
				i=i+1;}}
	
	}
		return square;}
