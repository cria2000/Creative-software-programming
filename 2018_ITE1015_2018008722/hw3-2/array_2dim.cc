#include<stdio.h>
int main(){

	int arr[3][2];
	int sum1=0,sum2=0;
	for(int i=0;i<3;i++){
		scanf("%d %d",&arr[i][0],&arr[i][1]);}
	for (int j=0;j<3;j++){
		printf("%d %d\n",arr[j][0],arr[j][1]);
		sum1=sum1+arr[j][0];	
		sum2=sum2+arr[j][1];}
	printf("sum of the 1st column: %d\nsum of the 2nd column: %d\n",sum1,sum2);


}
