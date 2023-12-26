#include <stdlib.h>
#include <stdio.h>
#include "node.h"
#include "book.h"

struct node* node_initialize(const void* const data)
{
    struct node* const new_node = (struct node*)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        perror("Memory allocation failed");
        exit(-1);
    }

    new_node->data = (void*)data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void node_print(const struct node* const node)
{
    if (node == NULL)
    {
        printf("Node is null.");
        return;
    }

    book_print(node->data);
}