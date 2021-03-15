#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef struct{
	char* studentID;
	char* studentName;
}ElementType;
struct Node{
	ElementType element;
	PtrToNode next;
};
int IsLast(Position P, List L){
	return P->next==NULL;
}
Position Find(char* id,List L){
	Position P;
	P=L->next;
	while(P!=NULL&&atoi(P->element.studentID)!=atoi(id))
		P=P->next;
	return P;
}
Position FindPrevious(char* id, List L){
	Position P;
	P=L;
	while(P->next!=NULL&&atoi(P->next->element.studentID)!=atoi(id))
		P=P->next;
	return P;
}
void DeleteList(List L){
	Position P, Tmp;
	P=L->next;
	L->next=NULL;
	while(P!=NULL)
	{
		Tmp=P->next;
		free(P->element.studentID);
		free(P->element.studentName);
		free(P);
		P=Tmp;
	}
}
List MakeEmpty(List L){
	L=(List)malloc(sizeof(struct Node));
	ElementType header;
	L->element=header;
	L->next=NULL;
	return L;
}
int IsEmpty(List L){
	return L->next==NULL;
}
void CurrentList(FILE *f,List L){
	fprintf(f,"Current List > ");
	Position print=L;
	while(!IsLast(print,L)){
		fprintf(f,"%s %s",print->next->element.studentID,print->next->element.studentName);
		print=print->next;
		if(!IsLast(print,L))
			fprintf(f,"-");
	}
	fprintf(f,"\n");
}
void Insert(ElementType X, List L, Position P){
	Position temp;
	temp=malloc(sizeof(struct Node));
	temp->element=X;
	temp->next=P->next;
	P->next=temp;
}
void Delete(FILE *f,char* id, List L){
	Position P, temp;
	P=FindPrevious(id,L);
	if(!IsLast(P,L)){
		temp=P->next;
		P->next=temp->next;
		free(temp);
		fprintf(f,"Deletion Success : %s\n",id);
		CurrentList(f,L);
	}
	else 
		fprintf(f,"Deletion Failed : Student ID %s is not in the list.\n",id);
}
void PrintList(FILE *f,List L){
	fprintf(f,"-----LIST-----\n");
	Position p=L;
	while(!IsLast(p,L)){
		fprintf(f,"%s %s\n",p->next->element.studentID,p->next->element.studentName);
		p=p->next;
	}
	fprintf(f,"--------------\n");
}
void main(){
	FILE *f;
	FILE *f2;
	f=fopen("input.txt","r");
	f2=fopen("output.txt","w");
	List head;
	head=MakeEmpty(head);
	for(int i=0;i<30;i++){
		char *ans=(char*)malloc(sizeof(char));
		fscanf(f,"%s",ans);
			if(*ans=='i'){
				ElementType ele;
				ele.studentID=(char*)malloc(sizeof(char));
				ele.studentName=(char*)malloc(sizeof(char));
				char *first=(char*)malloc(sizeof(char));
				char *last=(char*)malloc(sizeof(char));
				fscanf(f,"%s %s %s",ele.studentID,first,last);
				sprintf(ele.studentName,"%s %s",first,last);
				if(IsEmpty(head)){
					Insert(ele,head,head);
					fprintf(f2,"Insertion Success : %s\n",ele.studentID);
					CurrentList(f2,head);
				}
				else{
					if(Find(ele.studentID,head)!=NULL){
						fprintf(f2, "Insertion failed. ID %s already exists.\n",ele.studentID);
						free(ele.studentID);
						free(ele.studentName);
					}
					else{	
						Position pos=head;
						while(pos->next!=NULL){
							if(atoi(ele.studentID)>atoi(pos->next->element.studentID)){
								pos=pos->next;
							}
							else{
								Insert(ele,head,pos);
								fprintf(f2,"Insertion Success : %s\n",ele.studentID);
								fprintf(f2,"Current List > ");
								Position print=head;
                                                                while(!IsLast(print,head)){
                                                                        fprintf(f2,"%s %s",print->next->element.studentID,print->next->element.studentName);
                                                                        print=print->next;
                                                                        if(!IsLast(print,head))
                                                                                fprintf(f2,"-");
                                                                        pos=pos->next;
                                                                }fprintf(f2,"\n");}}

						if(atoi(ele.studentID)>atoi(pos->element.studentID)){
							Insert(ele,head,pos);
							fprintf(f2,"Insertion Success : %s\n",ele.studentID);
							CurrentList(f2,head);}}
				free(first);
				free(last);
				}
			}
			else if(*ans=='d'){
				char* id=(char*)malloc(sizeof(char));
				fscanf(f,"%s",id);
				Delete(f2, id, head);
				free(id);
			}
			else if(*ans=='f'){
				char* id=(char*)malloc(sizeof(char));
				fscanf(f,"%s",id);
				if(Find(id, head)!=NULL){
					fprintf(f2,"Find Success : %s %s\n",Find(id,head)->element.studentID,Find(id,head)->element.studentName);
				}
				else
					fprintf(f2,"Find %s Failed. There is no student ID\n",id);
				free(id);
			}
			else if(*ans=='p'){
				PrintList(f2,head);
			}
			free(ans);}
	DeleteList(head);
	free(head);
	fclose(f);
	fclose(f2);
}

