#include<stdio.h>
#include<math.h>
typedef struct
{
	double x;
	double y;
}Point;

typedef struct
{
	char name[7];
	Point points[3];
}Person;

Point find_max(Person* persons,Point* max_point){
	scanf("%s",persons->name);
	for(int i=0;i<3;i++){
		scanf("%lf %lf",&persons->points[i].x,&persons->points[i].y);
		if(sqrt(((max_point->x)*(max_point->x))+((max_point->y)*(max_point->y)))<sqrt(((persons->points[i].x)*(persons->points[i].x))+((persons->points[i].y)*(persons->points[i].y)))){
			(*max_point)={persons->points[i].x,persons->points[i].y};}}}

int main(void){
	Person p1,p2,p3;
        Point max1,max2,max3={0.0};

	find_max(&p1,&max1);
	find_max(&p2,&max2);
	find_max(&p3,&max3);
	printf("%s (%lf, %lf)\n",p1.name,max1.x,max1.y);
	printf("%s (%lf, %lf)\n",p2.name,max2.x,max2.y);
	printf("%s (%lf, %lf)\n",p3.name,max3.x,max3.y);}
