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
int TN=1;
Node* DFS_visit(int** edges, int n,int nodeNum,Node* nodes){
	nodes[n].state=1;
	time=time+1;
	nodes[n].d=time;
	int arb=0;
	if(nodes[n].p==NULL) nodes[n].treeNum=TN;
	for(int i=0;i<nodeNum;i++){
		if(edges[nodes[n].number-1][i]==1){
			if(nodes[i].state==0){
				nodes[i].p=&nodes[n];
				arb=1;
				nodes[i].treeNum=nodes[i].p->treeNum;
				nodes=DFS_visit(edges,i,nodeNum,nodes);
			}
		}
	}
	if(arb==0) ++TN;  
	nodes[n].state=2;
 	nodes[n].f=time=time+1;
	return nodes;
}	
int main(){
	FILE* f;
	f=fopen("input3-2.txt","r");
	int nodeNum;
	fscanf(f, "%d", &nodeNum);
	int **edges=malloc(sizeof(int*)*nodeNum);
	for(int i=0;i<nodeNum;i++)
		edges[i]=malloc(sizeof(int)*nodeNum);
	for(int i=0;i<nodeNum;i++)
		for(int j=0;j<nodeNum;j++)
			fscanf(f,"%d",&edges[i][j]);

	Node* nodes=malloc(sizeof(Node)*nodeNum);
	for(int i=0;i<nodeNum;i++){
		nodes[i].number=i+1;
		nodes[i].state=0;
		nodes[i].d=-1;
		nodes[i].f=-1;
		nodes[i].p=NULL;
		nodes[i].treeNum=-1;
	}
	
	int st=0;
	for(st=0;st<nodeNum;st++){
		if(nodes[st].state==0)
			nodes=DFS_visit(edges,st,nodeNum,nodes);
	}
	int l;
	Node key;
	for(int k=1;k<nodeNum;k++){
		key=nodes[k];
		for(l=k-1;l>=0;l--){
			if(nodes[l].d>key.d)
				nodes[l+1]=nodes[l];
			else break;
		}
		nodes[l+1]=key;
	}
	for(int i=0;i<nodeNum;i++)
		printf("%d ",nodes[i].number);
	printf("\n");
	for(int k=1;k<nodeNum;k++){
		key=nodes[k];
		for(l=k-1;l>=0;l--){
			if(nodes[l].number>key.number)
				nodes[l+1]=nodes[l];
			else break;
		}
		nodes[l+1]=key;
	}
	for(int i=1;i<nodeNum+1;i++)
		printf("%d: %d\n",i,nodes[i-1].treeNum);
	fclose(f);
	free(edges);
	free(nodes);

}
