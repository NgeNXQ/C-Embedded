#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "book.h"
#include "node.h"

struct linked_list
{
	int count;
	struct node* head;
	struct node* tail;
};

struct linked_list* linked_list_initialize();
void linked_list_print(const struct linked_list* const linked_list);
struct node* linked_list_add_last(struct linked_list* const linked_list, const void* const data);
struct node* linked_list_add_first(struct linked_list* const linked_list, const void* const data);
int linked_list_remove_last(struct linked_list* const linked_list);
int linked_list_remove_first(struct linked_list* const linked_list);
int linked_list_remove_node(struct linked_list* const linked_list, const struct node* const node);
struct node* linked_list_add_after(struct linked_list* const linked_list, const struct node* const node, const void* const data);
struct node* linked_list_add_before(struct linked_list* const linked_list, struct node* const node, const void* const data);
struct node* linked_list_search(const struct linked_list* const linked_list, const void* const data);
void linked_list_free(struct linked_list* const linked_list);

#endif // LINKED_LIST_H