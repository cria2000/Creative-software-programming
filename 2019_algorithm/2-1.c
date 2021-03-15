#include<stdio.h>
#include<time.h>       
#include<stdlib.h>
int Partition(int* arr, int start, int end){
	int i=start-1;
	int num;
	int x=arr[end];
	for(int j=start; j<end; j++){
		if(arr[j]<=x){
			i=i+1;
			num=arr[j];
			arr[j]=arr[i];
			arr[i]=num;
		}
	}
	num=arr[end];
	arr[end]=arr[i+1];
	arr[i+1]=num;
	return i+1;
}
int RandPartition(int* arr, int start, int end){
	int num;
	int first, mid, last;
	srand(time(NULL));
	first=rand()%(end-start)+start+1;
	mid=rand()%(end-start)+start+1;
	last=rand()%(end-start)+start+1;
	if(end-start>2){
		while(first==mid || first==last || mid==last){
			first=rand()%(end-start)+start+1;
			mid=rand()%(end-start)+start+1;
			last=rand()%(end-start)+start+1;		
		}
	}		
	int pivot; //pivot's index
	if(first<=mid && mid<=last){
		pivot=mid;
	}
	else if(first<=last && last<=mid){
		pivot=last;
	}
	else if(mid<=first && first<=last){
		pivot=first;
	}
	else if(mid<=last && last<=first){
		pivot=last;
	}
	else if(last<=first && first<=mid){
		pivot=first;
	}
	else if(last<=mid && mid<=first){
		pivot=mid;
	}
	num=arr[end];
	arr[end]=arr[pivot];
	arr[pivot]=num;
	return Partition(arr, start, end);
}
	
int* QuickSort(int* arr, int start, int end){
	int q;
	if(start<end){
	q=RandPartition(arr, start, end);
	QuickSort(arr, start, q-1);
	QuickSort(arr, q+1, end);
	}
	return arr;
}
int main(){
	FILE *f;
	FILE *f2;
	f=fopen("input2-1.txt","r");
	f2=fopen("output2-1.txt","w");
	int* arr=malloc(sizeof(int )*2000000);
	int num;
	int index=0; //arr's max index is index's value 
	while(fscanf(f,"%d",&num)!=EOF){
		arr[index]=num;
		++index;
	}
	index=index-1;
	clock_t start,end;
	float delay;
	start=clock();
	if(index>9){
		arr=QuickSort(arr, 0, index);
	}
	else if(index<=9){
		int key,num;
		for(int j=1;j<index+1;j++){
			key=arr[j];
			num=j-1;
			while(num>-1 && arr[num]>key){
				arr[num+1]=arr[num];
				num=num-1;
			}
			arr[num+1]=key;
		}
	}
	end=clock();
	delay=(float)(end-start);
	for(int k=0;k<index+1;k++){
		fprintf(f2, "%d ", arr[k]);
	}
	fprintf(f2, "\n%f s",delay);
	fclose(f);
	fclose(f2);
	free(arr);
}
