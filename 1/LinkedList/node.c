#include <stdlib.h>
#include <stdio.h>
#include "node.h"
#include "book.h"

struct node* create_node(const void* const data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        perror("Memory allocation failed");
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void print_node(const struct node* const node)
{
    if (node == NULL)
    {
        printf("Node is null.");
        return;
    }

    print_book(node->data);
}