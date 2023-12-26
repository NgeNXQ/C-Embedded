#ifndef NODE_H
#define NODE_H

struct node
{
    void* data;
    struct node* next;
    struct node* prev;
};

struct node* node_initialize(const void* const data);
void node_print(const struct node* const node);

#endif // NODE_H