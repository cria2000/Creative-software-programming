#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode *treeptr;
typedef struct TreeNode{
	int Value;
	treeptr left,right;
}TreeNode;
//insert하고자 하는 값과 head의 포인터를 input으로 넘겨주어 node를 만들어 insert해주는 함수.(insert하고자 하는 값과 root에 들어있는 값을 비교해서 작으면 왼쪽으로 크면 오른쪽으로 포인터를 옮겨, 포인터가 NULL이 되는 순간 동정할당을 해주어 node를 만들어 붙여준다.)
treeptr InsertNode(int value, treeptr root){
	if(root==NULL){
		root=malloc(sizeof(struct TreeNode));
		if(root==NULL)
			printf("Out of space!");
		else {
			root->Value=value;
			root->left=root->right=NULL;
		}
	}
	else if(value<root->Value){
		root->left=InsertNode(value,root->left);
	}
	else if(value>root->Value){
		root->right=InsertNode(value,root->right);
	}
	return root;
}
//DeleteNode 함수에 도움이 되는 함수로, head의 포인터를 input으로 받아  가장 큰 값(가장 오른쪽에 있는 값)을 찾아 return해준다. child가 두개 있는 node를 삭제할 때, 삭제되는 node의 자리를 대체해주기 위한 node를 찾는 함수이다.
treeptr FindMax(treeptr root){
	if(root==NULL)
		return NULL;
	else 
		while(root->right!=NULL)
			root=root->right;
	return root;
}
//삭제하고자 하는 값과 tree의 head포인터를 input으로 받아 delte된 tree의 head포인터를 return해준다. 삭제하고자 하는 값이 비교하는 node의 값보다 작으면 왼쪽으로, 크면 오른쪽으로 포인터를 옮겨가다 값을 발견하면 child의 개수에 따라 delete를 실행한다. 하나만 있으면 삭제하고자 하는 node의 child와 그 위의 node를 연결해주고, 두개면 FindMax함수를 이용해 삭제해준다.
treeptr DeleteNode(int value, treeptr root){
	treeptr temp;
	if(root==NULL)
		return root;
	else if(value<root->Value)
		root->left=DeleteNode(value,root->left);
	else if(value>root->Value)
		root->right=DeleteNode(value, root->right);
	else if(root->left&&root->right){
		temp=FindMax(root->left);
		root->Value=temp->Value;
		root->left=DeleteNode(root->Value,root->left);
	}
	else{
		temp=root;
		if(root->left==NULL)
			root=root->right;
		else if(root->right==NULL)
			root=root->left;
		free(temp);
	}
	return root;
}
//찾고자 하는 값과 tree의 head 포인터를 input으로 받아 값을 찾으면 그 위치를, 찾지 못하면 NULL를 return 해주는 함수이다. 마찬가지로, 찾고자 하는 값과 비교하는 node의 값이 작으면 왼쪽, 크면 오른쪽으로 이동하며 값을 찾는다. 
treeptr FindNode(int value, treeptr root){
	if(root==NULL)
		return NULL;
	if(value<root->Value)
		return FindNode(value,root->left);
	else if(value>root->Value)
		return FindNode(value, root->right);
	else return root;
}
//inorder방식으로 값을 차례로 print해주는 함수. printf할 File의 포인터와 값을 읽을 tree의 head 포인터를 input으로 준다.
void PrintInorder(FILE *f, treeptr root){
	if(root){
		PrintInorder(f,root->left);
		fprintf(f,"%d ",root->Value);
		PrintInorder(f,root->right);
	}
}
//preorder방식으로 값을 차례로 print해주는 함수. printf할 File의 포인터와 값을 읽을 tree의 head 포인터를 input으로 준다.

void PrintPreorder(FILE *f, treeptr root){
	if(root){
		fprintf(f,"%d ",root->Value);
		PrintPreorder(f,root->left);
		PrintPreorder(f,root->right);
	}
}
//postorder방식으로 값을 차례로 print해주는 함수. printf할 File의 포인터와 값을 읽을 tree의 head 포인터를 input으로 준다.
void PrintPostorder(FILE *f, treeptr root){
	if(root){
		PrintPostorder(f,root->left);
		PrintPostorder(f,root->right);
		fprintf(f,"%d ",root->Value);
	}
}
int main(){
	FILE *f;
	FILE *f2;
	int size;
	char a;
	int val;
	f=fopen("input.txt","r");
	f2=fopen("output.txt","w");
	fseek(f,0,SEEK_END);
	size=ftell(f);
	fseek(f,0,SEEK_SET);
	treeptr root=NULL;
	for(int i=0;i<size;i++){
		fscanf(f,"%c",&a);
//insert를 하기 전, 그 값이 tree에 있는지 확인하기 위해 FindNode를 사용. InsertNode함수는 recursion함수이기 때문에 함수 내에서 print를 하게 될 경우 제대로 되지 않아 FindNode함수를 사용.
		if(a=='i'){
			fscanf(f,"%d",&val);
			if(FindNode(val,root)==NULL){
				root=InsertNode(val,root);
			}
			else if(FindNode(val,root)!=NULL){
				fprintf(f2,"%d already exists.\n",val);
			}
			
		}
//delete를 하기 전, 그 값이 tree에 있는지 확인하기 위해 FindNode를 사용. DeleteNode함수는 recursion함수이기 때문에 함수 내에서 print를 하게 될 경우 제대로 되지 않아 FindNode함수를 사용.
		else if(a=='d'){
			fscanf(f,"%d",&val);
			if(FindNode(val,root)==NULL)
				fprintf(f2, "Deletion failed. %d does not exist.\n",val);
			else 
				root=DeleteNode(val,root);
		}
		else if(a=='f'){
			fscanf(f,"%d",&val);
			if(FindNode(val,root)==NULL)
				fprintf(f2,"%d is not in the tree\n",val);
			else 
				fprintf(f2,"%d is in the tree\n",val);
		}
		else if(a=='p'){
			fscanf(f,"%c",&a);
			if(a=='i'){
				fprintf(f2,"pi - ");
				PrintInorder(f2,root);
				fprintf(f2,"\n");
			}
			else if(a=='r'){
				fprintf(f2,"pr - ");
				PrintPreorder(f2,root);
				fprintf(f2, "\n");
			}
			else if(a=='o'){
				fprintf(f2,"po - ");
				PrintPostorder(f2,root);
				fprintf(f2,"\n");
			}
		}

	}
	fclose(f);
	fclose(f2);
}






