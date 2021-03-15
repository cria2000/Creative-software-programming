#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

struct Item{
	struct Item *next;
	char Name[10];
	char Age[10];
	char Id[10];
	char **Subjects;
};
struct Item* create_item();
struct Item* find_end_of_list(struct Item* linked_list);
void insert_item(struct Item *linked_list, struct Item *Item);

#endif// __LINKED_LIST_H__
