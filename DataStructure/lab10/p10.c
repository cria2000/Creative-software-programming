#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
typedef struct Graph{
	int size;
	int* node;
	int** matrix;
}Graph;
typedef struct Queue{
	int* key;
	int first;
	int rear;
	int qsize;
	int max_queue_size;
}Queue;
//���ڵ��� ��� int �迭�� input���� �޾� �ش� �迭�� ���ڵ�� ���� Graph�� return���ش�. grapn�� size�� int�迭�� 0�� �ƴ� ������ ���� element���� ���� ��� size�� �ϰ�, node �����ʹ� �����Ҵ��� ���ְ�, matrix�� ������ �����Ҵ����ش�. 
Graph CreateGraph(int nodes[]){
	Graph gr;
	int _size=0;
	for(int i=0;i<512;i++)
		if(nodes[i]!=0) ++_size;
	gr.size=_size;
	gr.node=malloc(sizeof(int)*gr.size);
	for(int i=0;i<gr.size;i++)
		gr.node[i]=nodes[i];
	gr.matrix=malloc(sizeof(int)*(gr.size+1));
	for(int j=0;j<gr.size;j++)
		gr.matrix[j]=malloc(sizeof(int)*(gr.size+1));
	return gr;
}
//Graph�� ���� �� ���� input���� �޾�(���� ����Ǿ� �ִ� ���� �ΰ�) node�迭���� �� ���ڵ��� ���� ��� index�� �ִ����� ã��, �ش��ϴ� index�� 1�� �־� edge�� �������ش�.
void InsertEdge(Graph G, int a, int b){
	for(int i=0;i<G.size;i++)
		for(int j=0;j<G.size;j++){
			if(G.node[i]==a&&G.node[j]==b){
				G.matrix[i][j]=1;
			}
		}
}
//Queue�� input���� �޾� �ش� Queue�� ����ִ����� Ȯ���Ѵ�. Topsort�Լ����� Dequeue�� �󸶵��� �ؾ��ϴ��� Ȯ���� �� ����Ѵ�.
bool IsEmpty(Queue Q){
	if(Q.qsize==0||Q.qsize<0) return true;
	return false;
}
void Enqueue(Queue *Q,int X);
int Dequeue(Queue *Q);
Queue MakeNewQueue(int X);
//int �迭�� ����, �迭�� ũ�⸦ input���� �޾� ���ڰ� �迭�� �ִ����� Ȯ���ϴ� �Լ�. �迭�� �� ���ڰ� ������ true�� , ������ false�� return�Ѵ�.  
bool inArray(int nodes[],int x,int size){
	for(int i=0;i<size;i++){
		if(nodes[i]==x) return true;
	}
	return false;
}
//Graph�� dequeue�� ���ڸ� ����� file�� ����ó�� input���� �޾� topsort�� ����� ���ʷ� ����Ѵ�. 
void Topsort(Graph G,FILE* f){
	Queue Q=MakeNewQueue(G.size);
	int sum=0;
	int nodes[G.size];
	for(int i=0;i<G.size;i++) nodes[i]=0;
//indegree�� ���� Ȯ���ϰ�, enqueue, dequeue�� �ϴ� ������ �ݺ�.
	for(int m=0;m<G.size+1;m++){
//enqueue�� ���ÿ� �̷����  ������(���� �켱������ ����) ���� �켱������ ������ enqueue�Ǳ� ���� ���� dequeue��Ų��. 
		while(!IsEmpty(Q)){
			fprintf(f,"%d ",Dequeue(&Q));
		}
//indegree�� 0�̸�(sum�� 0) enqueue�� ��Ű�� nodes��� �迭�� ���� ����� �� �� enqueue�� ������ nodes�� �־� �ߺ� enqueue���� �ʵ��� inArray��� �Լ��� �̿��Ͽ� nodes�� ���� ������ enqueue�� ���ش�. 
		for(int i=0;i<G.size;i++){
			sum=0;
			for(int j=0;j<G.size;j++)
				sum+=G.matrix[j][i];
			if(sum==0){
	
				if(!inArray(nodes,G.node[i],G.size)){
					Enqueue(&Q,G.node[i]);
					for(int n=0;n<G.size;n++){
						if(nodes[n]==0){
							nodes[n]=G.node[i];
							break;
						}
					}
				}
			}
		}
//enqueue�� ���� ����Ǿ� �ִ� ��� edge���� �����Ѵ�. (nodes�迭�� ����ִ� ������ enqueue�Ǿ� �ִ� �����̱� ������ nodes�� G.node�� ������ ���Ͽ� ���ٸ� �� ����� ����Ǿ� �ִ� ��� edge�� ����-0���� �ʱ�ȭ)
		for(int i=0;i<G.size;i++){
				for(int l=0;l<G.size;l++){
					if(nodes[l]==G.node[i]){
						for(int k=0;k<G.size;k++)
							G.matrix[i][k]=0;
					}
				}
		}
	}
}
//������� �ϴ� Queue�� ũ�⸦ input���� �޾� key�� �����Ҵ��� ���ְ� �������� �˸��� ������ �ʱ�ȭ�Ͽ� ������� queue�� return �Ѵ�. 
Queue MakeNewQueue(int X){
	Queue q;
	q.key=malloc(sizeof(int)*X);
	q.first=0;
	q.rear=-1;
	q.qsize=0;
	q.max_queue_size=X;
	return q;
}
//�켱������ ���� ������ dequeue�� ��, ���ڰ� ���� �� ���� dequeue�ϵ��� �ϱ� ���� �Լ���, Queue�� �����͸� input���� �޾� ������������ sort���ش�. 
void QueueSort(Queue *Q){
	int temp=0;
	for(int i=0;i<Q->qsize;i++){
		for(int j=0;j<Q->qsize;j++){
			if(Q->key[j]>Q->key[j+1]&&Q->key[j]!=0){
				temp=Q->key[j];
				Q->key[j]=Q->key[j+1];
				Q->key[j+1]=temp;
			}
		}
	}
}
//queue�� �ְ��� �ϴ� ���� input���� �޾� queue�� size�� �÷��ְ� rear�� �÷��־� �� �ڸ��� ���� �־��ش�. 
void Enqueue(Queue* Q,int X){
	Q->qsize++;
	++Q->rear;
	Q->key[Q->rear]=X;
}
//queue�� input���� �޾� �տ� �ִ� ���� dequeue���ִ� �Լ�. �̶�, ���ڰ� ���� �ͺ��� dequeue���־�� �ϱ� ������ queue�� ���� QueueSort�� ���� sort���ְ� �� ���� ���� return���ش�.
int Dequeue(Queue *Q){
	--Q->qsize;
	++Q->first;
	QueueSort(Q);
	return Q->key[Q->first-1];
}
int main(){
	FILE *f;
	FILE *f2;
	f=fopen("input.txt","r");
	f2=fopen("output.txt","w");
	int nodes[512];
	for(int i=0;i<512;i++)
		nodes[i]=0;
	int i=0;
	int num1;
	int num2;
	char c[512];
	fgets(c,512,f);
//input.txt�� ù°���� c�� ������ ��, ������ �������� ������ nodes��� �迭�� ������� �־��ش�. 
	char *ptr=strtok(c," ");
	while(ptr!=NULL){
		nodes[i]=atoi(ptr);
		++i;
		ptr=strtok(NULL," ");
	}
	Graph g=CreateGraph(nodes);
//input.txt�� �ι� ° ���� '-'�� ����� ���ڵ��� ���� num1�� num2�� �־� insertEdge ���ش�. 
	while(fscanf(f,"%d",&num1)!=EOF){
		char cc;
		fscanf(f,"%c",&cc);
		fscanf(f,"%d",&num2);
		InsertEdge(g,num1,num2);
	}
//matrix�� ������ ���ʷ� ������ش�.
	fprintf(f2,"Adjacency matrix\n  ");
	for(int i=0;i<g.size;i++)
		fprintf(f2,"%d ",g.node[i]);
	fprintf(f2,"\n");
	for(int i=0;i<g.size;i++){
		fprintf(f2,"%d ",g.node[i]);
		for(int j=0;j<g.size;j++)
			fprintf(f2,"%d ",g.matrix[i][j]);
		fprintf(f2,"\n");
	}
		
//topsort�� �� ������ ���ʷ� ������ش�. 
	fprintf(f2,"\n\nTopSort Result : ");
	Topsort(g,f2);
	fprintf(f2,"\n");
	fclose(f);
	fclose(f2);
}

