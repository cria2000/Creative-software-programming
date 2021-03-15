#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
	int key;
	int weight;
}Node;
typedef struct Heap{
	int capacity;
	int size;
	Node* element;
}Heap;
//만들고자 하는 heap의 size를 input으로 받아 minHeap을 만들어 return해주는 함수
Heap* createMinHeap(int heapSize){
	Heap* hp=malloc(sizeof(Heap));
	hp->capacity=heapSize;
	hp->size=0;
	hp->element=malloc(sizeof(Node)*heapSize);
	return hp;
}
//minHeap과 찾고자하는 수를 input으로 받아 minHeap에 수 vertex가 존재하면 그 index를, 존재하지 않으면 0을 return 해준다. 이는 insert에서 실제 insert를 할 것인지 원래 있던 값을 바꿀 것인지를 결정할 때 사용되는 함수이다. 
int Find(int vertex, Heap *minHeap){
	for(int i=0;i<minHeap->size;i++){
		if(minHeap->element[i].key==vertex)
			return i;
	}
	return 0;
}
//Heap의 포인터와 삽입하고자 하는 vertex와 weight를 ipnut으로 받아 insert해주는 함수. Find를 통해 minHeap에 이미 해당 vertex가 존재하지는 않는지 확인하고, 존재하지 않는다면 minHeap의 size를 하나 증가시킨후, 들어갈 자리를 파악하여(weight로 비교)  그 자리에 input으로 받은 vertex의 값과 distance의 값을 놓는다. 이미 minHeap에 vertex가 존재한다면 Find로 찾은 index에 새로 받은 값들을 넣어주고 자리 조정만 해준다. 
void insert(Heap* minHeap, int vertex, int distance){
	int i=0;
	if(Find(vertex,minHeap)==0){
	  ++minHeap->size;
	}
	else{
		int index=Find(vertex,minHeap);
	minHeap->element[index].key=vertex;
	minHeap->element[index].weight=distance;
	}
	for(i=++minHeap->size;minHeap->element[i/2].weight>distance;i/=2){
		minHeap->element[i]=minHeap->element[i/2];
		if(i==0) break;
		}
	if(Find(vertex,minHeap)==0){
		minHeap->element[i].key=vertex;
		minHeap->element[i].weight=distance;
	}
}
//Heap의 포인터를 input으로 받아 가장 작은 값을 삭제하고 그 값(node의 key값)을 return해주는 함수. 
int deleteMin(Heap* minHeap){
	int i, Child;
	Node MinElement, LastElement;
	MinElement=minHeap->element[1];
	LastElement=minHeap->element[minHeap->size--];
	for(i=1;i*2<=minHeap->size;i=Child){
		Child=i*2;
		if(Child!=minHeap->size&&minHeap->element[Child+1].weight<minHeap->element[Child].weight)
			Child++;
		if(LastElement.weight>minHeap->element[Child].weight)
			minHeap->element[i]=minHeap->element[Child];
		else 
			break;
	}
	minHeap->element[i]=LastElement;
	--minHeap->capacity;
	return MinElement.key;
}
//start와 end사이의 최단거리를 출력하기 위한 함수로, vertex[]는 vertex들의 배열이며, pred[]는 그 vertex들의 이전 node 값들을 가지는 배열이다. 이때, vertex와 pred의 각 값에 대한 index는 동일하다. 처음 for문을 통해 vertex의 개수를 알아내고, size는 vertex의 개수로 초기화한다. 그 후 pred배열을 통해 앞의 값들을 찾아가며 path라는 배열에 넣어주고(그대로 출력하면 end부터 출력되므로) path배열의 값들을 차례로 출력해준다.
void printShortestPath(int pred[],int end,int start,int vertex[],FILE *f){
	int i=0;
	for(i;i<100;i++)
		if(vertex[i]==0) break;
	int path[i];
	int size=i;
	int next;
	for(i=0;i<size;i++)
		if(vertex[i]==end){
			path[0]=end;
			next=pred[i];
		}
	path[1]=next;
	i=1;
	while(next!=start){
		for(int j=0;j<size;j++)
			if(vertex[j]==next){				
				next=pred[j];
				++i;
				path[i]=next;
				break;
			}
	}
	for(i;i>=0;i--){
		fprintf(f,"%d ",path[i]);
	}
	fprintf(f,"\n");
}
//dis배열과 pred배열을 만드는 함수. dis는 start로부터 가장 짧은 거리이고, pred는 가장 짧은 거리일 때 그 node 직전의 node의 값을 가지는 배열이다. 우선 vertex의 개수를 size라고하고, dis배열을 모두 99999로 초기화해준 다음, start의 dis는 0으로 바꿔준다. matrix배열(각 node간 거리를 가진 배열)을 사용하여 start와 인접해있는 node들의 dis를 바꿔주고,  minHeap에 각 vertex들을 다 넣어준다. 그리고 minHeap이 비어있을 때까지 delete하며 최단거리를 찾아간다.
void Dijkstra(int matrix[][100], int start, int pred[],int *vertex,Heap* minHeap){
	int i=0;
	int j;
	int size=0;
	for(i;i<100;i++){
		if(vertex[i]!=0) ++size;
	}
	int dis[size];
	for(j=0;j<size;j++)
		dis[j]=99999;
	for(j=0;j<size;j++)
		if(vertex[j]==start)
			dis[j]=0;
	for(i=0;i<size;i++)
		if(matrix[j][i]!=99999)
			dis[i]=matrix[j][i];
	for(i=0;i<size;i++)
		insert(minHeap,vertex[i],dis[i]);
	while(minHeap->capacity!=0){
		int u=deleteMin(minHeap);
		for(i=0;i<size;i++)
			if(vertex[i]==u){
				for(int k=0;k<size;k++){
					if(matrix[i][k]!=99999){
						if(dis[i]+matrix[i][k]<dis[k]){
							dis[k]=dis[i]+matrix[i][k];
							pred[k]=u;
							insert(minHeap,vertex[k],dis[k]);
						}
					}
				}
			}
	}
}	
int main(){
	FILE *f;
	FILE *f2;
	f=fopen("input.txt","r");
	f2=fopen("output.txt","w");
	int vertex[100];
	for(int i=0;i<100;i++) vertex[i]=0;
	char c[100];
	char s[500];
	char **dis=malloc(sizeof(char)*100);
	for(int i=0;i<100;i++)
		dis[i]=malloc(sizeof(char)*100);
	int matrix[100][100];
	int i=0;
	int vertex1, vertex2;
	int weight;
	int start,end;
	int pred[100];
	Heap* minHeap=createMinHeap(100);
	for(int i=0;i<100;i++)
		for(int j=0;j<100;j++)
			matrix[i][j]=99999;
//input.txt의 첫번째 줄을 읽어 vertex배열에 각 vertex들 저장
	fgets(c,100,f);
	char *ptr=strtok(c," ");
	while(ptr!=NULL){
		vertex[i]=atoi(ptr);
		++i;
		ptr=strtok(NULL," ");
	}
//input.txt의 두번째 줄을 읽어 matrix에 각 node간 거리 저장(우선 " "을 기준으로 나누어 dis배열에 저장후 "-"를 기준으로 나누어 matrix에 각 값 저장)
	fgets(s,500,f);
	char *ptr1=strtok(s," ");
	char *ptr2;
	int j=0;
	while(ptr1!=NULL){
		dis[j]=ptr1;
		++j;
		ptr1=strtok(NULL," ");
	}
	j=0;
	ptr2=strtok(dis[j],"-");
	while(ptr2!=NULL){
		vertex1=atoi(ptr2);
		ptr2=strtok(NULL,"-");
		vertex2=atoi(ptr2);
		ptr2=strtok(NULL,"-");
		weight=atoi(ptr2);
		for(int i=0;i<100;i++)
			for(int j=0;j<100;j++)
				if(vertex[i]==vertex1)
					if(vertex[j]==vertex2)				
						matrix[i][j]=weight;
		++j;
		if(dis[j]!="0"){
			ptr2=strtok(dis[j],"-");
		}
		else break;
	}
	fscanf(f,"%d",&start);
	fscanf(f,"%d",&end);
	Dijkstra(matrix,start,pred,vertex,minHeap);
	printShortestPath(pred,end,start,vertex,f2);

}
