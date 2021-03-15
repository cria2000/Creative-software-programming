#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
//Edge(���� �ΰ� ������)�� ������ ������ Struct�� Edge��� �̸����� ����. 
typedef struct edge{
	int num1;
	int num2;
}Edge;
//int�迭�� input���� �޾� int �迭�� ���� 0���� �ʱ�ȭ�����ִ� �Լ�
void Init(int *S){
	for(int i=1;i<=sizeof(S);i++) S[i]=0;
}
//root�� ã���� �ϴ� int�� �� ���� ã�� int�迭�� input���� �޾� �ش��ϴ� index�� return�Ѵ�. index x�� 0���� �۴ٸ� root�̱� ������ x��ü�� return�ϰ�, �ƴ϶�� root�� ���� ������ Recursive�ϰ� �Լ��� ȣ���Ѵ�.
int Find(int x,int *S){
	if(S[x]<=0)
		return x;
	else 
		return (S[x]=Find(S[x],S));
}
//union�� �ΰ��� int�� int�� ���Ե� int�迭�� input���� �޾� union���ִ� �Լ�. input�� int���� root �ΰ��� ���� �ȴ�. root�� rank�� ���Ͽ� �� ���� set�� ū set�� �ٿ��ְ�, rank�� ���ٸ� �ƹ����� �ٿ��ְ� rank�� �ϳ� �ÿ��ش�. 
void Union(int *S,int r1, int r2){
	if(S[r2]<S[r1])
		S[r1]=r2;
	else{
		if(S[r2]==S[r1]){
			S[r1]--;
		}
		S[r2]=r1;
	}
}
//set���� ���� union�Ǿ� set�� �ϳ��� ���Ҵ����� Ȯ���ϴ� �Լ�. int �迭 S��  input.txt�� ���Ͽ� �ִ� ���� num�� �޾� set�� �ϳ��� ���Ҵٸ� true, �ƴϸ� false�� return �Ѵ�.  ���߹ݺ����� ����Ͽ� S�� ��� index������ root�� ���Ͽ� ���� ������, Ȥ�� ���� root�� 0���� ���������� Ȯ���Ͽ� ���ٸ� true�� return�Ѵ�. 
bool IsOne(int *S,int num){
	for(int i=1;i<num*num+1;i++){
		for(int j=1;j<num*num+1;j++){
		if((Find(i,S)==0&&Find(j,S)==0)) return false;
		if(Find(i,S)!=Find(j,S)){
			return false;
		}}
	}
	
	return true;
}
int main(){
	FILE *f;
	FILE *f2;
	f=fopen("input.txt","r");
	f2=fopen("output.txt","w");
	int num;
	fscanf(f,"%d",&num);
	int *S=malloc((sizeof(int)*num*num)+1);
	Init(S);
	Edge *E=malloc((sizeof(Edge)*2*num*(num-1)));
	int j=1;
//Edge���� ������ E�� ����� �ݺ���. �� ���� ���ڸ� �����ִ� edge��  E[i]�� �ְ�, i�� �ϳ� �������� �� �Ʒ��� ���ڸ� �����ִ� edge�� E�� �ִ´�. �̶� �տ� �ִ� ����, ���� �ִ� ���ڸ� num1��, �ڿ� �ִ� ����, ���� �ִ� ���ڸ� num2�� ������, ��� ���� ���������� ���̻� edge�� �����Ƿ� ���ǹ��� ���� �����Ѵ�. 
	for(int i=0;i<2*num*(num-1);i++){
		if(j%num!=0){
			E[i].num1=j;
			E[i].num2=j+1;
		++i;  
		}
		if(j<=(num*num)-num){
			E[i].num1=j;
			E[i].num2=j+num;
			
		}
		else
			--i;
		++j;
	}
//maze�� �׸��� ������ �ִ� char�迭 maze�� �ʱ�ȭ�ϴ� �ݺ���. Ȧ������ Ȧ������ ' '�� Ȧ������ ¦������ |��, ¦������ ¦������ +��, ¦������ Ȧ������ -�� �ʱ�ȭ �� maze�� �Ա��� �ⱸ�� ' '�� �ʱ�ȭ�Ѵ�.
	char maze[2*num+1][2*num+1];
	for(int i=0;i<2*num+1;i++){
		for(int j=0;j<2*num+1;j++){
			if(i%2==0&&j%2==0)
				maze[i][j]='+';
			else if(i%2==0&&j%2==1)
				maze[i][j]='-';
			else if(i%2==1&&j%2==0)
				maze[i][j]='|';
			else if(i%2==1&&j%2==1)
				maze[i][j]=' ';
		}
	}
		maze[1][0]=' ';
		maze[2*num-1][2*num]=' ';
	
	srand((unsigned int)time(NULL));
//set�� �ϳ��� �ƴҵ��� while���� �ݺ��Ѵ�.
	while(IsOne(S,num)==false){
	int x=rand()%(2*num*(num-1));
		int row,column;
		Edge e=E[x];
//random���� �� index�� E�� num1�� num2�� �� �� ���� set�̰ų� root�� �ٸ� ��� union����. 
		if((Find(E[x].num1,S)==0&&Find(E[x].num2,S)==0)||(Find(E[x].num1,S)!=Find(E[x].num2,S))){
//���� �� ���� �� ���� ���� edge�� �ִ� ��쿡 �°� row�� column�� �������� �� edge�� �����ش�. (' '���� �ٲ��ش�.)
			if(E[x].num2-E[x].num1==1){
				if(E[x].num1/num==0)
					row=1;
				else 
					row=2*(E[x].num1/num)+1;
				column=2*(E[x].num1%num);
				maze[row][column]=' ';
			}
//���ڰ� ���Ʒ��� �ִ� ���
			else{
//num1�� ù°�ٿ� �ִ� ���� ���� row�� �������ش�. 
				if(E[x].num1/num==0||(E[x].num1/num==1&&E[x].num1%num==0)){
					row=2;
					if(E[x].num1%num!=0) column=2*(E[x].num1%num)-1;
					else column=2*num-1;
				}
//num1�� ù°���� �ƴϸ鼭 ���Ʒ��� edge�� ������ �ִ� ��� ���� ���� row�� cloumn�� �˸°� ������ �� edge�� �����ش�. 
				else{
					if(E[x].num1%num!=0){
						row=2*(E[x].num1/num)+2;
						column=2*(E[x].num1%num)-1;
					}
					else{
						row=2*(E[x].num1/num);
						column=2*num-1;
					}
				}
				maze[row][column]=' ';
			}
//edge�� ���ְ� �� ��, �ΰ��� ���ڸ� union���ش�. 
			Union(S,Find(E[x].num1,S),Find(E[x].num2,S));
		}	}
//maze�� print�ϴ� �ݺ���
	for(int i=0;i<2*num+1;i++){
		for(int j=0;j<2*num+1;j++)
			fprintf(f2,"%c",maze[i][j]);
		fprintf(f2,"\n");
	}
	fclose(f);
	fclose(f2);
	free(S);
	free(E);
}


	

