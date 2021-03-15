#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct HeapStruct *PriorityQueue;
struct HeapStruct{
	int Capacity;
	int Size;
	int *Elements;
};
//queue가 다 찼는지를 확인하는 함수. 확인하고자 하는 queue를 input으로 받아 다 차있으면 true를 return한다.(Size와 Capacity가 같으면 full)
bool IsFull(PriorityQueue H){
	if(H->Capacity==H->Size) return true;
	else return false;
}
//queue에 넣고자 하는 값과 해당 값을 넣은 queue와 알림메세지를 출력할 file의 포인터를 input으로 받아 queue에 값을 insert해주는 함수.
void Insert(int X,PriorityQueue H,FILE *f){
	int i;
	if(IsFull(H)){
		fprintf(f,"heap is full");
		return ;
	}
//넣고자 하는 값 X가 queue H에 있는지를 확인하고, 있다면 경고메세지를 출력한 후 insert하지 않는다.
	for(int i=0;i<H->Size;i++){
		if(H->Elements[i]==X){
			fprintf(f,"%d is already in the tree.\n",X);
			return ;
		}
	}
	for(i=++H->Size;H->Elements[i/2]<X;i/=2){
			H->Elements[i]=H->Elements[i/2];
			if(i==0) break;
	}
		H->Elements[i]=X;
		fprintf(f,"insert %d\n",X);
	
}
//찾고자 하는 값과 그 값을 찾을 queue와 알림메세지를 출력할 file의 포인터를 input으로 받아 for문으로 해당 queue의 index처음부터 Size크기만한 index까지 중 찾고자 하는 값인 X와 일치하는 값이 있는지를 확인하는 함수  
void Find(int X, PriorityQueue H,FILE *f){
	for(int i=0;i<H->Size;i++){
		if(H->Elements[i]==X){
			fprintf(f,"%d is in the heap\n",X);
			return ;
		}
	}
	fprintf(f,"%d is not in the heap\n",X);
}
//출력하고자 하는 queue와 값을 출력할 file의 포인터를 input으로 받아 queue의 값들을 모두 출력해주는 함수. for문을 사용하여 queue의 처음부터 Size만큼 index를 증가시키면서 값을 출력한다.
void Print(PriorityQueue H,FILE *f){
	for(int i=0;i<H->Size;i++){
		fprintf(f,"%d ",H->Elements[i]);
	}
	fprintf(f,"\n");
}
int main(){
	FILE *f;
	FILE *f2;
	f=fopen("input.txt","r");
	f2=fopen("output.txt","w");
	int capacity;
	PriorityQueue Q;
//input.txt 로부터 queue의 capacity를 받아 queue인 Q의 Capacity에 저장한후, 나머지 값들을 차례대로 받는다.
	fscanf(f,"%d",&capacity);
	Q->Elements=malloc(sizeof(int)*capacity);
	Q->Capacity=capacity;
	Q->Size=0;
	char ans;
	while(fscanf(f,"%c",&ans)!=EOF){
		fscanf(f,"%c",&ans);
		int num;
		if(ans=='i'){
			fscanf(f,"%d",&num);
			Insert(num,Q,f2);
		}
		else if(ans=='f'){
			fscanf(f,"%d",&num);
			Find(num,Q,f2);
		}
		else if(ans=='p') 
			Print(Q,f2);
	}
	fclose(f);
	fclose(f2);
	free(Q->Elements);

}


