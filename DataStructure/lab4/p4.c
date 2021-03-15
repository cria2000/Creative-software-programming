#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct threaded_tree *threaded_ptr;
typedef struct threaded_tree{
	bool left_thread;
	threaded_ptr left_child;
	char data;
	threaded_ptr right_child;
	bool right_thread;
}threaded_tree;
//threaded_ptr�� input���� �޾� �ش� ptr�� thread���� false�� ��� ���� ���� ���� node���� ������ ���ִ� �Լ�. ���� true��� input���� ���� ptr�� right_child�� �ٷ� return ���ش�.
threaded_ptr insucc(threaded_ptr tree){
	threaded_ptr temp;
	temp=tree->right_child;
	if(!tree->right_thread)
		while(!temp->left_thread)
			temp=temp->left_child;
	return temp;
}
//temp�� data�� ���� print�� file�� �����Ϳ� ���� threaded tree�� �� ���(root�� �� ����) �� input���� �޾� insucc�Լ��� �̿��Ͽ� node���� ���ʴ�� ���� �� �ְ� �Ѵ��� �� node�� data�� file�� ������ִ� �Լ�
void tinorder(FILE *f, threaded_ptr tree){
	threaded_ptr temp=tree;
	for(;;){
		temp=insucc(temp);
		if(temp==tree) break;
		fprintf(f,"%c ",temp->data);
	}
	fprintf(f,"\n");
}
int main(){
	FILE *f;
	FILE *f2;
	f=fopen("input.txt","r");
	f2=fopen("output.txt","w");
	int num;
	fscanf(f,"%d ",&num);
	threaded_ptr root=malloc(sizeof(threaded_tree));
	char *node=malloc(sizeof(char)*num);
//input���Ͽ� �ִ� �����͵��� node��� �迭�� ���ʷ� �ִ´�.
	for(int i=1;i<num+1;i++)
		fscanf(f,"%c ",&node[i]);
	threaded_ptr* pnum=malloc(sizeof(threaded_ptr)*num);
//pnum�̶�� �迭�� pnum[i]���� �����Ҵ��� ���ְ� ���� i���� node�� �����͸� pnum->data�� �־��ش�.
	for(int i=1;i<num+1;i++){
		pnum[i]=malloc(sizeof(threaded_tree));
		pnum[i]->data=node[i];
	}
//root�� ������ �������ش�.
	root->left_thread=false;
	root->left_child=pnum[1];
	root->right_thread=false;
	root->right_child=root;
//�� pnum[i]�� left_child �� right_child�� ������ ��Ģ�� ������ �̿��Ͽ� ���� �־��ش�.(1��°(A)�� 2��°(B)�� 3��°(C)��, 2��°�� 4��°(D)�� 5��°(E)�� ����Ŵ) �� for������ right_child�� left_child�� �������� pnum=A, B, C, D 
	for(int i=1;i<(num/2)+1;i++){
		pnum[i]->left_child=pnum[2*i];
		pnum[i]->right_child=pnum[(2*i)+1];
	}
//pnum[i]�� right_child�� left_child�� ���� ���������� ���ο� ����(������ node�� child������ ������ node�鸸 �����س�������) thread�� ���� �����Ѵ�.
	for(int i=1;i<num+1;i++){
		if(pnum[i]->left_child!=NULL)
			pnum[i]->left_thread=false;
		else pnum[i]->left_thread=true;
		if(pnum[i]->right_child!=NULL)
			pnum[i]->right_thread=false;
		else pnum[i]->right_thread=true;
	}
//�����ڸ��� �ִ� node���� ���� �����Ѵ�. ù��° �ܶ��� ���� ������ node����, i���� 1�� �� �İ� ���� �������� node�� �����ϴ� ���̴�. 
	int i=2;
	int j=1;
	int k;
	while(pnum[i]!=NULL){
		if(pnum[i]->left_thread==true)
			pnum[i]->left_child=root;
		if(pnum[i]->right_thread==true){
			for(k=1;k<j;k++)
				k=k+(k*2);
			pnum[i]->right_child=pnum[k];
		}
		i=i-1;
		if(pnum[i]->right_thread==true)
			pnum[i]->right_child=root;
		if(pnum[i]->left_thread==true){
			for(k=1;k<j;k++)
				k=k+(k*2);
			pnum[i]->left_child=pnum[k-1];
		}
		i=i+1;
		i=i*2;
		++j;
	}
//�������� ���� ���� node���� ���� ��������ش�.(E, F, I)
	pnum[5]->left_child=pnum[2];
	pnum[5]->right_child=pnum[1];
	pnum[6]->left_child=pnum[1];
	pnum[6]->right_child=pnum[3];
	pnum[9]->left_child=pnum[4];
	pnum[9]->right_child=pnum[2];
	tinorder(f2,root);
	free(node);
	free(pnum);
	fclose(f);
	fclose(f2);
}

