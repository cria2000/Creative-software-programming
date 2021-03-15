#include<stdio.h>
typedef struct
{
	char name[10];
	int age;
} Person;
int main(){
	Person name_age[3];
	Person* p1=&name_age[0];
	Person* p2=&name_age[1];
	Person* p3=&name_age[2];
	for (int i=0;i<3;i++){
		scanf("%s %d",name_age[i].name,&name_age[i].age);}
	printf("Name:%s, Age:%d\n",p1->name,p1->age);
	printf("Name:%s, Age:%d\n",p2->name,p2->age);
	printf("Name:%s, Age:%d\n",p3->name,p3->age);}
