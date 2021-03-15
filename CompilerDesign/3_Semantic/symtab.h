/****************************************************/
/* File: symtab.h                                   */
/* Symbol table interface for the TINY compiler     */
/* (allows only one symbol table)                   */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/
#include "globals.h"
#ifndef _SYMTAB_H_
#define _SYMTAB_H_
#define SIZE 211
/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */

/* the list of line numbers of the source 
 * code in which a variable is referenced
 */

typedef struct LineListRec
   { int lineno;
     struct LineListRec * next;
   } * LineList;

/* The record in the bucket lists for
 * each variable, including name, 
 * assigned memory location, and
 * the list of line numbers in which
 * it appears in the source code
 */
typedef struct BucketListRec
	{
		char * name;
		char* type;
		LineList lines;
		int memloc ; /* memory location for variable */
		struct BucketListRec * next;
	} * BucketList ;

/* The record for each scope, 
 * including name, its bucket,
 * and parent scope.
 */
typedef struct ScopeListRec
	{
		char * name;
		BucketList bucket[SIZE];
		struct ScopeListRec * parent;
		struct ScopeListRec * child;
	} ScopeList ;

void st_insert( char * scope, char * name, char* type, int lineno, int loc );

/* Function st_lookup returns the memory 
 * location of a variable or -1 if not found
 */
BucketList st_lookup ( char * scope, char * name );

BucketList st_lookup_excluding_parent ( char * scope, char * name );

ScopeList* makeScope(char * name);

void makeScopeList(char * name);

void gotoParent();
//static BucketList hashTable[SIZE];

/* Procedure printSymTab prints a formatted 
 * listing of the symbol table contents 
 * to the listing file
 */
void printSymTab(FILE * listing);

#endif
