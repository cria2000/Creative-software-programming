#include<stdio.h>
typedef struct
{
	double num;
	double com_num;
}Number;

void printComplex(Number com){
	printf("%lf + %lfi\n",com.num,com.com_num);}

void printAddComp(Number com1,Number com2){
	Number add={com1.num+com2.num,com1.com_num+com2.com_num};
	printComplex(add);}

void printMulComp(Number com1,Number com2){
	Number mul={((com1.num)*(com2.num))-((com1.com_num)*(com2.com_num)),((com1.num)*(com2.com_num))+((com1.com_num)*(com2.num))};
	printComplex(mul);}

int main(){
	Number com1,com2;
	scanf("%lf %lf %lf %lf",&com1.num,&com1.com_num,&com2.num,&com2.com_num);
	printf("Complex number1:\n");
	printComplex(com1);
	printf("Complex number2:\n");
	printComplex(com2);
	printf("sum:\n");
	printAddComp(com1,com2);
	printf("Multiplication:\n");
	printMulComp(com1,com2);
}


	


