#include<stdio.h>
int main(){
	char eng[10];
	scanf("%s",eng);
	for (int i=0;i<9;i++){
		if (63<eng[i]&&eng[i]<91){
			eng[i]=eng[i]+32;}
		else if(96<eng[i]&&eng[i]<123){
			eng[i]=eng[i]-32;}
		else 
			break;
	   
	}
	printf("%s\n",eng);

}

