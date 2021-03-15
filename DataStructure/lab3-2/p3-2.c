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
//queue�� �� ����ϰ� �� ��, �����Ҵ����־��� ������ ������Ű��, queue�� ������ ó������ �ʱ�ȭ�����ִ� �Լ��� main�� ���� ������ �κп� ����� �ȴ�
void MakeEmpty(Queue Q,int MaxElements){
	Q->Size=0;
	Q->Front=1;
	Q->Rear=0;
	free(Q->Array);
	free(Q);
}
//queue�� queue�� array�� �����Ҵ��� ���ְ� ������ element�� ���� �ʱ�ȭ ���ִ� �Լ��� �����Ҵ��� �߸��Ǿ��� ��� ����� ����� file�� �����Ϳ� �� ���� ���� ���� �������� input���� �޴´�
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
//queue�� input���� �޾� �� queue�� array�� ���� ���ִ����� Ȯ���ϰ� boolean���� �� ���� return ���ִ� �Լ��̴�.
bool IsFull(Queue Q){
	if(Q->Size==Q->Capacity)
		return true;
	else if(Q->Size<Q->Capacity)
		return false;
}
//queue�� input���� �޾� �� queue�� array�� ����ִ����� Ȯ���ϰ� boolean���� �� ���� return ���ִ� �Լ��̴�
bool IsEmpty(Queue Q){
	if(Q->Size==0)
		return true;
	else
		return false;
}
//queue�� array�� ���� ������ �� ����� �����  file�� �����Ϳ� ���� ��, queue�� input���� �޾� queue�� array�� ���� �������� ���� �־��ְ� size�� rear�� �ϳ��� �ÿ��ִ� �Լ�
void Enqueue(FILE *f, int X, Queue Q){
	if(IsFull(Q))
		fprintf(f,"Full\n");
	else{
		Q->Size++;
		Q->Rear=(Q->Rear+1)%Q->Capacity;
		Q->Array[Q->Rear]=X;
	}
}
//queue�� array�� ������� ��� ����� ����� file�� �����Ϳ� queue�� input���� �ް�, queue�� size�� �ϳ� ���̰� front�� �ϳ� �������� �� ���� ���� ����� �� ó�� �����ϰ� ����� �Լ�
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
