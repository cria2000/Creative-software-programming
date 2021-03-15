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
//stack과 stack의 array에 동적할당을 해주고, 각 element들을 초기화해주기 위한 함수(동적할당이 제대로 이루어지지 않았을 경우 경고문을 표시할 파일의 포인터와 몇개의 element를 넣을 것인지 element의 개수를 input으로 받는다)
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
//stack을 input으로 받아 그 stack의 array가 가득 차있는지를 확인하여 boolean으로 return해주는 함수  
bool IsFull(Stack S){
	if(S->TopOfStack==S->Capacity-1)
		return true;
	else
		return false;
}
//stack을 input으로 받아 stack의 array가 비어있는지를 확인하여 boolean값으로 return해주는 함수 
bool IsEmpty(Stack S){
	if(S->TopOfStack<0)
		return true;
	else
		return false;
}
//skack이 가득 차있을 경우 경고문을 출력할 file의 포인터와 stack에 넣을 값, stack을 input으로 받아 stack의 array에 값을 넣고 TopOfStack의 값을 하나 증가시키는 함수
void Push(FILE *f, int X, Stack S){
	if(IsFull(S))
		fprintf(f,"Full\n");
	else 
		S->Array[++S->TopOfStack]=X;
}
//stack의 array가 비어있는 경우 경고문을 출력할 file의 포인터와 pop할 stack을 input으로 받고 가장 위에 있는 값을 pop시키는 함수
void Pop(FILE *f, Stack S){
	if(IsEmpty(S))
		fprintf(f,"Empty\n");
	else
		S->TopOfStack--;
	
}
//어떤 값이 pop되었는지를 알려주기 위한 함수로. stack의 array가 비어있을 경우 경고문을 출력할 file의 포인터와 Stack을 input으로 받아 stack의 가장 위쪽에 있는 값을 return한다.
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


