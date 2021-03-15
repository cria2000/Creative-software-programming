#include<stdio.h>
#include<stdlib.h>
struct AVLNode;
typedef struct AVLNode *Position;
typedef struct AVLNode *AVLTree;
struct AVLNode{
	int Element;
	AVLTree Left;
	AVLTree Right;
	int Height;
};
//Position의 Height를 return해주는 함수(Position이 NULL이면 Height는 -1이다)
int Height(Position P){
	if(P==NULL)
		return -1;
	else
		return P->Height;
}
//Rotate와 Insert에서 Height를 결정할 때, 도움을 주는 함수로 int2개를 input으로 받아 더 큰 것(같다면 둘 중 하나-여기서는 b)을 return한다.(child의 Height 중 더 큰 것을 찾기위한 것)
int Max(int a, int b){
	if(a>b) return a;
	else return b;
}
//Position을 input으로 받아 이 Position의 왼쪽child의 왼쪽에 node가 insert됨으로써 AVL tree가 깨지는 경우 Rotate를 하기 위한 함수(깨진 Position과 Position의 Left child의 위치를 바꾼 tree가 return된다.)
Position SingleRotateWithLeft(Position K){
	Position K1;
	K1=K->Left;
	K->Left=K1->Right;
	K1->Right=K;

	K->Height=Max(Height(K->Left),Height(K->Right))+1;
	K1->Height=Max(Height(K1->Left),K->Height)+1;

	return K1;
}
//Position을 input으로 받아 이 Position의 오른쪽child의 오른쪽에 node가 insert됨으로써 AVL tree가 깨지는 경우 Rotate를 하기 위한 함수(깨진 Position과 Position의 right child의 위치를 바꾼 tree가 return된다.)
Position SingleRotateWithRight(Position K){
	Position K1;
	K1=K->Right;
	K->Right=K1->Left;
	K1->Left=K;

	K->Height=Max(Height(K->Left),Height(K->Right))+1;
	K1->Height=Max(Height(K1->Left),K->Height)+1;

	return K1;
}
//Position을 input으로 받아 이 Position의 왼쪽child의 오른쪽에 node가 insert됨으로써 AVL tree가 깨지는 경우 Rotate를 하기 위한 함수. Position의 왼쪽 child의 right child와 왼쪽 child의 위치를 바꿔주고, position과 Position의 left의 위치를 바꾼 후 바꿔진 root를 return 해준다.
Position DoubleRotateWithLeft(Position K){
	K->Left=SingleRotateWithRight(K->Left);
	return SingleRotateWithLeft(K);
}
//Position을 input으로 받아 이 Position의 오른쪽child의 왼쪽에 node가 insert됨으로써 AVL tree가 깨지는 경우 Rotate를 하기 위한 함수. Position의 오른쪽 child의 left child와 오른쪽 child의 위치를 바꿔주고, position과 Position의 left의 위치를 바꾼 후 바꿔진 root를 return 해준다.
Position DoubleRotateWithRight(Position K){
	K->Right=SingleRotateWithLeft(K->Right);
	return SingleRotateWithRight(K);
}	
//AVLETree와(root) 값을 출력할 FILE의 포인터, insert할 값인 X를 input으로 받고,X를 insert한 다음, height의 차이가 2가 되면, AVLtree로 만들기 위해 rotate를 해준 후 그 AVLTree를 return해준다. X의 값이 AVLTree(root)의 값보다 작으면 Left rotate를, 크면 right rotate를 해준다.
AVLTree Insert(int X,AVLTree T,FILE *f){
	if(T==NULL){
		T=malloc(sizeof(struct AVLNode));
		if(T==NULL)
			fprintf(f,"Out of sapce!!");
		else{
			T->Element=X;
			T->Height=0;
			T->Left=T->Right=NULL;
		}
	}
	else if(X<T->Element){
		T->Left=Insert(X,T->Left,f);
		if(Height(T->Left)-Height(T->Right)==2)
			if(X<T->Left->Element)
				T=SingleRotateWithLeft(T);
			else 
				T=DoubleRotateWithLeft(T);
	}
	else if(X>T->Element){
		T->Right=Insert(X,T->Right,f);
		if(Height(T->Right)-Height(T->Left)==2)
			if(X>T->Right->Element)
				T=SingleRotateWithRight(T);
			else 
				T=DoubleRotateWithRight(T);
	}
	else if(X==T->Element){
		fprintf(f,"%d already in the tree!\n",X);
	}
	T->Height=Max(Height(T->Left),Height(T->Right))+1;
	return T;
}
//inorder방식으로 root의 값들을 출력해주는 함수. 값을 출력할 AVLTree와 값을 입력할 FILE의 포인터를 input으로 받는다.
void PrintInorder(FILE *f, AVLTree root){
	if(root){
		PrintInorder(f,root->Left);
		fprintf(f,"%d(%d) ",root->Element,root->Height);
		PrintInorder(f,root->Right);
	}
}
int main(){
	FILE *f;
	FILE *f2;
	f=fopen("input.txt","r");
	f2=fopen("output.txt","w");
	int num;
	AVLTree root=malloc(sizeof(struct AVLNode));
	fscanf(f,"%d",&num);
	root->Element=num;
	root->Left=root->Right=NULL;
	root->Height=0;
	PrintInorder(f2,root);
	fprintf(f2,"\n");
	while(fscanf(f,"%d",&num)!=EOF){
		root=Insert(num,root,f2);
		PrintInorder(f2,root);
		fprintf(f2,"\n");
	}
	fclose(f);
	fclose(f2);
	free(root);
}




