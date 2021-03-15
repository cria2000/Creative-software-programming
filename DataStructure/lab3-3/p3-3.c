#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#define EmptyTOS (-1)
typedef struct StackRecord *Stack;
typedef struct IntStackRecord *IntStack;
struct StackRecord{
	int Capacity;
	int TopOfStack;
	char *Array;
};
//postfix로 바꾼 식을 계산하기 위해서 int형 array를 가지는 struct를 하나 더 생성(식 계산 시 stack을 사용하는데, 그 stack에 숫자를 넣게 될 때 int형으로 넣는 것이 나중 실제 계산할 때 편하기 때문)
struct IntStackRecord{
	int Capacity;
	int TopOfStack;
	int *Array;
};
//stack과 array에 동적할당을 해주기 위한 함수(동적할당이 제대로 안되었을 경우에 경고문을 출력할 파일의 포인터와 동적할당을 하기 위한 size를 받는다)-stack형
Stack CreateStack(FILE * f, int MaxElements){
	Stack S;
	S=malloc(sizeof(struct StackRecord));
	if(S==NULL)
		fprintf(f,"Out of Space!!!!!");
	S->Array=malloc(sizeof(char)*MaxElements);
	if(S->Array==NULL)
		fprintf(f,"Out of space!!!");
	S->Capacity=MaxElements;
	S->TopOfStack=EmptyTOS;
	return S;
}
//stack과 array에 동적할당을 해주기 위한 함수(동적할당이 제대로 안되었을 경우에 경고문을 출력할 파일의 포인터와 동적할당을 하기 위한 size를 받는다)-IntStack형
IntStack IntCreateStack(FILE *f, int MaxElements){
	IntStack S;
	S=malloc(sizeof(struct IntStackRecord));
	if(S==NULL)
		fprintf(f,"Out of space!!!");
	S->Array=malloc(sizeof(int)*MaxElements);
	if(S->Array==NULL)
		fprintf(f,"out of spzce!!!");
	S->Capacity=MaxElements;
	S->TopOfStack=EmptyTOS;
	return S;
}
//stack을 input으로 받아 stack에 push를 하기 전에 stack의 array가 다 차있나를 boolean으로 return해 확인하는 함수-stack형
bool IsFull(Stack S){
	if(S->TopOfStack==S->Capacity-1)
		return true;
	else
		return false;
}
//stack을 input으로 받아 stack에 push를 하기 전에 stack의 array가 다 차있나를 boolean으로 return해 확인하는 함수-IntStack형
bool IntIsFull(IntStack S){
	if(S->TopOfStack==S->Capacity-1)
		return true;
	else 
		return false;
}
//stack을 input으로 받아 stack에 pop을 하기 전에 stack의 array가 비어있는지를 boolean으로 return해 확인하는 함수-Stack형
bool IsEmpty(Stack S){
	if(S->TopOfStack<0)
		return true;
	else
		return false;
}
//stack을 input으로 받아 stack에 pop을 하기 전에 stack의 array가 비어있는지를 boolean으로 return해 확인하는 함수-IntStack형
bool IntIsEmpty(IntStack S){
	if(S->TopOfStack<0)
		return true;
	else
		return false;
}
//stack이 다 찼을 경우 경고문을 출력할 파일의 포인터와 집어넣을 값, 값이 들어가게 되는 stack을 input으로 받아 stack의 array에 값을 집어넣기 위한 함수(나중에 들어간 값이 가장 위로 온다)-Stack형
void Push(FILE *f, char X, Stack S){
	if(IsFull(S))
		fprintf(f,"Full\n");

	else
		S->Array[++S->TopOfStack]=X;
}
//stack이 다 찼을 경우 경고문을 출력할 파일의 포인터와 집어넣을 값, 값이 들어가게 되는 stack을 input으로 받아 stack의 array에 값을 집어넣기 위한 함수(나중에 들어간 값이 가장 위로 온다)-IntStack형
void IntPush(FILE *f, int X, IntStack S){
	if(IntIsFull(S))
		fprintf(f,"FULL\n");
	else 
		S->Array[++S->TopOfStack]=X;
}
//값이 하나도 없을 때 경고문을 출력할 파일의 포인터와 값을 pop할 stack을 input으로 받아 stack의 맨 위 값을 없애는 함수-Stack형
void Pop(FILE *f, Stack S){
	if(IsEmpty(S))
		fprintf(f,"Empty\n");
	else
		S->TopOfStack--;

}
//값이 하나도 없을 때 경고문을 출력할 파일의 포인터와 값을 pop할 stack을 input으로 받아 stack의 맨 위 값을 없애는 함수-IntStack형
void IntPop(FILE *f, IntStack S){
	if(IntIsEmpty(S))
		fprintf(f,"Empty\n");
	else 
		S->TopOfStack--;
}
//stack이 비어있을 경우 경고문을 출력할 파일의 포인터와 값을 가져올 stack을 input으로 받아 stack의 가장 위에 있는 값을 return하는 함수-Stack형
char Top(FILE *f, Stack S){
	if(!IsEmpty(S))
		return S->Array[S->TopOfStack];
	fprintf(f,"Empty\n");
	return 0;
}
//stack이 비어있을 경우 경고문을 출력할 파일의 포인터와 값을 가져올 stack을 input으로 받아 stack의 가장 위에 있는 값을 return하는 함수-IntStack형
int IntTop(FILE *f, IntStack S){
	if(!IntIsEmpty(S))
		return S->Array[S->TopOfStack];
	fprintf(f,"Empty\n");
	return 0;
}
//postfix로 정리하는 중인 식을 계산하는 함수. IntTop과 IntPop에 사용될 파일의 포인터와 pop할 stack, 연산기호를 input으로 받아 stack의 위 두개를 pop하고 연산기호가 뭐냐에 따라 실제 연산 수행 후 그 값을 return 한다. 
int Evaluate(FILE *f, IntStack S, char ans){
	int c;
	int a,b;
	b=IntTop(f,S);
	IntPop(f,S);
	a=IntTop(f,S);
	IntPop(f,S);
	if(ans=='+'){
		c=a+b;
	}
	else if(ans=='-'){
		c=a-b;
	}
	else if(ans=='*'){
		c=a*b;
	}
	else if(ans=='%'){
		c=a%b;
	}
	else if(ans=='/'){
		c=a/b;
	}
	return c;
}
int main(){
	FILE *f;
	FILE *f2;
	f=fopen("input.txt","r");
	f2=fopen("output.txt","w");
	Stack st;
	IntStack ev;
	st=CreateStack(f2, 100);
	ev=IntCreateStack(f2, 100);
	char *ans=(char*)malloc(sizeof(char)*100);
	fprintf(f2,"Infix Form : ");
	fscanf(f,"%s",ans);
	for(int i=0;i<100;i++){
		if(ans[i]!='#')
			fprintf(f2,"%c",ans[i]);
		else{
			fprintf(f2,"\n");
			break;
		}
	}
	fprintf(f2,"Postfix Form : ");
	for(int i=0;i<100;i++){
		if(ans[i]!='#'){
			if(ans[i]=='1'||ans[i]=='2'||ans[i]=='3'||ans[i]=='4'||ans[i]=='5'||ans[i]=='6'||ans[i]=='7'||ans[i]=='8'||ans[i]=='9'){
				fprintf(f2,"%c",ans[i]);
				IntPush(f2,atoi(&ans[i]),ev);
			}
			else if(ans[i]=='+'||ans[i]=='-'){
				if(st->Array[st->TopOfStack]==')'||st->Array[st->TopOfStack]=='('||IsEmpty(st)==true)
					Push(f2,ans[i],st);
			
				else{
					fprintf(f2,"%c",Top(f2,st));
					--i;
					IntPush(f2, Evaluate(f2,ev,Top(f2,st)), ev);
					Pop(f2,st);
				}
			}
			else if(ans[i]=='*'||ans[i]=='/'||ans[i]=='%'){
				if(st->Array[st->TopOfStack]!='*'||st->Array[st->TopOfStack]!='%'||st->Array[st->TopOfStack]!='/')
					Push(f2,ans[i],st);
				else{
					fprintf(f2,"%c",Top(f2,st));
					--i;
					IntPush(f2,Evaluate(f2,ev,Top(f2,st)),ev);
					Pop(f2,st);
				}
			}	
			else if(ans[i]=='(')
				Push(f2,ans[i],st);
			else if(ans[i]==')'){
				while(st->Array[st->TopOfStack]!='('){
					fprintf(f2, "%c", Top(f2,st));
					IntPush(f2,Evaluate(f2,ev,Top(f2,st)),ev);
					Pop(f2,st);}
				Pop(f2,st);
			}
		}
		else{
			while(IsEmpty(st)==false){
				fprintf(f2,"%c",Top(f2,st));
				IntPush(f2,Evaluate(f2,ev,Top(f2,st)),ev);
				Pop(f2,st);
			}
			fprintf(f2, "\n");
			break;
		}
	}
	fprintf(f2,"Evaluation Result : %d\n",IntTop(f2,ev));	
	free(ev->Array);
	free(ev);
	free(st->Array);
	free(st);
	free(ans);
	fclose(f);
	fclose(f2);
}
