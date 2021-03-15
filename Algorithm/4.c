#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct element{
	int num;
	int value;
}Element;
typedef struct HeapStruct{
	int size;
	Element *element;
}HeapStruct;
Element* set;
void sort(HeapStruct *heap, int child){
	if(child*2<heap->size){
		if(heap->element[child].value>=heap->element[child*2].value){
			int number;
			int value;
			number=heap->element[child].num;
			value=heap->element[child].value;
			heap->element[child].num=heap->element[child*2].num;
			heap->element[child].value=heap->element[child*2].value;
			heap->element[child*2].num=number;
			heap->element[child*2].value=value;
		}
	}
	if((child*2)+1<heap->size)
		if(heap->element[child].value>=heap->element[(child*2)+1].value){
			int number;
			int value;
			number=heap->element[child].num;
			value=heap->element[child].value;
			heap->element[child].num=heap->element[(child*2)+1].num;
			heap->element[child].value=heap->element[(child*2)+1].value;
			heap->element[(child*2)+1].num=number;
			heap->element[(child*2)+1].value=value;
		}
}
void heapSort(HeapStruct *heap){
	int index=heap->size;
	int child=heap->size;
	if(heap->size==2){
		if(heap->element[0].value>heap->element[1].value){
			int num=heap->element[0].num;
			int val=heap->element[0].value;
			heap->element[0].num=heap->element[1].num;
			heap->element[0].value=heap->element[1].value;
			heap->element[1].num=num;
			heap->element[1].value=val;
		}
	}
	else{
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
	}}
}
Element ExtractMin(HeapStruct *heap){
	heapSort(heap);
	Element min;
	min=heap->element[0];
	heap->element[0].value=heap->element[heap->size-1].value;
	heap->element[0].num=heap->element[heap->size-1].num;
	heap->size=heap->size-1;
	return min;

}
void Dijkstra(int** edges, HeapStruct *heap, int size){
	while(heap->size>0){
		Element u=ExtractMin(heap);
		for(int i=0;i<size;i++){
			if(set[i].num==-1){
				set[i].num=u.num;
				set[i].value=u.value;
			
				break;
			}
		}
		for(int j=0;j<size;j++){
			if(edges[u.num][j]!=0){
				for(int k=0;k<heap->size;k++){
					if(heap->element[k].num==j && (heap->element[k].value)>(u.value+edges[u.num][j])){
					heap->element[k].value=u.value+edges[u.num][j];
			}}
		}}


	}
}
int main(){
	FILE* f=fopen("input4.txt","r");
	int nodeNum;
	fscanf(f, "%d", &nodeNum);
	int** edges=(int**)malloc(sizeof(int*)*nodeNum);
	for(int i=0;i<nodeNum;i++)
		edges[i]=(int*)malloc(sizeof(int)*nodeNum);
	for(int i=0;i<nodeNum;i++){//edge's node number starts from 0
		for(int j=0;j<nodeNum;j++){
			fscanf(f,"%d",&edges[i][j]);
		}
	}
	HeapStruct *heap=malloc(sizeof(HeapStruct));
	heap->size=nodeNum;
	set=malloc(sizeof(Element)*nodeNum);
	for(int i=0;i<heap->size;i++)
		set[i].num=-1;
	heap->element=malloc(sizeof(Element)*nodeNum);
	for(int i=0;i<nodeNum;i++){

		heap->element[i].value=1023;
		heap->element[i].num=i;
	}
	heap->element[0].value=0;
	Dijkstra(edges, heap, heap->size);
	Element key;
	for(int k=0;k<nodeNum;k++){
		key=set[k];
		int l;
		for(l=k-1;l>=0;l--){
			if(set[l].num>key.num)
				set[l+1]=set[l];
			else break;
		}
		set[l+1]=key;
	}
	for(int i=0;i<nodeNum;i++)
		printf("%d ", set[i].value);
	printf("\n");
	free(edges);
	free(set);
	free(heap->element);
	free(heap);
	fclose(f);
 }


	
