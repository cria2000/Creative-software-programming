#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define order 3
typedef struct B_node{
	int n_keys;
	struct B_node *child[order];
	int key[order-1];
}B_node;
B_node *root;
void initialize(B_node *node){
	node->child[0]=NULL;
	node->child[1]=NULL;
	node->child[2]=NULL;
	node->n_keys=0;
}
bool isFull(B_node *node){
	if(node->n_keys==2) return true;
	return false;
}
bool isLeaf(B_node *node){
	for(int i=0;i<order;i++)
		if(node->child[i]!=NULL) return false;
	return true;
}

void insert_root(int _key,B_node *node){//use when node is not full
	if(node->n_keys==0){
		node->key[0]=_key;
		node->n_keys=1;
	}
	else if(node->n_keys==1){
		if(node->key[0]<_key)
			node->key[1]=_key;
		else if(node->key[0]>_key){
			node->key[1]=node->key[0];
			node->key[0]=_key;
		}
		node->n_keys=2;
	}
}
void split_root(int _key,B_node *node){//use when root is full but want to insert to root
	node->child[0]=malloc(sizeof(B_node));
	node->child[1]=malloc(sizeof(B_node));
	if(node->key[0]>_key){
		node->child[0]->key[0]=_key;
		node->child[1]->key[0]=node->key[1];
		node->key[1]=0;
		node->n_keys=1;
	}
	else if(node->key[1]<_key){
		node->child[0]->key[0]=node->key[0];
		node->child[1]->key[0]=_key;
		node->key[0]=node->key[1];
		node->key[1]=0;
		node->n_keys=1;
	}
	else{
		node->child[0]->key[0]=node->key[0];
		node->child[1]->key[0]=node->key[0];
		node->key[0]=_key;
		node->key[1]=0;
		node->n_keys=1;
	}
}
void insert(int _key){
	B_node *x=root;
	if(isLeaf(x)){
		if(!isFull(x))
			insert_root(_key,x);
		else{
			split_root(_key,x);
	
		}
	}
}
int main(){
	FILE *f;
	FILE *f2;
	f=fopen("input.txt","r");
	char ans;
	int _key;
	root=malloc(sizeof(B_node));
	initialize(root);
	while(ans!='p'){
		fscanf(f,"%c",&ans);
		fscanf(f,"%d",&_key);
		insert(_key);
	}
}



