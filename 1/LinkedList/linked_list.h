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

struct linked_list* initialize_linked_list();
void print_linked_list(const struct linked_list* const linked_list);
struct node* add_last(struct linked_list* const linked_list, const void* const data);
struct node* add_first(struct linked_list* const linked_list, const void* const data);
struct node* remove_last(struct linked_list* const linked_list);
struct node* remove_first(struct linked_list* const linked_list);
void remove_node(struct linked_list* const linked_list, const struct node* const node);
struct node* add_after(struct linked_list* const linked_list, const struct node* const node, const void* const data);
struct node* add_before(struct linked_list* const linked_list, struct node* const node, const void* const data);
struct node* search(const struct linked_list* const linked_list, const void* const data);
void free_linked_list(struct linked_list* const linked_list);

#endif // LINKED_LIST_H