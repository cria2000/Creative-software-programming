/* LC-2K Instruction-level simulator */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define NUMMEMORY 65536 /* maximum number of words in memory */
#define NUMREGS 8 /* number of machine registers */
#define MAXLINELENGTH 1000
typedef struct stateStruct {
	int pc;
	int mem[NUMMEMORY];
	int reg[NUMREGS];
	int numMemory;
} stateType;
void printState(stateType *);
int convertNum(int);
int main(int argc, char *argv[])
{ 
	char line[MAXLINELENGTH];
	stateType state;
	FILE *filePtr;
	int numberOfInst = 0;
	int halt = 0;
	if (argc != 2) {
		printf("error: usage: %s <machine-code file>\n", argv[0]);
		exit(1);
	}
	filePtr = fopen(argv[1], "r");
	if (filePtr == NULL) {
		printf("error: can't open file %s", argv[1]);
		perror("fopen");
		exit(1);
	}
	for(int i=0;i<NUMREGS;i++){
		state.reg[i] = 0;
	}
	state.pc = 0;
	/* read in the entire machine-code file into memory */
	for (state.numMemory = 0; fgets(line, MAXLINELENGTH, filePtr) != NULL;state.numMemory++) {
		if (sscanf(line, "%d", state.mem+state.numMemory) != 1) {
			printf("error in reading address %d\n", state.numMemory);
		 	exit(1);
		}
		printf("memory[%d]=%d\n", state.numMemory, state.mem[state.numMemory]);
	}
	while(halt != 1){
		printState(&state);
		/* the case that state is add */
		if((state.mem[state.pc] >> 22 & 0x7) == 0){
			state.reg[state.mem[state.pc] & 0x7] = state.reg[state.mem[state.pc]>>19 & 0x7] + state.reg[state.mem[state.pc] >>16 & 0x7];
			++state.pc;
		}
		/* the case that state is nor */
		else if((state.mem[state.pc] >> 22 & 0x7) == 1){
			state.reg[state.mem[state.pc] & 0x7] = ~((state.reg[state.mem[state.pc] >> 19 & 0x7]) | (state.reg[state.mem[state.pc] >> 16 & 0x7]));
			++state.pc;
		}
		/* the case that state is lw */
		else if((state.mem[state.pc] >> 22 & 0x7) == 2){ 
			state.reg[state.mem[state.pc] >> 16 & 0x7] = state.mem[(convertNum(state.mem[state.pc] & 0xffff)) + (state.reg[state.mem[state.pc] >> 19 & 0x7])];
			++state.pc;
		}
		/* the case that state is sw */
		else if((state.mem[state.pc] >> 22 & 0x7) == 3){
				state.mem[(state.mem[state.pc] >> 19 & 0x7) + (convertNum(state.mem[state.pc] & 0xffff))] = state.reg[state.mem[state.pc] >> 16 & 0x7];
			++state.pc;
		}
		/* the case that state is beq */
		else if((state.mem[state.pc] >> 22 & 0x7) == 4){
			if((state.reg[state.mem[state.pc] >> 19 & 0x7]) == (state.reg[state.mem[state.pc] >> 16 & 0x7])){
				state.pc = state.pc + (convertNum(state.mem[state.pc] & 0xffff)) + 1;
			}
			else
				++state.pc;
		}
		/* the case that state is jalr */
		else if((state.mem[state.pc] >> 22 & 0x7) == 5){
			state.reg[state.mem[state.pc] >> 16 & 0x7] = state.pc+1;
			if(state.reg[state.mem[state.pc] >> 19 & 0x7] == state.reg[state.mem[state.pc] >> 16 & 0x7])
				++state.pc;
			else { 
				state.pc = state.reg[state.mem[state.pc] >> 19 & 0x7];
			}
		}
		/* the case that state is halt */
		else if((state.mem[state.pc] >> 22 & 0x7) == 6){
			++state.pc;
			halt = 1; 
			printf("machine halted\ntotal of %d instructions executed\nfinal state of machine : ",++numberOfInst);

		}
		/* the case that state is noop */
		else if((state.mem[state.pc] >> 22 & 0x7) == 7){
			/* do nothing */
			++state.pc;
		}
		++numberOfInst;
	}
	printState(&state);
	return(0);
}
void printState(stateType *statePtr)
{ 
	int i;
	printf("\n@@@\nstate:\n");
	printf("\tpc %d\n", statePtr->pc);
	printf("\tmemory:\n");
	for (i=0; i<statePtr->numMemory; i++) {
		printf("\t\tmem[ %d ] %d\n", i, statePtr->mem[i]);
	}
	printf("\tregisters:\n");
	for (i=0; i<NUMREGS; i++) {
		printf("\t\treg[ %d ] %d\n", i, statePtr->reg[i]);
	}
	printf("end state\n");
}
int convertNum(int num){
	/* convert a 16-bit number into a 32-bit Linux integer */
	if(num & (1<<15)){
		num -=(1 << 16);
	}
	return(num);
}
