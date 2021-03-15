#include<stdio.h>
void min_max_sum(int* arr,int* min,int* max,int* sum){
	*min=arr[0];
	*max=arr[0];
	for (int i=0;i<5;i++){
		if (arr[i]<*min){
			*min=arr[i];}
		else if (arr[i]>*max){
			*max=arr[i];
		}
		*sum=*sum+arr[i];
	
	}

	

}
int main(){

	int a,b,c,d,e;
	int min,max,sum;
	scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
	int arr[5]={a,b,c,d,e};
	min_max_sum(arr,&min,&max,&sum);
	printf("min: %d\nmax: %d\nsum: %d\n",min,max,sum);
}
