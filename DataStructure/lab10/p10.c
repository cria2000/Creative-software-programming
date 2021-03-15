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
//숫자들이 담긴 int 배열을 input으로 받아 해당 배열의 숫자들로 만든 Graph를 return해준다. grapn의 size는 int배열이 0이 아닌 값들을 가진 element들의 수를 세어서 size로 하고, node 포인터는 동적할당을 해주고, matrix도 각각을 동적할당해준다. 
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
//Graph와 숫자 두 개를 input으로 받아(서로 연결되어 있는 숫자 두개) node배열에서 그 숫자들이 각각 어느 index에 있는지를 찾고, 해당하는 index에 1을 넣어 edge를 생성해준다.
void InsertEdge(Graph G, int a, int b){
	for(int i=0;i<G.size;i++)
		for(int j=0;j<G.size;j++){
			if(G.node[i]==a&&G.node[j]==b){
				G.matrix[i][j]=1;
			}
		}
}
//Queue를 input으로 받아 해당 Queue가 비어있는지를 확인한다. Topsort함수에서 Dequeue를 얼마동안 해야하는지 확인할 때 사용한다.
bool IsEmpty(Queue Q){
	if(Q.qsize==0||Q.qsize<0) return true;
	return false;
}
void Enqueue(Queue *Q,int X);
int Dequeue(Queue *Q);
Queue MakeNewQueue(int X);
//int 배열과 숫자, 배열의 크기를 input으로 받아 숫자가 배열에 있는지를 확인하는 함수. 배열에 그 숫자가 있으면 true를 , 없으면 false를 return한다.  
bool inArray(int nodes[],int x,int size){
	for(int i=0;i<size;i++){
		if(nodes[i]==x) return true;
	}
	return false;
}
//Graph와 dequeue한 숫자를 출력할 file의 포인처를 input으로 받아 topsort한 결과를 차례로 출력한다. 
void Topsort(Graph G,FILE* f){
	Queue Q=MakeNewQueue(G.size);
	int sum=0;
	int nodes[G.size];
	for(int i=0;i<G.size;i++) nodes[i]=0;
//indegree의 값을 확인하고, enqueue, dequeue를 하는 과정을 반복.
	for(int m=0;m<G.size+1;m++){
//enqueue가 동시에 이루어진  값들을(같은 우선순위의 값들) 다음 우선순위의 값들이 enqueue되기 전에 전부 dequeue시킨다. 
		while(!IsEmpty(Q)){
			fprintf(f,"%d ",Dequeue(&Q));
		}
//indegree가 0이면(sum이 0) enqueue를 시키되 nodes라는 배열을 새로 만들어 한 번 enqueue한 값들을 nodes에 넣어 중복 enqueue되지 않도록 inArray라는 함수를 이용하여 nodes에 값이 없으면 enqueue를 해준다. 
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
//enqueue한 값과 연결되어 있는 모든 edge들을 삭제한다. (nodes배열에 들어있는 값들은 enqueue되어 있는 값들이기 때문에 nodes와 G.node의 값들을 비교하여 같다면 그 값들과 연결되어 있는 모든 edge글 삭제-0으로 초기화)
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
//만들고자 하는 Queue의 크기를 input으로 받아 key는 동적할당을 해주고 나머지는 알맞은 값으로 초기화하여 만들어진 queue를 return 한다. 
Queue MakeNewQueue(int X){
	Queue q;
	q.key=malloc(sizeof(int)*X);
	q.first=0;
	q.rear=-1;
	q.qsize=0;
	q.max_queue_size=X;
	return q;
}
//우선순위가 같은 값들을 dequeue할 때, 숫자가 작은 거 먼저 dequeue하도록 하기 위한 함수로, Queue의 포인터를 input으로 받아 오름차순으로 sort해준다. 
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
//queue와 넣고자 하는 값을 input으로 받아 queue의 size를 늘려주고 rear도 늘려주어 그 자리에 값을 넣어준다. 
void Enqueue(Queue* Q,int X){
	Q->qsize++;
	++Q->rear;
	Q->key[Q->rear]=X;
}
//queue를 input으로 받아 앞에 있는 값을 dequeue해주는 함수. 이때, 숫자가 작은 것부터 dequeue해주어야 하기 때문에 queue의 값을 QueueSort로 먼저 sort해주고 맨 앞의 값을 return해준다.
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
//input.txt의 첫째줄을 c에 저장한 후, 공백을 기준으로 나누어 nodes라는 배열에 순서대로 넣어준다. 
	char *ptr=strtok(c," ");
	while(ptr!=NULL){
		nodes[i]=atoi(ptr);
		++i;
		ptr=strtok(NULL," ");
	}
	Graph g=CreateGraph(nodes);
//input.txt의 두번 째 줄의 '-'로 연결된 숫자들을 각각 num1과 num2에 넣어 insertEdge 해준다. 
	while(fscanf(f,"%d",&num1)!=EOF){
		char cc;
		fscanf(f,"%c",&cc);
		fscanf(f,"%d",&num2);
		InsertEdge(g,num1,num2);
	}
//matrix의 값들을 차례로 출력해준다.
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
		
//topsort를 한 값들을 차례로 출력해준다. 
	fprintf(f2,"\n\nTopSort Result : ");
	Topsort(g,f2);
	fprintf(f2,"\n");
	fclose(f);
	fclose(f2);
}

