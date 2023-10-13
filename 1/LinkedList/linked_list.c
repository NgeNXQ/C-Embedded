#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "linked_list.h"

struct linked_list* linked_list_initialize()
{
	struct linked_list* const linked_list = (struct linked_list*)malloc(sizeof(struct linked_list));

	if (linked_list == NULL)
	{
		perror("Memory allocation failed");
		exit(-1);
	}

	linked_list->head = NULL;
	linked_list->tail = NULL;
	linked_list->count = 0;
	return linked_list;
}

void linked_list_print(const struct linked_list* const linked_list)
{
	if (linked_list == NULL)
	{
		printf("linked_list is null.");
		return;
	}

	const struct node* current = linked_list->head;

	while (current != NULL)
	{
		node_print(current);
		printf("\n");
		current = current->next;
	}
}

struct node* linked_list_add_first(struct linked_list* const linked_list, const void* const data)
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

	struct node* const new_node = node_initialize(data);

	if (linked_list->head == NULL)
	{
		linked_list->head = linked_list->tail = new_node;
	}
	else
	{
		new_node->next = linked_list->head;
		linked_list->head->prev = new_node;
		linked_list->head = new_node;
	}

	++linked_list->count;
	return new_node;
}

struct node* linked_list_add_last(struct linked_list* const linked_list, const void* const data)
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

	struct node* const new_node = node_initialize(data);

	if (linked_list->tail == NULL)
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

int linked_list_remove_last(struct linked_list* const linked_list)
{
	if (linked_list == NULL)
	{
		printf("linked_list is null.");
		return -1;
	}

	if (linked_list->count == 0)
	{
		printf("linked_list is empty.");
		return -1;
	}

	const struct node* removed_node = NULL;

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

	free(removed_node->data);
	free(removed_node);
	--linked_list->count;
	return 0;
}

int linked_list_remove_first(struct linked_list* const linked_list)
{
	if (linked_list == NULL)
	{
		printf("linked_list is null.");
		return -1;
	}

	if (linked_list->count == 0)
	{
		printf("linked_list is empty.");
		return -1;
	}

	const struct node* removed_node = NULL;

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

	free(removed_node->data);
	free(removed_node);
	--linked_list->count;
	return 0;
}

int linked_list_remove_node(struct linked_list* const linked_list, const struct node* const node)
{
	if (linked_list == NULL)
	{
		printf("linked_list is null.");
		return -1;
	}

	if (node == NULL)
	{
		printf("node is null.");
		return -1;
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
		if (node->next == NULL && node->prev == NULL)
		{
			printf("Selected node is not from specified linked_list.");
			return -1;
		}

		removed_node = node;
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	
	free(removed_node->data);
	free(removed_node);
	--linked_list->count;
	return 0;
}

struct node* linked_list_add_after(struct linked_list* const linked_list, struct node* const node, const void* const data)
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

	struct node* const new_node = node_initialize(data);

	if (node == linked_list->tail)
	{
		linked_list->tail->next = new_node;
		new_node->prev = linked_list->tail;
		linked_list->tail = new_node;
	}
	else
	{
		new_node->next = node->next;
		new_node->prev = node;
		node->next->prev = new_node;
		node->next = new_node;
	}

	++linked_list->count;
	return new_node;
}

struct node* linked_list_add_before(struct linked_list* const linked_list, struct node* const node, const void* const data)
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

	struct node* const new_node = node_initialize(data);

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

struct node* linked_list_search(const struct linked_list* const linked_list, const void* const data)
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

void linked_list_free(struct linked_list* const linked_list)
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