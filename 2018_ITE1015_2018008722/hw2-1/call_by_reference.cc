#include<stdio.h>
void square(double* a);
int main(){
	double dvar;
	scanf("%lf",&dvar);
	square(&dvar);
	printf("%f\n",dvar);
}

void square(double* a){

	*a=(*a)*(*a);
	
}
