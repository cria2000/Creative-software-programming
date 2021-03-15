#include<stdio.h>
typedef struct{
	char name[7];
	int score;
}Person;

void printScoreStars(Person* persons, int len){
	for(int j=0;j<3;j++){
		printf("%s ",persons[j].name);
	for (int i=0;i<(persons[j].score/len);i++){
		printf("*");

}
printf("\n");}}

int main(void){
	Person persons[3];
	for(int i=0; i<3; i++){
		scanf("%s %d",persons[i].name,&persons[i].score);}

	printScoreStars(persons,5);

}

