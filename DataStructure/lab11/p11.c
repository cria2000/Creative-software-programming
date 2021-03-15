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
//������� �ϴ� heap�� size�� input���� �޾� minHeap�� ����� return���ִ� �Լ�
Heap* createMinHeap(int heapSize){
	Heap* hp=malloc(sizeof(Heap));
	hp->capacity=heapSize;
	hp->size=0;
	hp->element=malloc(sizeof(Node)*heapSize);
	return hp;
}
//minHeap�� ã�����ϴ� ���� input���� �޾� minHeap�� �� vertex�� �����ϸ� �� index��, �������� ������ 0�� return ���ش�. �̴� insert���� ���� insert�� �� ������ ���� �ִ� ���� �ٲ� �������� ������ �� ���Ǵ� �Լ��̴�. 
int Find(int vertex, Heap *minHeap){
	for(int i=0;i<minHeap->size;i++){
		if(minHeap->element[i].key==vertex)
			return i;
	}
	return 0;
}
//Heap�� �����Ϳ� �����ϰ��� �ϴ� vertex�� weight�� ipnut���� �޾� insert���ִ� �Լ�. Find�� ���� minHeap�� �̹� �ش� vertex�� ���������� �ʴ��� Ȯ���ϰ�, �������� �ʴ´ٸ� minHeap�� size�� �ϳ� ������Ų��, �� �ڸ��� �ľ��Ͽ�(weight�� ��)  �� �ڸ��� input���� ���� vertex�� ���� distance�� ���� ���´�. �̹� minHeap�� vertex�� �����Ѵٸ� Find�� ã�� index�� ���� ���� ������ �־��ְ� �ڸ� ������ ���ش�. 
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
//Heap�� �����͸� input���� �޾� ���� ���� ���� �����ϰ� �� ��(node�� key��)�� return���ִ� �Լ�. 
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
//start�� end������ �ִܰŸ��� ����ϱ� ���� �Լ���, vertex[]�� vertex���� �迭�̸�, pred[]�� �� vertex���� ���� node ������ ������ �迭�̴�. �̶�, vertex�� pred�� �� ���� ���� index�� �����ϴ�. ó�� for���� ���� vertex�� ������ �˾Ƴ���, size�� vertex�� ������ �ʱ�ȭ�Ѵ�. �� �� pred�迭�� ���� ���� ������ ã�ư��� path��� �迭�� �־��ְ�(�״�� ����ϸ� end���� ��µǹǷ�) path�迭�� ������ ���ʷ� ������ش�.
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
//dis�迭�� pred�迭�� ����� �Լ�. dis�� start�κ��� ���� ª�� �Ÿ��̰�, pred�� ���� ª�� �Ÿ��� �� �� node ������ node�� ���� ������ �迭�̴�. �켱 vertex�� ������ size����ϰ�, dis�迭�� ��� 99999�� �ʱ�ȭ���� ����, start�� dis�� 0���� �ٲ��ش�. matrix�迭(�� node�� �Ÿ��� ���� �迭)�� ����Ͽ� start�� �������ִ� node���� dis�� �ٲ��ְ�,  minHeap�� �� vertex���� �� �־��ش�. �׸��� minHeap�� ������� ������ delete�ϸ� �ִܰŸ��� ã�ư���.
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
//input.txt�� ù��° ���� �о� vertex�迭�� �� vertex�� ����
	fgets(c,100,f);
	char *ptr=strtok(c," ");
	while(ptr!=NULL){
		vertex[i]=atoi(ptr);
		++i;
		ptr=strtok(NULL," ");
	}
//input.txt�� �ι�° ���� �о� matrix�� �� node�� �Ÿ� ����(�켱 " "�� �������� ������ dis�迭�� ������ "-"�� �������� ������ matrix�� �� �� ����)
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
