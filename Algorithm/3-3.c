#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int number;//nodes'number(starts 0)
	int state;//state=0 is WHITE, 1 is GRAY, 2 is Black
	int d;
	int f;
	struct node* p;
	int treeNum;
}Node;
int time=0;
int TN=0;
int isback=0; //If isback is 1, there are back edges, so it can't be topological sort.
Node* DFS_visit(int** edges, int n,int nodeNum,Node* nodes,int* topological){
	nodes[n].state=1;
	time=time+1;
	nodes[n].d=time;
	int am=0;
	for(int i=0;i<nodeNum;i++){
		if(edges[nodes[n].number-1][i]==1){
			if(nodes[i].state==0){
				nodes[n].p==&nodes[n];
				am=1;
				nodes=DFS_visit(edges,i,nodeNum,nodes,topological);
				nodes[n].treeNum=TN;
			
			}
			else{
				if(nodes[i].treeNum!=nodes[nodes[n].number-1].treeNum)
					isback=0;
				else if(nodes[nodes[n].number-1].d>=nodes[i].d)
					isback=1;
				else if(nodes[nodes[n].number-1].d<nodes[i].d)
					isback=0;
			}
		}
	}
	if(am==0){
	       	++TN;
	}
	nodes[n].treeNum=TN;
	nodes[n].state=2;
	for(int i=0;i<nodeNum;i++)
		if(topological[i]==0){
			topological[i]=nodes[n].number;
			break;
		}
	nodes[n].f=time=time+1;
	return nodes;
}

int main(){
	FILE *f;
	f=fopen("input3-3.txt","r");
	int nodeNum;
	fscanf(f,"%d", &nodeNum);
	int** edges=(int**)malloc(sizeof(int*)*nodeNum);
	for(int i=0;i<nodeNum;i++)
		edges[i]=(int*)malloc(sizeof(int)*nodeNum);
	for(int i=0;i<nodeNum;i++){//edge's node number starts from 0
		for(int j=0;j<nodeNum;j++){
			fscanf(f,"%d",&edges[i][j]);
		}
	}
	Node* nodes=malloc(sizeof(Node)*nodeNum);
	int* topological=malloc(sizeof(int)*nodeNum);
	
	for(int i=0;i<nodeNum;i++){
		nodes[i].number=i+1;
		nodes[i].state=0;
		nodes[i].d=-1;
		nodes[i].f=-1;
		nodes[i].p=NULL;
		topological[i]=0;
	}
	
	int st=0;
	for(st=0;st<nodeNum;st++){
		if(nodes[st].state==0)
			nodes=DFS_visit(edges,st,nodeNum,nodes,topological);
	}
	if(isback==0){
		printf("1\n");
		for(int i=nodeNum-1;i>=0;i--)
			printf("%d ",topological[i]);
	}
	else printf("0");
	printf("\n");
	fclose(f);
	free(edges);
	free(nodes);
	free(topological);


}
