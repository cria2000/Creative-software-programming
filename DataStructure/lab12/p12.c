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
//HashTable�� �����ϰ��� �ϴ� int��, �浹�� �ذ��ϴ� solution ���� input���� �޾� ������ �ڸ��� ���� �־��ش�. Find�� ���� �ش� HashTable�� �̹� ���� �ִ����� Ȯ���ϰ� ���� ���ٸ� ���ο� LIistNode�� �����͸� ����� ListNode�� Element�� int���� �־��ְ� HashTable�� TheLists�� �ش��ϴ� �ڸ��� �־��ش�.(Find �Լ��� ���� ���Ե� �ڸ��� return���ش�. ) 
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
//HashTable�� �����ϰ� ���� int���� ����� ����� FILE�� �����͸� input���� �޾� �ش� ���� �ִ� �ڸ��� �����Ͽ� ���� �������ش�.(0���� �ʱ�ȭ���ش�) Find�Լ��� ���� ���� ������ Ȯ���ϰ� �ִٸ� �� �ڸ��� �����Ͽ� ���� 0���� �ٲ��ش�.  
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
//HashTable�� ã�����ϴ� int���� �浹�� �ذ��Ϸ��� ����� solution�� input���� �޾� ���� �̹� �����Ѵٸ� �� ���� �ִ� index��, ���� ���ٸ� �ش� ���� insert�� index�� return ���ش�. while���� ���� �ش� ���� �������� index�� ã�ư��鼭 if���� ���� ���� �̹� �����ϴ��� ���θ� �Ǵ��ϴµ�, ���� �̹� �����Ѵٸ� insert������ϴ� index�� ������ ���ֱ� ���� �ش� index�� ������ �ٲ��� 1�� ���־� return���ش�(insert�ؾ��� index�� ���� ������ ���� �� �����Ƿ�) ���� �������� �ʴ´ٸ� ���� insert���� index�� hash�� return ���ش�. 
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
//HashTable�� ����� ����� FILE�� �����͸� input���� �޾� HashTable�� TheLists�� ���� ���� ���鼭 ���� ������ش�. �̶�, ���� �ƹ� ���� ���� ����(TheLists[ ]�� NULL)�̸� 0���� ���� ������ش�. 
void print(HashTable H,FILE *f){
	for(int i=0;i<H->TableSize;i++){
		if(H->TheLists[i]!=NULL)
		fprintf(f,"%d ",H->TheLists[i]->Element);
		else fprintf(f,"0 ");
	}
	fprintf(f,"\n");
}
//int ���� HashTable�� Size, int i, �浹�� �ذ��� ����� solution�� input���� �޾� �� ����� ������ Hash��(index�� ��)�� return �Ѵ�. solution�� 1�̸� Linear, 2�̸� Quadratic, 3�̸� Double�� ������� hash���� �����ش�. �� ��, hash���� Table�� Size�� �Ѿ�� �ٽ� ó���� index���� �����ϱ� ���� Size�� ���ش�. 
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
//�浹�� �ذ��ϱ� ���� ����� Linear�̸� solution�� 1��, Quadratic�̸� 2��, Double�̸� 3���� �ʱ�ȭ���ش�. 
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
//Find�Լ��� �ش� HashTable�� ���� ������ ������, ���ٸ� ����� return �ϹǷ� Find�� 0���� ũ�ų� ���� ��쿡�� �ش簪�� ���������ʴ´ٴ� �ȳ��� ����Ѵ�.
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
//������ Table�� ���������� ������ �ϱ� ���� ����ߴ� \n�� ������� �ʱ� ���� if��
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
