#ifndef NODE_H
#define NODE_H

struct node
{
    void* data;
    struct node* next;
    struct node* prev;
};

struct node* create_node(const void* const data);
void print_node(const struct node* const node);

#endif // NODE_H