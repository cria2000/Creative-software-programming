#include<stdio.h>
#include<stdlib.h>
void Merge(int A[], int TmpArray[], int Lpos, int Rpos, int RightEnd);
//recursive하게 Sort하기 위한 함수로 실제 값들이 들어있는 배열, sort하는 동안 값들을 저장한 임시 배열, 배열의 시작점, 끝점, 값들을 출력하기 위한 파일의 포인터를 input으로 받아 시작점이 끝점 보다 작은 경우 가운데 값을 center라는 변수에 넣어 Merge함수를 호출하여 sort되고 있는 과정을 출력해준다.(한 개의 element끼리 Merge될 때까지 recursive하게 함수가 호출된다.)
void MSort(int A[], int TmpArray[], int Left, int Right,FILE *f){
	int Center;
	if(Left<Right){
		Center=(Left+Right)/2;
		MSort(A, TmpArray, Left, Center,f);
		MSort(A, TmpArray, Center+1, Right,f);
		Merge(A, TmpArray, Left, Center+1, Right);
//sort되고 있는 과정을 보여주기 위한 for문
		for(int i=Right;i>=Left;i--)
			fprintf(f,"%d ", TmpArray[i]);
		fprintf(f,"\n");
	}
}
//실제 값들이 저장되어 있는 배열, sort하는 동안 값들을 임시 저장할 임시 배열, sort해야하는 배열 index의 left의 시작점, right의 시작점, 끝점을 input으로 받아 두 배열을 앞에서부터 비교하여 하나의 sort된 배열로 만들어준다. 즉, Lpos가 왼쪽 배열의 시작점, Rpos가 오른쪽 배열의 시작점으로 이미 sort되어 있는 이 두 배열을 합쳐 실제 값들이 저장되어 있는 배열로 옮겨준다.
void Merge(int A[], int TmpArray[], int Lpos, int Rpos, int RightEnd){
	int i, LeftEnd, NumElements, TmpPos;
	LeftEnd=Rpos-1;
	TmpPos=Lpos;
	NumElements=RightEnd-Lpos+1;
//각각의 시작점이 끝점을 넘어가지 않을 때까지 서로의 값들을 앞에서부터 비교해나간다
	while(Lpos<=LeftEnd&&Rpos<=RightEnd)
		if(A[Lpos]>=A[Rpos])
			TmpArray[TmpPos++]=A[Lpos++];
		else 
			TmpArray[TmpPos++]=A[Rpos++];
//하나의 배열이 모두 소진된 경우, 나머지 배열의 끝까지 임시 배열에 넣어준다. 
	while(Lpos<=LeftEnd)
		TmpArray[TmpPos++]=A[Lpos++];
	while(Rpos<=RightEnd)
		TmpArray[TmpPos++]=A[Rpos++];
//임시 배열에 저장된 sort된 값들을 실제 배열로 옮겨준다.
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

	

