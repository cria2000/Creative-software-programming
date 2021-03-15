#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

typedef struct Element{
	int numberOfArr;
	int element;
}Element;
typedef struct HeapStruct{
	int size;
	Element *element;
}HeapStruct;
void sort(HeapStruct *heap, int child){
	if(child*2<=heap->size){
		if(heap->element[child].element>heap->element[child*2].element){
			int number;
			int arr;
			number=heap->element[child].element;
			arr=heap->element[child].numberOfArr;
			heap->element[child].element=heap->element[child*2].element;
			heap->element[child].numberOfArr=heap->element[child*2].numberOfArr;
			heap->element[child*2].element=number;
			heap->element[child*2].numberOfArr=arr;
		}
	}
	if((child*2)+1<=heap->size)
		if(heap->element[child].element>heap->element[(child*2)+1].element){
			int number;
			int arr;
			number=heap->element[child].element;
			arr=heap->element[child].numberOfArr;
			heap->element[child].element=heap->element[(child*2)+1].element;
			heap->element[child].numberOfArr=heap->element[(child*2)+1].numberOfArr;
			heap->element[(child*2)+1].element=number;
			heap->element[(child*2)+1].numberOfArr=arr;
		}
}
void heapSort(HeapStruct *heap){
	int index=heap->size;
	int child=heap->size;
	while(index!=0){
		child=index;
		if((index*2)<=heap->size){
			while(child*2<=heap->size){
				sort(heap,child);
				sort(heap,child+1);
				child=child*2;
			}
		}
		--index;
	}
}
int main(){
	FILE *f;
	f=fopen("input1-2.txt","r");
	int numOfArr;
	char input[100]; //help to file reading
	int arr[100][100]; //array that have initial numbers
	char *delete; //use to delete \n
	fscanf(f,"%d",&numOfArr);
	int numOfEle[numOfArr]; //the number of each array's element
	int orderOfEle[numOfArr]; //the order that we have to borrow
	for(int n=0;n<numOfArr;n++)
		orderOfEle[n]=0;
	fscanf(f, "%s",delete); //delete "\n"
	for(int i=0;i<numOfArr;i++){
		int j=0;
		fgets(input, 100, f);
		char* ptr=strtok(input, " ");
		while(ptr!=NULL){
			arr[i][j]=atoi(ptr);
			++j;
			ptr=strtok(NULL," ");
		}
		numOfEle[i]=j-1;
	}
	HeapStruct *heap=malloc(sizeof(HeapStruct));
	heap->element=malloc(sizeof(Element)*100);
	for(int k=1;k<numOfArr+1;k++){
		heap->element[k].element=arr[k-1][0];
		heap->element[k].numberOfArr=k-1;
	}
	heap->size=numOfArr;
	heapSort(heap);
	int element[10000];
	int m=0;
	while(1){
		element[m]=heap->element[1].element; //Choose the smallest
		if(numOfEle[heap->element[1].numberOfArr]>0){
			int ele=heap->element[heap->size].element;
			int number=heap->element[heap->size].numberOfArr;
			heap->element[heap->size].element=arr[heap->element[1].numberOfArr][orderOfEle[heap->element[1].numberOfArr]+1];
			heap->element[heap->size].numberOfArr=heap->element[1].numberOfArr;
			++orderOfEle[heap->element[1].numberOfArr];
			--numOfEle[heap->element[1].numberOfArr];
			heap->element[1].element=ele;
			heap->element[1].numberOfArr=number;
		}

		else if(numOfEle[heap->element[1].numberOfArr]<=0){
			int mini=1001;
			int l=0;
			for(int p=0;p<numOfArr;p++){
				if(numOfEle[p]>0){
					if(mini>arr[p][orderOfEle[p]+1]){
						mini=arr[p][orderOfEle[p]+1];
						l=p;
					}
				}
			}
			if(mini==1001) break;


				int ele=heap->element[heap->size].element;
				int number=heap->element[heap->size].numberOfArr;
				heap->element[heap->size].element=arr[l][orderOfEle[l]+1];
				heap->element[heap->size].numberOfArr=l;
				++orderOfEle[l];
				--numOfEle[l];
				heap->element[1].element=ele;
				heap->element[1].numberOfArr=number;
			}
		heapSort(heap);
		++m;
	}
	for(int s=0;s<numOfArr;s++){
		int heapElement=heap->element[heap->size].element;
		heap->element[heap->size]=heap->element[1];
		heap->element[1].element=heapElement;
		--heap->size;
		++m;
		heapSort(heap);
		element[m]=heap->element[1].element;
	}
	for(int h=0;h<m;h++){
		printf("%d ",element[h]);
	}
	printf("\n");
		
}
