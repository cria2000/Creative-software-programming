#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linked_list.h"

char** split(char *str,const char *delim){
	char **string_list = (char **)malloc(10 * sizeof(char *));
	for(int i=0;i<10;++i){
		string_list[i]=NULL;}

	int idx=0;
	char *token=strtok(str,delim);
	while (token!=NULL){
		string_list[idx]=(char *)malloc(strlen(token)+1);
		strcpy(string_list[idx],token);
		token=strtok(NULL,delim);

		++idx;
	}
	return string_list;
}
int main(void){
	FILE *f;
	struct Item head; 
	struct Item* head1;
	char sub[10];
        char *s=(char *)malloc(100*sizeof(char));
	f=fopen("input.txt","r");
	fgets(s,100,f);
	char **item=split(s,":");
	head1=create_item();
	strcpy(head.Name,item[0]);
	strcpy(head.Age,item[1]);
	strcpy(head.Id,item[2]);
	char **subjects=split(item[3],",");
	head.Subjects=subjects;
	memcpy(head1,&head,sizeof(struct Item));
	head1->next=NULL;



	struct Item n;
	struct Item* n1;
	while(fgets(s,100,f)!=NULL){
		int j=1;
		char **items=split(s,":");
		n1=create_item();
		strcpy(n.Name,items[0]);
		strcpy(n.Age,items[1]);
		strcpy(n.Id,items[2]);
		char **subjects1=split(items[3],",");
                n.Subjects=subjects1;
		memcpy(n1,&n,sizeof(struct Item));
		insert_item(head1,n1);
		
	}


	char* result;
	struct Item* nod=head1;
	while(nod->next!=NULL){
		result=strstr(nod->Id,"2013");
		if(result!=NULL){
			printf("%s: %s:",nod->Name,nod->Id);
			for(int i=0;i<10&&nod->Subjects[i]!=NULL;i++){
				printf(" %s",nod->Subjects[i]);}
	
			
			}
		nod=nod->next;}
	if(nod->next==NULL&&strstr(nod->Id,"2013")!=NULL){
		printf("%s: %s:",nod->Name,nod->Id);
		for(int ii=0;ii<10&&nod->Subjects[ii]!=NULL;ii++){
			printf(" %s",nod->Subjects[ii]);}
	
	}
		
}


