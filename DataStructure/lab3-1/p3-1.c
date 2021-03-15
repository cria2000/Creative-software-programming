#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#define EmptyTOS (-1)
typedef struct StackRecord *Stack;
struct StackRecord
{
	int Capacity;
	int TopOfStack;
	int *Array;
};
//stack�� stack�� array�� �����Ҵ��� ���ְ�, �� element���� �ʱ�ȭ���ֱ� ���� �Լ�(�����Ҵ��� ����� �̷������ �ʾ��� ��� ����� ǥ���� ������ �����Ϳ� ��� element�� ���� ������ element�� ������ input���� �޴´�)
Stack CreateStack(FILE * f, int MaxElements){
	Stack S;
	S=malloc(sizeof(struct StackRecord));
	if(S==NULL)
		fprintf(f,"Out of Space!!!!!");
	S->Array=malloc(sizeof(int)*MaxElements);
	if(S->Array==NULL)
		fprintf(f,"Out of space!!!");

	S->Capacity=MaxElements;
	S->TopOfStack=EmptyTOS;

	return S;
}
//stack�� input���� �޾� �� stack�� array�� ���� ���ִ����� Ȯ���Ͽ� boolean���� return���ִ� �Լ�  
bool IsFull(Stack S){
	if(S->TopOfStack==S->Capacity-1)
		return true;
	else
		return false;
}
//stack�� input���� �޾� stack�� array�� ����ִ����� Ȯ���Ͽ� boolean������ return���ִ� �Լ� 
bool IsEmpty(Stack S){
	if(S->TopOfStack<0)
		return true;
	else
		return false;
}
//skack�� ���� ������ ��� ����� ����� file�� �����Ϳ� stack�� ���� ��, stack�� input���� �޾� stack�� array�� ���� �ְ� TopOfStack�� ���� �ϳ� ������Ű�� �Լ�
void Push(FILE *f, int X, Stack S){
	if(IsFull(S))
		fprintf(f,"Full\n");
	else 
		S->Array[++S->TopOfStack]=X;
}
//stack�� array�� ����ִ� ��� ����� ����� file�� �����Ϳ� pop�� stack�� input���� �ް� ���� ���� �ִ� ���� pop��Ű�� �Լ�
void Pop(FILE *f, Stack S){
	if(IsEmpty(S))
		fprintf(f,"Empty\n");
	else
		S->TopOfStack--;
	
}
//� ���� pop�Ǿ������� �˷��ֱ� ���� �Լ���. stack�� array�� ������� ��� ����� ����� file�� �����Ϳ� Stack�� input���� �޾� stack�� ���� ���ʿ� �ִ� ���� return�Ѵ�.
int Top(FILE *f, Stack S){
	if(!IsEmpty(S))
		return S->Array[S->TopOfStack];
	fprintf(f,"Empty\n");
	return 0;
}
int main(){
	FILE *f;
	FILE *f2;
	f=fopen("input.txt","r");
	f2=fopen("output.txt","w");
	Stack st;
	st=CreateStack(f2,100);
	int num;
	char *ans;
	fscanf(f,"%d",&num);
	for(int i=0;i<num;i++){
		fscanf(f,"%s",ans);
		if(strcmp(ans,"push")==0){
			int array;
			fscanf(f,"%d",&array);
			Push(f2,array,st);
		}
		else if(strcmp(ans,"pop")==0){
			if(Top(f2, st)!=0){
				fprintf(f2,"%d\n",Top(f2,st));
				Pop(f2,st);
			}
		}
	}
	free(st->Array);
	free(st);
	fclose(f);
	fclose(f2);
}


