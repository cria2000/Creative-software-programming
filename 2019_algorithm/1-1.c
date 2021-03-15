#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct HeapStruct{
	int size;
	int *element;
}HeapStruct;
void sort(HeapStruct *heap, int child){
	if(child*2<=heap->size){
		if(heap->element[child]<heap->element[child*2]){
			int number;
			number=heap->element[child];
			heap->element[child]=heap->element[child*2];
			heap->element[child*2]=number;
		}
	}
	if((child*2)+1<=heap->size)
		if(heap->element[child]<heap->element[(child*2)+1]){
			int number;
			number=heap->element[child];
			heap->element[child]=heap->element[(child*2)+1];
			heap->element[(child*2)+1]=number;
		}
}
void heapSort(HeapStruct *heap){
	int index=heap->size;
	int child=heap->size;
	while(index!=0){
		child=index;
		if((index*2)<=heap->size){
			while(child*2<=heap->size){
				sort(heap, child);
				sort(heap, child+1);
				child=child*2;
			}
		}
		--index;
	}
}

int main(){
	int num=0;
	int size=0;
	HeapStruct *max_heap;
	for(int i=0;i<100;i++){
		scanf("%d", &num);
		if(num!=-1){
			++size;
			max_heap->element[size]=num; //element starts at 1
		}
		else
			break;
	}
	max_heap->size=size;
	heapSort(max_heap);
	for(int k=1;k<size+1;k++){
		int arb;
		arb=max_heap->element[1];
		max_heap->element[1]=max_heap->element[max_heap->size];
		max_heap->element[max_heap->size]=arb;
		--max_heap->size;
		heapSort(max_heap);
	}
	for(int j=size;j>0;j--){
		printf("%d ", max_heap->element[j]);
	}
	printf("\n");
}
