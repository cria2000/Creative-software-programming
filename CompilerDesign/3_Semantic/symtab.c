/****************************************************/
/* File: symtab.c                                   */
/* Symbol table implementation for the TINY compiler*/
/* (allows only one symbol table)                   */
/* Symbol table is implemented as a chained         */
/* hash table                                       */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

/* SIZE is the size of the hash table */
#define SIZE 211

/* SHIFT is the power of two used as multiplier
   in hash function  */
#define SHIFT 4
static ScopeList* hashTable;
ScopeList *currentList;
int h = 0;
/* the hash function */
static int hash ( char * key )
{ int temp = 0;
  int i = 0;
  while (key[i] != '\0')
  { 
    temp = ((temp << SHIFT) + key[i]) % SIZE;
    ++i;
  }
  return temp;
}

ScopeList* makeScope(char * name) {
	ScopeList *table;
	table = (ScopeList *) malloc(sizeof(struct ScopeListRec));
	table -> name = name;
	table -> child = NULL; 	
	table -> parent = currentList;
	return table;
//	table -> bucket = (BucketList *)malloc((sizeof(struct BucketListRec)) * SIZE);
}

void makeScopeList(char * name){
	if(hashTable == NULL) {
		hashTable = (ScopeList*) malloc(sizeof(struct ScopeListRec));
		hashTable -> name = "global";
		hashTable -> parent = NULL;
		hashTable -> child = NULL;
		currentList = hashTable;
	}
	currentList->child = makeScope(name);
	currentList = currentList->child;
}
void gotoParent(){
	currentList = currentList->parent;
}
/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */
void st_insert( char * scope, char * name, char* type, int lineno, int loc )
{ //int h = hash(name);
    h++;
 // printf("%s %s %d ", scope, name, type);
  BucketList l =  hashTable->bucket[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    l = l->next;
  if (l == NULL) /* variable not yet in table */
  { l = (BucketList) malloc(sizeof(struct BucketListRec));    
    l->name = name;
    l->type = type;
    l->lines = (LineList) malloc(sizeof(struct LineListRec));
    l->lines->lineno = lineno;
    l->memloc = loc;
    l->lines->next = NULL;
    l->next = hashTable->bucket[h];
    hashTable->bucket[h] = l; }
  else /* found in table, so just add line number */
  { LineList t = l->lines;
    while (t->next != NULL) t = t->next;
    t->next = (LineList) malloc(sizeof(struct LineListRec));
    t->next->lineno = lineno;
    t->next->next = NULL;
  }
} /* st_insert */

/* Function st_lookup returns the memory 
 * location of a variable or -1 if not found
 */
BucketList st_lookup ( char * scope, char * name)
{
//	int h = hash(name);
	while(currentList != NULL){
		for(int i = 0; i<SIZE;i++){
			if(currentList->bucket[i] != NULL){
			BucketList l = currentList->bucket[i];
			while ((l != NULL) && (strcmp(name,l->name) != 0))
				l = l->next;
			if (l == NULL) currentList = currentList->parent;
			if (currentList != NULL) return l->memloc;
		}}
		return -1;
	}
}

BucketList st_look_up_excluding_parent ( char * scope, char * name) {
}

/* Procedure printSymTab prints a formatted 
 * listing of the symbol table contents 
 * to the listing file
 */
void printSymTab(FILE * listing)
{ 
  int i;
  fprintf(listing,"   scope     variable Name  Location   Line Numbers\n");
  fprintf(listing,"-----------  -------------  --------   ------------\n");
  for (i=0;i<SIZE;++i)
  { if (hashTable != NULL)
    { ScopeList* l = hashTable;
      BucketList m = l->bucket;
      while (m != NULL)
      { LineList t = m->lines;
	fprintf(listing, "%-17s", l->name);
        fprintf(listing,"%-14s ",m->name);
        fprintf(listing,"%-8d  ",m->memloc);
        while (t != NULL)
        { fprintf(listing,"%4d ",t->lineno);
          t = t->next;
        }
        fprintf(listing,"\n");
        l = l->child;
      }
    }
  }
} /* printSymTab */
