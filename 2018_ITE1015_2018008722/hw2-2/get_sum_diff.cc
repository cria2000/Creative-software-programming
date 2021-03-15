#include<stdio.h>
void getSumDiff(int a,int b,int* pSum,int* pDiff){
	*(pSum)=a+b;
	*(pDiff)=a-b;}
int main(void){
	int x,y;
	int pSum,pDiff;
	scanf("%d %d", &x,&y);

	getSumDiff(x,y,&pSum,&pDiff);
	printf("Sum:%d\n",pSum);
	printf("diff:%d\n",pDiff);


}
