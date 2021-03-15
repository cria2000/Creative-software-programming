#include<stdio.h>
typedef struct
{
	char name[10];
	int age;
} Person;
int main(){
	Person name_age;
	scanf("%s %d",name_age.name,&name_age.age);
	printf("name: %s\n",name_age.name);
	printf("age: %d\n",name_age.age);}


