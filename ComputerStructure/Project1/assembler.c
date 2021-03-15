#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAXLINELENGTH 1000
int readAndParse(FILE *, char *, char *, char *, char *, char *);
int isNumber(char *);
int main(int argc, char *argv[])
{ 
	char *inFileString, *outFileString;
       	FILE *inFilePtr, *outFilePtr;
	char label[MAXLINELENGTH], opcode[MAXLINELENGTH],arg0[MAXLINELENGTH],arg1[MAXLINELENGTH], arg2[MAXLINELENGTH];
	
	/* these are for storing labels */
	/* the index of the array(labels) is that label's address */
	int address = 0;
	char** labels = malloc(sizeof(char*)*MAXLINELENGTH);
	for(int i = 0; i<MAXLINELENGTH;i++)
		labels[i] = malloc(sizeof(char)*6);

	if (argc != 3) {
		printf("error: usage: %s <assembly-code-file> <machine-code-file>\n",argv[0]);
		exit(1);
	}
	inFileString = argv[1];
	outFileString = argv[2];
	inFilePtr = fopen(inFileString, "r");
	if (inFilePtr == NULL) {
		printf("error in opening %s\n", inFileString);
		exit(1);
	}
	outFilePtr = fopen(outFileString, "w");
	if (outFilePtr == NULL) {
		printf("error in opening %s\n", outFileString);
		exit(1);
	}
	while(readAndParse(inFilePtr,label,opcode,arg0, arg1, arg2)){
		if(label[0]!='\0'){
			int i;
			if (label[0]=='0' | label[0]=='1' | label[0]=='2' | label[0]=='3' | label[0]=='4'  | label[0]=='5' | label[0]=='6' | label[0]=='7' | label[0]=='8' | label[0]=='9' | strlen(label) > 6){
				printf("error : It does not conform to the format of the label\n%s\n",label);
				return(1);
			}
			for(int i=0;i<address;i++){
				if(!strcmp(labels[i], label)){
					printf("error : duplicate lables\n%s\n",label);
					return(1);
				}
			}
			strcpy(labels[address],label);
		}
		++address;

	}
	rewind(inFilePtr);
	address = 0;
	/* here is an example for how to use readAndParse to read a line from inFilePtr */
	while (readAndParse(inFilePtr, label, opcode, arg0, arg1, arg2) ) {
	/* after doing a readAndParse, you may want to do the following to test the opcode */
	/* write down the binary in OutFilePtr first, and change it to dicimal later */
//	for(int k=0;k<10;k++){
//		readAndParse(inFilePtr, label, opcode, arg0, arg1, arg1);
//		printf("%s\n",opcode);
		printf("%s|%s|%s|%s|%s\n", label, opcode, arg0, arg1, arg2);
	if (!strcmp(opcode, "add")) {
		if(isNumber(arg0)&&isNumber(arg1)&&isNumber(arg2)){
			fprintf(outFilePtr, "%d\n",atoi(arg0) << 19 | atoi(arg1) << 16 | atoi(arg2));
		}
	}
	else if(!strcmp(opcode, "nor")){
		if(isNumber(arg0)&&isNumber(arg1)&&isNumber(arg2)){
			fprintf(outFilePtr, "%d\n",1 << 22 | atoi(arg0) << 19 | atoi(arg1) << 16 | atoi(arg2));
		}
	}
	else if(!strcmp(opcode, "lw")||!strcmp(opcode,"sw")){
		if(isNumber(arg0)&&isNumber(arg1)){
			int tempNumber;
			if(!strcmp(opcode,"lw"))
				tempNumber = 2 << 22 | atoi(arg0) << 19 | atoi(arg1) << 16;
			else if(!strcmp(opcode, "sw"))
				tempNumber = 3 << 22 | atoi(arg0) << 19 | atoi(arg1) << 16;	
			if(isNumber(arg2)){
				if(atoi(arg2)>=-32768&&atoi(arg2)<=32767)
					fprintf(outFilePtr, "%d\n", tempNumber | atoi(arg2) & 0xffff);
				else{
					printf("error : offsetFields that don't fit in 16 bits\n");
					return(1);
				}
			}
			else{
				int define = 0;
				for(int i=0;i<MAXLINELENGTH;i++){
					if(!strcmp(labels[i],arg2)){
						define = 1;
						/* i can not be more than 16bits because MAXLINELENGTH is 1000 */
						fprintf(outFilePtr, "%d\n", tempNumber | i & 0xffff);
						break;
					}
				}
				if(define == 0){
					printf("error : undefined labels\n%s\n",arg2);
					return(1);
				}
			}
		}
	}
	else if(!strcmp(opcode, "beq")){
		if(isNumber(arg0) && isNumber(arg1)){
			if(isNumber(arg2)){
				if(atoi(arg2) >= -32768 && atoi(arg2) <= 32767)
					fprintf(outFilePtr, "%d\n", 4 << 22 | atoi(arg0) << 19 | atoi(arg1) << 16 | (atoi(arg2) & 0xffff));
				else{
					printf("error : offsetFields that don't fit in 16 bits\n");
					return(1);
				}
			}
			else{
				int define = 0;
				for(int i= 0;i < MAXLINELENGTH; i++){
					if(!strcmp(labels[i],arg2)){
						define = 1;
						fprintf(outFilePtr, "%d\n", 4 << 22 | atoi(arg0) << 19 | atoi(arg1) << 16 | ((i - 1 - address) & 0xffff));
						break;
					}
				}
				if(define == 0){
					printf("error : undefined lables\n%s\n",arg2);
					return(1);
				}
			}
		}
	}
	else if(!strcmp(opcode, "jalr")){
		if(isNumber(arg0)&&isNumber(arg1))
			fprintf(outFilePtr,"%d\n",5 << 22 | atoi(arg0) << 19 | atoi(arg1) << 16);
	}
	else if(!strcmp(opcode, "halt")){
		fprintf(outFilePtr,"%d\n", 6 << 22);
	}
	else if(!strcmp(opcode, "noop")){
		fprintf(outFilePtr,"%d\n", 7 << 22);
	}
	else if(!strcmp(opcode, ".fill")){
		if(isNumber(arg0)){
			if(atoi(arg0)>=-2147483648&&atoi(arg0)<=2147483647)
				fprintf(outFilePtr,"%d\n",atoi(arg0));
			else{
				printf("error : numeric value that don't fit in 32bits\n");
				return(1);
			}
		}
		else{
			int define = 0;
			for(int i=0;i<MAXLINELENGTH;i++)
				if(!strcmp(labels[i],arg0)){
					define = 1;
					fprintf(outFilePtr, "%d\n",i);
					break;
				}
			if(define == 0){
				printf("error : undefined lables\n%s\n",arg0);
				return(1);
			}
		}
	}
	else{
		printf("error : unrecognized opcode\n%s\n",opcode);
		return(1);
	}
	address++;
	}

	/*this is how to rewind the file ptr so that you start reading from the beginning of the file */
	rewind(inFilePtr);
	return(0);
}/*
* Read and parse a line of the assembly-language file. Fields are returned
* in label, opcode, arg0, arg1, arg2 (these strings must have memory already
* allocated to them). *
* Return values:
* 	0 if reached end of file
* 	1 if all went well *
* exit(1) if line is too long.
*/
int readAndParse(FILE *inFilePtr, char *label, char *opcode, char *arg0, char *arg1, char *arg2)
{
	char line[MAXLINELENGTH];
	char *ptr = line;
	/* delete prior values */
	label[0] = opcode[0] = arg0[0] = arg1[0] = arg2[0] = '\0';
	/* read the line from the assembly-language file */
	if (fgets(line, MAXLINELENGTH, inFilePtr) == NULL) {
		/* reached end of file */
		return(0);
	}
	/* check for line too long (by looking for a \n) */
	if (strchr(line, '\n') == NULL) {
		/* line too long */
		printf("error: line too long\n");
		exit(1);
	}
	/* is there a label? */
	ptr = line;
	if (sscanf(ptr, "%[^\t\n\r ]", label)) {
		/* successfully read label; advance pointer over the label */
	       ptr += strlen(label);
	}
	/*
	 * Parse the rest of the line. Would be nice to have real regular
	 * expressions, but scanf will suffice.
	 */
	sscanf(ptr, "%*[\t\n\r ]%[^\t\n\r ]%*[\t\n\r ]%[^\t\n\r ]%*[\t\n\r ]%[^\t\n\r ]%*[\t\n\r ]%[^\t\n\r ]",opcode, arg0, arg1, arg2);
	return(1);
}
int isNumber(char *string)
{ 
	/* return 1 if string is a number */
	int i;
	return( (sscanf(string, "%d", &i)) == 1);
}
