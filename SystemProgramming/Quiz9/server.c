#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define MAX_BUF 1024
#define MAX_FILE 10
void error(){
	printf("incorrect usage\n");
	exit(1);
}
int main(int argc, char *argv[]){
	char myString[MAX_BUF];
	FILE* infile;
	FILE* outfile[MAX_FILE];
	int i;

	if(argc<2 || argc >MAX_FILE) error();
	infile=fopen("KNOWN_FIFO", "r");
	for(i=1;i<argc;i++) outfile[i]=fopen(argv[i], "w");
	printf("open finished\n");
	while(1)
	{
		if(fgets(myString, MAX_BUF, infile)==NULL){
			printf("EOF read\n");
			exit(0);
		}

		printf("KNOWN_FIFO: '%s'\n", myString);
		for(i=1;i<argc;i++){
			fprintf(outfile[i], "%s", myString);
			fflush(outfile[i]);
			printf("wrote to %s\n", argv[i]);
		}
	}
	for(i=1;i<argc;i++) fclose(outfile[i]);
		fclose(infile);

}

