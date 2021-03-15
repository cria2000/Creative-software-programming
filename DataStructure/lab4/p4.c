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
//threaded_ptr을 input으로 받아 해당 ptr의 thread들이 false인 경우 왼쪽 가장 끝의 node까지 가도록 해주는 함수. 만약 true라면 input으로 받은 ptr의 right_child를 바로 return 해준다.
threaded_ptr insucc(threaded_ptr tree){
	threaded_ptr temp;
	temp=tree->right_child;
	if(!tree->right_thread)
		while(!temp->left_thread)
			temp=temp->left_child;
	return temp;
}
//temp의 data의 값을 print할 file의 포인터와 읽을 threaded tree의 한 노드(root가 될 예정) 을 input으로 받아 insucc함수를 이용하여 node들을 차례대로 읽을 수 있게 한다음 각 node의 data를 file에 출력해주는 함수
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
//input파일에 있는 데이터들을 node라는 배열에 차례로 넣는다.
	for(int i=1;i<num+1;i++)
		fscanf(f,"%c ",&node[i]);
	threaded_ptr* pnum=malloc(sizeof(threaded_ptr)*num);
//pnum이라는 배열을 pnum[i]별로 동적할당을 해주고 같은 i끼리 node의 데이터를 pnum->data에 넣어준다.
	for(int i=1;i<num+1;i++){
		pnum[i]=malloc(sizeof(threaded_tree));
		pnum[i]->data=node[i];
	}
//root의 값들을 설정해준다.
	root->left_thread=false;
	root->left_child=pnum[1];
	root->right_thread=false;
	root->right_child=root;
//각 pnum[i]의 left_child 와 right_child가 일정한 규칙을 가짐을 이용하여 값을 넣어준다.(1번째(A)는 2번째(B)와 3번째(C)를, 2번째는 4번째(D)와 5번째(E)를 가리킴) 이 for문으로 right_child와 left_child가 정해지는 pnum=A, B, C, D 
	for(int i=1;i<(num/2)+1;i++){
		pnum[i]->left_child=pnum[2*i];
		pnum[i]->right_child=pnum[(2*i)+1];
	}
//pnum[i]의 right_child와 left_child에 값이 들어가있으냐의 여부에 따라(위에서 node를 child값으로 가지는 node들만 설정해놓았으니) thread의 값을 설정한다.
	for(int i=1;i<num+1;i++){
		if(pnum[i]->left_child!=NULL)
			pnum[i]->left_thread=false;
		else pnum[i]->left_thread=true;
		if(pnum[i]->right_child!=NULL)
			pnum[i]->right_thread=false;
		else pnum[i]->right_thread=true;
	}
//가장자리에 있는 node들의 값을 설정한다. 첫번째 단락이 가장 왼쪽의 node설정, i에서 1을 뺀 후가 가장 오른쪽의 node를 설정하는 것이다. 
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
//설정되지 않은 남은 node들을 직접 연결시켜준다.(E, F, I)
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

