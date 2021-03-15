#include"linked_list.h"
#include<stdlib.h>


struct Item* create_item(){
	struct Item *ptr=(struct Item*)malloc(sizeof(struct Item));
	return ptr;
}

struct Item* find_end_of_list(struct Item* linked_list){
	while(linked_list->next!=NULL){
	linked_list=linked_list->next;}
	return linked_list;
}

void insert_item(struct Item *linked_list, struct Item *item){
	find_end_of_list(linked_list)->next=item;
	item->next=NULL;}

