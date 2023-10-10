#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "linked_list.h"

#define DEBUG

struct linked_list* initialize_linked_list()
{
	struct linked_list* const linked_list = (struct linked_list*)malloc(sizeof(struct linked_list));

	if (linked_list == NULL)
	{
		perror("Memory allocation failed");
		return NULL;
	}

	linked_list->head = NULL;
	linked_list->tail = NULL;
	linked_list->count = 0;
	return linked_list;
}

void print_linked_list(const struct linked_list* const linked_list)
{

#ifdef DEBUG
	system("cls");
#endif // !DEBUG

	if (linked_list == NULL)
	{
		printf("linked_list is null.");
		return;
	}

	const struct node* current = linked_list->head;

	while (current != NULL)
	{
		print_node(current);
		printf("\n");
		current = current->next;
	}
}

struct node* add_first(struct linked_list* const linked_list, const void* const data)
{
	if (linked_list == NULL)
	{
		printf("linked_list is null.");
		return NULL;
	}

	if (data == NULL)
	{
		printf("data is null.");
		return NULL;
	}

	struct node* const new_node = create_node(data);

	if (linked_list->head == NULL)
	{
		linked_list->head = linked_list->tail = new_node;
	}
	else
	{
		new_node->next = linked_list->head;
		linked_list->head->prev = data;
		linked_list->head = new_node;
	}

	++linked_list->count;
	return new_node;
}

struct node* add_last(struct linked_list* const linked_list, const void* const data)
{
	if (linked_list == NULL)
	{
		printf("linked_list is null.");
		return NULL;
	}

	if (data == NULL)
	{
		printf("data is null.");
		return NULL;
	}

	struct node* const new_node = create_node(data);

	if (linked_list->head == NULL)
	{
		linked_list->head = linked_list->tail = new_node;
	}
	else
	{
		linked_list->tail->next = new_node;
		new_node->prev = linked_list->tail;
		linked_list->tail = new_node;
	}

	++linked_list->count;
	return new_node;
}

struct node* remove_last(struct linked_list* const linked_list)
{
	if (linked_list == NULL)
	{
		printf("linked_list is null.");
		return NULL;
	}

	const struct node* removed_node;

	if (linked_list->count == 1)
	{
		removed_node = linked_list->tail;
		linked_list->head = linked_list->tail = NULL;
	}
	else
	{
		removed_node = linked_list->tail;
		linked_list->tail = linked_list->tail->prev;
		linked_list->tail->next = NULL;
	}

	--linked_list->count;
	return removed_node;
}

struct node* remove_first(struct linked_list* const linked_list)
{
	if (linked_list == NULL)
	{
		printf("linked_list is null.");
		return NULL;
	}

	const struct node* removed_node;

	if (linked_list->count == 1)
	{
		removed_node = linked_list->head;
		linked_list->head = linked_list->tail = NULL;
	}
	else
	{
		removed_node = linked_list->head;
		linked_list->head = linked_list->head->next;
		linked_list->head->prev = NULL;
	}

	--linked_list->count;
	return removed_node;
}

void remove_node(struct linked_list* const linked_list, const struct node* const node)
{
	if (linked_list == NULL)
	{
		printf("linked_list is null.");
		return;
	}

	if (node == NULL)
	{
		printf("linked_list is null.");
		return;
	}

	const struct node* removed_node = NULL;

	if (linked_list->count == 1)
	{
		removed_node = linked_list->head;
		linked_list->head = linked_list->tail = NULL;
	}
	else if (node == linked_list->head)
	{
		removed_node = linked_list->head;
		linked_list->head = linked_list->head->next;
		linked_list->head->prev = NULL;
	}
	else if (node == linked_list->tail)
	{
		removed_node = linked_list->tail;
		linked_list->tail = linked_list->tail->prev;
		linked_list->tail->next = NULL;
	}
	else
	{
		if (node->next == NULL || node->prev == NULL)
		{
			printf("Selected node is not from specified linked_list.");
			return;
		}

		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	
	free(removed_node->data);
	free(removed_node);
	--linked_list->count;
}

struct node* add_after(struct linked_list* const linked_list, struct node* const node, const void* const data)
{
	if (linked_list == NULL)
	{
		printf("linked_list is null.");
		return NULL;
	}

	if (node == NULL)
	{
		printf("node is null.");
		return NULL;
	}

	if (data == NULL)
	{
		printf("data is null.");
		return NULL;
	}

	if (node->next == NULL && node->prev == NULL)
	{
		printf("Selected node is not from specified linked_list.");
		return NULL;
	}

	struct node* const new_node = create_node(data);

	if (node == linked_list->tail)
	{
		linked_list->tail->next = new_node;
		new_node->prev = linked_list->tail;
		linked_list->tail = new_node;
	}
	else
	{
		node->next->prev = new_node;
		node->next = new_node;
		new_node->next = node->next;
		new_node->prev = node;
	}

	++linked_list->count;
	return new_node;
}

struct node* add_before(struct linked_list* const linked_list, struct node* const node, const void* const data)
{
	if (linked_list == NULL)
	{
		printf("linked_list is null.");
		return NULL;
	}

	if (node == NULL)
	{
		printf("node is null.");
		return NULL;
	}

	if (data == NULL)
	{
		printf("data is null.");
		return NULL;
	}

	if (node->next == NULL && node->prev == NULL)
	{
		printf("Selected node is not from specified linked_list.");
		return NULL;
	}

	struct node* const new_node = create_node(data);

	if (node == linked_list->head)
	{
		new_node->next = linked_list->head;
		linked_list->head->prev = data;
		linked_list->head = new_node;
	}
	else
	{
		node->prev->next = new_node;
		node->prev = new_node;
		new_node->prev = node->prev;
		new_node->next = node;
	}

	++linked_list->count;
	return new_node;
}

struct node* search(const struct linked_list* const linked_list, const void* const data)
{
	if (linked_list == NULL)
	{
		printf("linked_list is null.");
		return;
	}

	if (data == NULL)
	{
		printf("data is null.");
		return;
	}

	const struct node* current = linked_list->head;

	while (current != NULL)
	{
		if (current->data == data)
			return current;

		current = current->next;
	}

	return NULL;
}

void free_linked_list(struct linked_list* const linked_list)
{
	if (linked_list == NULL)
	{
		printf("linked_list is null.");
		return;
	}

	struct node* current = linked_list->head;
	struct node* next = NULL;

	while (current != NULL)
	{
		next = current->next;
		free(current->data);
		free(current);
		current = next;
	}

	linked_list->count = 0;
	linked_list->head = NULL;
	linked_list->tail = NULL;
}