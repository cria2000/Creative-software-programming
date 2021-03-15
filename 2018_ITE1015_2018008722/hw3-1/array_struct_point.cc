#include<stdio.h>
typedef struct
{
	int xpos;
	int ypos;
}Point;

void scale2x(Point* pp)
{
	pp->xpos*=2;
	pp->ypos*=2;
}
int main(){
	Point points[3];
	for (int i=0;i<3;i++){
		scanf("%d %d",&points[i].xpos,&points[i].ypos);}
	scale2x(&points[0]);
	scale2x(&points[1]);
	scale2x(&points[2]);
	for (int j=0;j<3;j++){
		printf("[%d] %d %d\n",j,points[j].xpos,points[j].ypos);}}
