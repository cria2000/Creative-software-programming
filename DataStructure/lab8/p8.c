#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct HeapStruct *PriorityQueue;
struct HeapStruct{
	int Capacity;
	int Size;
	int *Elements;
};
//queue�� �� á������ Ȯ���ϴ� �Լ�. Ȯ���ϰ��� �ϴ� queue�� input���� �޾� �� �������� true�� return�Ѵ�.(Size�� Capacity�� ������ full)
bool IsFull(PriorityQueue H){
	if(H->Capacity==H->Size) return true;
	else return false;
}
//queue�� �ְ��� �ϴ� ���� �ش� ���� ���� queue�� �˸��޼����� ����� file�� �����͸� input���� �޾� queue�� ���� insert���ִ� �Լ�.
void Insert(int X,PriorityQueue H,FILE *f){
	int i;
	if(IsFull(H)){
		fprintf(f,"heap is full");
		return ;
	}
//�ְ��� �ϴ� �� X�� queue H�� �ִ����� Ȯ���ϰ�, �ִٸ� ���޼����� ����� �� insert���� �ʴ´�.
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
//ã���� �ϴ� ���� �� ���� ã�� queue�� �˸��޼����� ����� file�� �����͸� input���� �޾� for������ �ش� queue�� indexó������ Sizeũ�⸸�� index���� �� ã���� �ϴ� ���� X�� ��ġ�ϴ� ���� �ִ����� Ȯ���ϴ� �Լ�  
void Find(int X, PriorityQueue H,FILE *f){
	for(int i=0;i<H->Size;i++){
		if(H->Elements[i]==X){
			fprintf(f,"%d is in the heap\n",X);
			return ;
		}
	}
	fprintf(f,"%d is not in the heap\n",X);
}
//����ϰ��� �ϴ� queue�� ���� ����� file�� �����͸� input���� �޾� queue�� ������ ��� ������ִ� �Լ�. for���� ����Ͽ� queue�� ó������ Size��ŭ index�� ������Ű�鼭 ���� ����Ѵ�.
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
//input.txt �κ��� queue�� capacity�� �޾� queue�� Q�� Capacity�� ��������, ������ ������ ���ʴ�� �޴´�.
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


