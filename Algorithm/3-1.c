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
	int am=0;
	if(nodes[n].p==NULL) nodes[n].treeNum=TN;
	for(int i=0;i<nodeNum;i++){
		if(edges[nodes[n].number-1][i]==1){
			if(nodes[i].state==0){
				printf("(%d,%d) tree edge\n",nodes[nodes[n].number-1].number, nodes[i].number);
				nodes[i].p=&nodes[n];
				nodes[i].treeNum=nodes[i].p->treeNum;
				am=1;
				nodes=DFS_visit(edges,i,nodeNum,nodes);
			
			}							
			else{
				if(nodes[i].treeNum!=nodes[nodes[n].number-1].treeNum)
					printf("(%d,%d) cross edge\n",nodes[nodes[n].number-1].number, nodes[i].number);
				else if(nodes[nodes[n].number-1].d>=nodes[i].d)
					printf("(%d,%d) back edge\n", nodes[nodes[n].number-1].number, nodes[i].number);
				else if(nodes[nodes[n].number-1].d<nodes[i].d)
					printf("(%d,%d) forward edge\n", nodes[nodes[n].number-1].number, nodes[i].number);
			 
			}
			
		}
	}
	if(am==0){
	       	++TN;
	}
	nodes[n].state=2;
 	nodes[n].f=time=time+1;
	return nodes;
}	
int main(){
	FILE *f;
	f=fopen("input3-1.txt","r");
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
	for(int i=0;i<nodeNum;i++){
		nodes[i].number=i+1;
		nodes[i].state=0;
		nodes[i].d=-1;
		nodes[i].f=-1;
		nodes[i].p=NULL;
		
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
	fclose(f);
	free(edges);
	free(nodes);


}
