#include<stdio.h>
#include<stdlib.h>
void Merge(int A[], int TmpArray[], int Lpos, int Rpos, int RightEnd);
//recursive�ϰ� Sort�ϱ� ���� �Լ��� ���� ������ ����ִ� �迭, sort�ϴ� ���� ������ ������ �ӽ� �迭, �迭�� ������, ����, ������ ����ϱ� ���� ������ �����͸� input���� �޾� �������� ���� ���� ���� ��� ��� ���� center��� ������ �־� Merge�Լ��� ȣ���Ͽ� sort�ǰ� �ִ� ������ ������ش�.(�� ���� element���� Merge�� ������ recursive�ϰ� �Լ��� ȣ��ȴ�.)
void MSort(int A[], int TmpArray[], int Left, int Right,FILE *f){
	int Center;
	if(Left<Right){
		Center=(Left+Right)/2;
		MSort(A, TmpArray, Left, Center,f);
		MSort(A, TmpArray, Center+1, Right,f);
		Merge(A, TmpArray, Left, Center+1, Right);
//sort�ǰ� �ִ� ������ �����ֱ� ���� for��
		for(int i=Right;i>=Left;i--)
			fprintf(f,"%d ", TmpArray[i]);
		fprintf(f,"\n");
	}
}
//���� ������ ����Ǿ� �ִ� �迭, sort�ϴ� ���� ������ �ӽ� ������ �ӽ� �迭, sort�ؾ��ϴ� �迭 index�� left�� ������, right�� ������, ������ input���� �޾� �� �迭�� �տ������� ���Ͽ� �ϳ��� sort�� �迭�� ������ش�. ��, Lpos�� ���� �迭�� ������, Rpos�� ������ �迭�� ���������� �̹� sort�Ǿ� �ִ� �� �� �迭�� ���� ���� ������ ����Ǿ� �ִ� �迭�� �Ű��ش�.
void Merge(int A[], int TmpArray[], int Lpos, int Rpos, int RightEnd){
	int i, LeftEnd, NumElements, TmpPos;
	LeftEnd=Rpos-1;
	TmpPos=Lpos;
	NumElements=RightEnd-Lpos+1;
//������ �������� ������ �Ѿ�� ���� ������ ������ ������ �տ������� ���س�����
	while(Lpos<=LeftEnd&&Rpos<=RightEnd)
		if(A[Lpos]>=A[Rpos])
			TmpArray[TmpPos++]=A[Lpos++];
		else 
			TmpArray[TmpPos++]=A[Rpos++];
//�ϳ��� �迭�� ��� ������ ���, ������ �迭�� ������ �ӽ� �迭�� �־��ش�. 
	while(Lpos<=LeftEnd)
		TmpArray[TmpPos++]=A[Lpos++];
	while(Rpos<=RightEnd)
		TmpArray[TmpPos++]=A[Rpos++];
//�ӽ� �迭�� ����� sort�� ������ ���� �迭�� �Ű��ش�.
	for(i=0; i<NumElements; i++, RightEnd--)
		A[RightEnd]=TmpArray[RightEnd];
}
int main(){
	FILE *f;
	FILE *f2;
	f=fopen("input.txt","r");
	f2=fopen("output.txt","w");
	int num;
	fscanf(f,"%d",&num);
	int *arr=malloc(sizeof(int)*num);
	int *tmp=malloc(sizeof(int)*num);
	fprintf(f2,"input : \n");
	for(int i=0;i<num;i++){
		fscanf(f,"%d",&arr[i]);
		fprintf(f2,"%d ",arr[i]);
	}
	fprintf(f2,"\n\nrecursive : \n");
	MSort(arr,tmp,0,num-1,f2);
}

	

