#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define MAX_BUF 10
void error(){
	printf("incorrect usage\n");
	exit(1);
}
int main(int argc,char *argv[]){
	char myString[MAX_BUF];
	
	if(argc != 2) error();
	FILE* outfile=fopen("KNOWN_FIFO","w");
	if(!outfile) error();
	printf("KNOWN_FIFO open finished\n");
	FILE* infile = fopen (argv[1], "r");
	if(!infile) error();
	printf("client FIFO open finished");
	while(fgets(myString, MAX_BUF, stdin)!=NULL)
	{
		printf("to KNOWN_FIFO: '%s'\n", myString);
		fprintf(outfile, "%s", myString);
		fflush(outfile);
		while(fgets(myString, MAX_BUF, infile)!=NULL)
			printf("from %s to KNOWN_FIFO : '%s'\n", argv[1], myString);
	}
	printf("EOF from KNOWN_FIFO\n");
	fclose(outfile);
	fclose(infile);
	return 0;
}
