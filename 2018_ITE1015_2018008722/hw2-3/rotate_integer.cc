#include<stdio.h>
void rotateLeft(int* pa,int* pb,int* pc){
	int a;
	a=*pa;
	*pa=*pb;
	*pb=*pc;
	*pc=a;}

void rotateRight(int* pa,int* pb,int* pc){
	int a;
	a=*pc;
	*pc=*pb;
	*pb=*pa;
	*pa=a;}

int main(void){
	int a=10,b=20,c=30;
	int input=1;
	printf("%d:%d:%d\n",a,b,c);
	while(input==1||input==2){
		scanf("%d",&input);
		if (input==1){
			rotateLeft(&a,&b,&c);
			printf("%d:%d:%d\n",a,b,c);}
		else if (input==2){
			rotateRight(&a,&b,&c);
			printf("%d:%d:%d\n",a,b,c);}
		else 
			break;
	}
}



