#ifndef TYPES_H
#define TYPES_H

typedef struct node* node_ptr;

struct node{
    int coeffecient;
    int exponent;
    node_ptr next;
};
typedef struct node node;
typedef struct node* List; // Header
typedef struct node* Position; // adress of a node in a linked list 

int delete_list(List head);
int delete_elem(List head,int val);
Position find_prev_elem_list(List head,int exp);
int check_is_null(List head);
Position find_elem_list(List head,int exp);
void traverse_list(List head);
int push_front_list(List head,int exp,int coef);
int push_back_list(List head,int exp,int coef);
List init_list();

#endif 