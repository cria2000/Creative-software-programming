#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
//Edge(숫자 두개 순서쌍)의 집합을 저장할 Struct를 Edge라는 이름으로 정의. 
typedef struct edge{
	int num1;
	int num2;
}Edge;
//int배열을 input으로 받아 int 배열을 전부 0으로 초기화시켜주는 함수
void Init(int *S){
	for(int i=1;i<=sizeof(S);i++) S[i]=0;
}
//root를 찾고자 하는 int와 그 수를 찾을 int배열을 input으로 받아 해당하는 index를 return한다. index x가 0보다 작다면 root이기 때문에 x자체를 return하고, 아니라면 root가 나올 때까지 Recursive하게 함수를 호출한다.
int Find(int x,int *S){
	if(S[x]<=0)
		return x;
	else 
		return (S[x]=Find(S[x],S));
}
//union할 두개의 int와 int가 포함된 int배열을 input으로 받아 union해주는 함수. input의 int에는 root 두개가 들어가게 된다. root의 rank를 비교하여 더 작은 set을 큰 set에 붙여주고, rank가 같다면 아무데나 붙여주고 rank를 하나 늘여준다. 
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
//set끼리 전부 union되어 set가 하나만 남았는지를 확인하는 함수. int 배열 S와  input.txt의 파일에 있는 수인 num을 받아 set가 하나만 남았다면 true, 아니면 false를 return 한다.  이중반복문을 사용하여 S의 모든 index끼리의 root를 비교하여 전부 같은지, 혹은 전부 root가 0으로 동일한지를 확인하여 같다면 true를 return한다. 
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
//Edge들의 집합인 E를 만드는 반복문. 양 옆의 숫자를 막고있는 edge를  E[i]에 넣고, i를 하나 증가시켜 위 아래의 숫자를 막고있는 edge를 E에 넣는다. 이때 앞에 있는 숫자, 위에 있는 숫자를 num1에, 뒤에 있는 숫자, 위에 있는 숫자를 num2에 넣으며, 행과 열의 마지막줄은 더이상 edge가 없으므로 조건문을 통해 배제한다. 
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
//maze의 그림을 가지고 있는 char배열 maze를 초기화하는 반복문. 홀수행의 홀수열은 ' '로 홀수행의 짝수열은 |로, 짝수행의 짝수열은 +로, 짝수행의 홀수열은 -로 초기화 후 maze의 입구와 출구는 ' '로 초기화한다.
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
//set가 하나가 아닐동안 while문을 반복한다.
	while(IsOne(S,num)==false){
	int x=rand()%(2*num*(num-1));
		int row,column;
		Edge e=E[x];
//random으로 고른 index의 E의 num1과 num2가 둘 다 단일 set이거나 root가 다를 경우 union실행. 
		if((Find(E[x].num1,S)==0&&Find(E[x].num2,S)==0)||(Find(E[x].num1,S)!=Find(E[x].num2,S))){
//숫자 두 개를 양 옆에 끼고 edge가 있는 경우에 맞게 row와 column을 결정해준 후 edge를 없애준다. (' '으로 바꿔준다.)
			if(E[x].num2-E[x].num1==1){
				if(E[x].num1/num==0)
					row=1;
				else 
					row=2*(E[x].num1/num)+1;
				column=2*(E[x].num1%num);
				maze[row][column]=' ';
			}
//숫자가 위아래로 있는 경우
			else{
//num1이 첫째줄에 있는 경우는 따로 row를 설정해준다. 
				if(E[x].num1/num==0||(E[x].num1/num==1&&E[x].num1%num==0)){
					row=2;
					if(E[x].num1%num!=0) column=2*(E[x].num1%num)-1;
					else column=2*num-1;
				}
//num1이 첫째줄이 아니면서 위아래로 edge를 가지고 있는 경우 열에 따라서 row와 cloumn을 알맞게 설정한 후 edge를 없애준다. 
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
//edge를 없애고 난 후, 두개의 숫자를 union해준다. 
			Union(S,Find(E[x].num1,S),Find(E[x].num2,S));
		}	}
//maze를 print하는 반복문
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


	

