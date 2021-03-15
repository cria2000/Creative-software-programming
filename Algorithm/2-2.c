#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *f;
	f=fopen("input2-2.txt","r");
	int size;
	fscanf(f, "%d", &size);
	int p[size]; //price array
	for(int i=1;i<size+1;i++){
		fscanf(f,"%d",&p[i]);
	}
	int s[size];
	int r[size];
	r[0]=0;
	for(int j=1;j<size+1;j++){
		int q=-1;
		for(int k=1; k<j+1;k++){
			if(q<p[k]+r[j-k]){
				q=p[k]+r[j-k];
				s[j]=k;
			}	
		}

		r[j]=q;
	}
	int n=size;
	printf("%d\n", r[n]);
	while(n>0){
		printf("%d ",s[n]);
		n=n-s[n];
	}
	printf("\n");
	fclose(f);

}

