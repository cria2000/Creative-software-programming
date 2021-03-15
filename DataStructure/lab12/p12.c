#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
typedef struct ListNode *Position;
typedef Position List;
typedef struct HashTbl *HashTable;
struct ListNode{
	int Element;
};
struct HashTbl{
	int TableSize;
	List* TheLists;
};
int Find(HashTable H, int value, int solution);
//HashTable과 삽입하고자 하는 int값, 충돌을 해결하는 solution 값을 input으로 받아 적절한 자리에 값을 넣어준다. Find를 통해 해당 HashTable에 이미 값이 있는지를 확인하고 값이 없다면 새로운 LIistNode의 포인터를 만들어 ListNode의 Element에 int값을 넣어주고 HashTable의 TheLists에 해당하는 자리에 넣어준다.(Find 함수가 값이 삽입될 자리를 return해준다. ) 
void insert(HashTable H, int value, int solution,FILE *f){
	int Pos;
	Position newCell;
	int i=0;
	Pos=Find(H,value,solution);
	if(Pos<0){
		fprintf(f,"Already exists\n");
		return ;
	}
		newCell=malloc(sizeof(struct ListNode));		
		newCell->Element=value;
		H->TheLists[Pos]=newCell;
	fprintf(f,"Inserted %d\n",H->TheLists[Pos]->Element);
}
//HashTable과 삭제하고 싶은 int값과 결과를 출력할 FILE의 포인터를 input으로 받아 해당 값이 있는 자리에 접근하여 값을 삭제해준다.(0으로 초기화해준다) Find함수를 통해 값이 있음을 확인하고 있다면 그 자리에 접근하여 값을 0으로 바꿔준다.  
void delete(HashTable H, int value, int solution,FILE *f){
	int hash,Pos;
	int i=0;
	Pos=Find(H, value, solution);
	if(Pos<0) {
		H->TheLists[(-Pos)-1]->Element=0;
		fprintf(f,"Deleted %d\n",value);
		return ;
	}
	fprintf(f,"%d not exists\n",value);
}
int Hash(int value, int Size, int i, int solution);
//HashTable과 찾고자하는 int값과 충돌을 해결하려는 방법인 solution을 input으로 받아 값이 이미 존재한다면 그 값이 있는 index를, 값이 없다면 해당 값을 insert할 index를 return 해준다. while문을 통해 해당 값을 넣으려는 index를 찾아가면서 if문을 통해 값이 이미 존재하는지 여부를 판단하는데, 값이 이미 존재한다면 insert해줘야하는 index와 구별을 해주기 위해 해당 index를 음수로 바꾼후 1을 빼주어 return해준다(insert해야할 index의 값은 음수가 나올 수 없으므로) 값이 존재하지 않는다면 값을 insert해줄 index인 hash를 return 해준다. 
int Find(HashTable H, int value, int solution){
	int i=0;
	int hash=Hash(value, H->TableSize, i, solution);
	while(H->TheLists[hash]!=NULL&&H->TheLists[hash]->Element!=0){
		if(H->TheLists[hash]->Element==value) 
			return (-hash)-1;
		++i;
		hash=Hash(value, H->TableSize, i, solution);
	}
	return hash;
}
//HashTable과 결과를 출력할 FILE의 포인터를 input으로 받아 HashTable의 TheLists의 도믄 값를 돌면서 값을 출력해준다. 이때, 아직 아무 값이 없는 상태(TheLists[ ]가 NULL)이면 0으로 값을 출력해준다. 
void print(HashTable H,FILE *f){
	for(int i=0;i<H->TableSize;i++){
		if(H->TheLists[i]!=NULL)
		fprintf(f,"%d ",H->TheLists[i]->Element);
		else fprintf(f,"0 ");
	}
	fprintf(f,"\n");
}
//int 값과 HashTable의 Size, int i, 충돌을 해결할 방법인 solution을 input으로 받아 그 값들로 구해진 Hash값(index의 값)을 return 한다. solution이 1이면 Linear, 2이면 Quadratic, 3이면 Double의 방법으로 hash값을 구해준다. 이 때, hash값이 Table의 Size를 넘어가면 다시 처음의 index부터 시작하기 위해 Size를 빼준다. 
int Hash(int value, int Size, int i, int solution){
	int hash=value%Size;
	if(solution==1)
		hash=hash+i;
	else if(solution==2)
		hash=hash+(i*i);
	else if(solution==3)
		hash=(hash+i*(7-(value%7))%Size);
	while(hash>Size||hash==Size)
		hash=hash-Size;
	return hash;
}
int main(){
	FILE *f,*f2;
	f=fopen("input.txt","r");
	f2=fopen("output.txt","w");
	int testCase=0;
	int solution=0;
	int size;
	fscanf(f, "%d",&testCase);
	HashTable table=malloc(sizeof(struct HashTbl));
	for(int i=0;i<testCase;i++){
		char *ans;
			fscanf(f,"%s",ans);
			fprintf(f2, "%s\n",ans);
//충돌을 해결하기 위한 방법이 Linear이면 solution을 1로, Quadratic이면 2로, Double이면 3으로 초기화해준다. 
			if(strcmp(ans,"Linear")==0){
				solution=1;
			}
			else if(strcmp(ans,"Quadratic")==0)
				solution=2;
			else if(strcmp(ans,"Double")==0)
				solution=3;
			fscanf(f, "%d",&size);
			table->TableSize=size;
			table->TheLists=malloc(sizeof(List)*size);
			char cmd;
			while(true){
			fscanf(f,"%c", &cmd);
			if(cmd=='i'){
				int num;
				fscanf(f,"%d",&num);
				insert(table, num, solution,f2);
			}
			else if(cmd=='f'){
				int num;
				fscanf(f, "%d",&num);
//Find함수는 해당 HashTable에 값이 있으면 음수를, 없다면 양수를 return 하므로 Find가 0보다 크거나 같은 경우에는 해당값이 존재하지않는다는 안내를 출력한다.
				if(Find(table, num, solution)>=0)
					fprintf(f2,"Not found\n");
			}
			else if(cmd=='d'){
				int num;
				fscanf(f,"%d",&num);
				delete(table, num, solution,f2);
			}
			else if(cmd=='p'){
				print(table,f2);
			}
			else if(cmd=='q'){
//마지막 Table이 끝날때에는 구분을 하기 위해 출력했던 \n을 출력하지 않기 위한 if문
				if(i+1<testCase)
					fprintf(f2,"\n");
				break;
			}
		}
	}
	fclose(f);
	fclose(f2);
	free(table->TheLists);
	free(table);
}
