#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode *treeptr;
typedef struct TreeNode{
	int Value;
	treeptr left,right;
}TreeNode;
//insert�ϰ��� �ϴ� ���� head�� �����͸� input���� �Ѱ��־� node�� ����� insert���ִ� �Լ�.(insert�ϰ��� �ϴ� ���� root�� ����ִ� ���� ���ؼ� ������ �������� ũ�� ���������� �����͸� �Ű�, �����Ͱ� NULL�� �Ǵ� ���� �����Ҵ��� ���־� node�� ����� �ٿ��ش�.)
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
//DeleteNode �Լ��� ������ �Ǵ� �Լ���, head�� �����͸� input���� �޾�  ���� ū ��(���� �����ʿ� �ִ� ��)�� ã�� return���ش�. child�� �ΰ� �ִ� node�� ������ ��, �����Ǵ� node�� �ڸ��� ��ü���ֱ� ���� node�� ã�� �Լ��̴�.
treeptr FindMax(treeptr root){
	if(root==NULL)
		return NULL;
	else 
		while(root->right!=NULL)
			root=root->right;
	return root;
}
//�����ϰ��� �ϴ� ���� tree�� head�����͸� input���� �޾� delte�� tree�� head�����͸� return���ش�. �����ϰ��� �ϴ� ���� ���ϴ� node�� ������ ������ ��������, ũ�� ���������� �����͸� �Űܰ��� ���� �߰��ϸ� child�� ������ ���� delete�� �����Ѵ�. �ϳ��� ������ �����ϰ��� �ϴ� node�� child�� �� ���� node�� �������ְ�, �ΰ��� FindMax�Լ��� �̿��� �������ش�.
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
//ã���� �ϴ� ���� tree�� head �����͸� input���� �޾� ���� ã���� �� ��ġ��, ã�� ���ϸ� NULL�� return ���ִ� �Լ��̴�. ����������, ã���� �ϴ� ���� ���ϴ� node�� ���� ������ ����, ũ�� ���������� �̵��ϸ� ���� ã�´�. 
treeptr FindNode(int value, treeptr root){
	if(root==NULL)
		return NULL;
	if(value<root->Value)
		return FindNode(value,root->left);
	else if(value>root->Value)
		return FindNode(value, root->right);
	else return root;
}
//inorder������� ���� ���ʷ� print���ִ� �Լ�. printf�� File�� �����Ϳ� ���� ���� tree�� head �����͸� input���� �ش�.
void PrintInorder(FILE *f, treeptr root){
	if(root){
		PrintInorder(f,root->left);
		fprintf(f,"%d ",root->Value);
		PrintInorder(f,root->right);
	}
}
//preorder������� ���� ���ʷ� print���ִ� �Լ�. printf�� File�� �����Ϳ� ���� ���� tree�� head �����͸� input���� �ش�.

void PrintPreorder(FILE *f, treeptr root){
	if(root){
		fprintf(f,"%d ",root->Value);
		PrintPreorder(f,root->left);
		PrintPreorder(f,root->right);
	}
}
//postorder������� ���� ���ʷ� print���ִ� �Լ�. printf�� File�� �����Ϳ� ���� ���� tree�� head �����͸� input���� �ش�.
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
//insert�� �ϱ� ��, �� ���� tree�� �ִ��� Ȯ���ϱ� ���� FindNode�� ���. InsertNode�Լ��� recursion�Լ��̱� ������ �Լ� ������ print�� �ϰ� �� ��� ����� ���� �ʾ� FindNode�Լ��� ���.
		if(a=='i'){
			fscanf(f,"%d",&val);
			if(FindNode(val,root)==NULL){
				root=InsertNode(val,root);
			}
			else if(FindNode(val,root)!=NULL){
				fprintf(f2,"%d already exists.\n",val);
			}
			
		}
//delete�� �ϱ� ��, �� ���� tree�� �ִ��� Ȯ���ϱ� ���� FindNode�� ���. DeleteNode�Լ��� recursion�Լ��̱� ������ �Լ� ������ print�� �ϰ� �� ��� ����� ���� �ʾ� FindNode�Լ��� ���.
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






