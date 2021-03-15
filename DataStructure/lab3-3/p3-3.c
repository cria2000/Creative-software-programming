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
//postfix�� �ٲ� ���� ����ϱ� ���ؼ� int�� array�� ������ struct�� �ϳ� �� ����(�� ��� �� stack�� ����ϴµ�, �� stack�� ���ڸ� �ְ� �� �� int������ �ִ� ���� ���� ���� ����� �� ���ϱ� ����)
struct IntStackRecord{
	int Capacity;
	int TopOfStack;
	int *Array;
};
//stack�� array�� �����Ҵ��� ���ֱ� ���� �Լ�(�����Ҵ��� ����� �ȵǾ��� ��쿡 ����� ����� ������ �����Ϳ� �����Ҵ��� �ϱ� ���� size�� �޴´�)-stack��
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
//stack�� array�� �����Ҵ��� ���ֱ� ���� �Լ�(�����Ҵ��� ����� �ȵǾ��� ��쿡 ����� ����� ������ �����Ϳ� �����Ҵ��� �ϱ� ���� size�� �޴´�)-IntStack��
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
//stack�� input���� �޾� stack�� push�� �ϱ� ���� stack�� array�� �� ���ֳ��� boolean���� return�� Ȯ���ϴ� �Լ�-stack��
bool IsFull(Stack S){
	if(S->TopOfStack==S->Capacity-1)
		return true;
	else
		return false;
}
//stack�� input���� �޾� stack�� push�� �ϱ� ���� stack�� array�� �� ���ֳ��� boolean���� return�� Ȯ���ϴ� �Լ�-IntStack��
bool IntIsFull(IntStack S){
	if(S->TopOfStack==S->Capacity-1)
		return true;
	else 
		return false;
}
//stack�� input���� �޾� stack�� pop�� �ϱ� ���� stack�� array�� ����ִ����� boolean���� return�� Ȯ���ϴ� �Լ�-Stack��
bool IsEmpty(Stack S){
	if(S->TopOfStack<0)
		return true;
	else
		return false;
}
//stack�� input���� �޾� stack�� pop�� �ϱ� ���� stack�� array�� ����ִ����� boolean���� return�� Ȯ���ϴ� �Լ�-IntStack��
bool IntIsEmpty(IntStack S){
	if(S->TopOfStack<0)
		return true;
	else
		return false;
}
//stack�� �� á�� ��� ����� ����� ������ �����Ϳ� ������� ��, ���� ���� �Ǵ� stack�� input���� �޾� stack�� array�� ���� ����ֱ� ���� �Լ�(���߿� �� ���� ���� ���� �´�)-Stack��
void Push(FILE *f, char X, Stack S){
	if(IsFull(S))
		fprintf(f,"Full\n");

	else
		S->Array[++S->TopOfStack]=X;
}
//stack�� �� á�� ��� ����� ����� ������ �����Ϳ� ������� ��, ���� ���� �Ǵ� stack�� input���� �޾� stack�� array�� ���� ����ֱ� ���� �Լ�(���߿� �� ���� ���� ���� �´�)-IntStack��
void IntPush(FILE *f, int X, IntStack S){
	if(IntIsFull(S))
		fprintf(f,"FULL\n");
	else 
		S->Array[++S->TopOfStack]=X;
}
//���� �ϳ��� ���� �� ����� ����� ������ �����Ϳ� ���� pop�� stack�� input���� �޾� stack�� �� �� ���� ���ִ� �Լ�-Stack��
void Pop(FILE *f, Stack S){
	if(IsEmpty(S))
		fprintf(f,"Empty\n");
	else
		S->TopOfStack--;

}
//���� �ϳ��� ���� �� ����� ����� ������ �����Ϳ� ���� pop�� stack�� input���� �޾� stack�� �� �� ���� ���ִ� �Լ�-IntStack��
void IntPop(FILE *f, IntStack S){
	if(IntIsEmpty(S))
		fprintf(f,"Empty\n");
	else 
		S->TopOfStack--;
}
//stack�� ������� ��� ����� ����� ������ �����Ϳ� ���� ������ stack�� input���� �޾� stack�� ���� ���� �ִ� ���� return�ϴ� �Լ�-Stack��
char Top(FILE *f, Stack S){
	if(!IsEmpty(S))
		return S->Array[S->TopOfStack];
	fprintf(f,"Empty\n");
	return 0;
}
//stack�� ������� ��� ����� ����� ������ �����Ϳ� ���� ������ stack�� input���� �޾� stack�� ���� ���� �ִ� ���� return�ϴ� �Լ�-IntStack��
int IntTop(FILE *f, IntStack S){
	if(!IntIsEmpty(S))
		return S->Array[S->TopOfStack];
	fprintf(f,"Empty\n");
	return 0;
}
//postfix�� �����ϴ� ���� ���� ����ϴ� �Լ�. IntTop�� IntPop�� ���� ������ �����Ϳ� pop�� stack, �����ȣ�� input���� �޾� stack�� �� �ΰ��� pop�ϰ� �����ȣ�� ���Ŀ� ���� ���� ���� ���� �� �� ���� return �Ѵ�. 
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
