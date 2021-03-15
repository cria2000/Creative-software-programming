#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
struct QueueRecord;
typedef struct QueueRecord *Queue;
struct QueueRecord{
	int Capacity;
	int Front;
	int Rear;
	int Size;
	int *Array;
};
//queue를 다 사용하고 난 후, 동적할당해주었던 값들을 해제시키고, queue의 값들을 처음으로 초기화시켜주는 함수로 main의 가장 마지막 부분에 사용이 된다
void MakeEmpty(Queue Q,int MaxElements){
	Q->Size=0;
	Q->Front=1;
	Q->Rear=0;
	free(Q->Array);
	free(Q);
}
//queue와 queue의 array에 동적할당을 해주고 나머지 element의 값도 초기화 해주는 함수로 동적할당이 잘못되었을 경우 경고문을 출력할 file의 포인터와 몇 개의 값을 받을 것인지를 input으로 받는다
Queue Createqueue(FILE *f, int MaxElements){
	Queue Q=malloc(sizeof(struct QueueRecord));
	if(Q==NULL)
		fprintf(f,"Out of space!!!");
	Q->Array=malloc(sizeof(int)*MaxElements);
	if(Q->Array==NULL)
		fprintf(f,"Out of space!!!");
	Q->Capacity=MaxElements;
	Q->Front=1;
	Q->Size=0;
	Q->Rear=0;
}
//queue를 input으로 받아 그 queue의 array가 가득 차있는지를 확인하고 boolean으로 그 값을 return 해주는 함수이다.
bool IsFull(Queue Q){
	if(Q->Size==Q->Capacity)
		return true;
	else if(Q->Size<Q->Capacity)
		return false;
}
//queue를 input으로 받아 그 queue의 array가 비어있는지를 확인하고 boolean으로 그 값을 return 해주는 함수이다
bool IsEmpty(Queue Q){
	if(Q->Size==0)
		return true;
	else
		return false;
}
//queue의 array가 가득 차있을 때 경고문을 출력할  file의 포인터와 넣을 값, queue를 input으로 받아 queue의 array의 가장 마지막에 값을 넣어주고 size와 rear도 하나씩 늘여주는 함수
void Enqueue(FILE *f, int X, Queue Q){
	if(IsFull(Q))
		fprintf(f,"Full\n");
	else{
		Q->Size++;
		Q->Rear=(Q->Rear+1)%Q->Capacity;
		Q->Array[Q->Rear]=X;
	}
}
//queue의 array가 비어있을 경우 경고문을 출력할 file의 포인터와 queue를 input으로 받고, queue의 size를 하나 줄이고 front를 하나 증가시켜 맨 앞의 값이 사라진 것 처럼 무시하게 만드는 함수
void Dequeue(FILE *f,Queue Q){
	if(IsEmpty(Q))
		fprintf(f,"Empty\n");
	else{
		fprintf(f,"%d\n",Q->Array[Q->Front]);
		Q->Size--;
		++Q->Front;
	}
}
int main(){
	FILE *f;
	FILE *f2;
	f=fopen("input.txt","r");
	f2=fopen("output.txt","w");
	Queue q;
	q=Createqueue(f2,100);
	int num;
	fscanf(f,"%d",&num);
	for(int i=0;i<num;i++){
		char *ans;
		fscanf(f,"%s",ans);
		if(strcmp(ans,"enQ")==0){
			int queue;
			fscanf(f,"%d",&queue);
			Enqueue(f2,queue,q);
		}
		else if(strcmp(ans,"deQ")==0){
			Dequeue(f2,q);
		}
	}
	MakeEmpty(q,100);
	fclose(f);
	fclose(f2);
}
