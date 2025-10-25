#include <stdio.h>
#include <stdlib.h>

typedef struct node* node_ptr;

struct node{
    int element;
    node_ptr next;
};
typedef struct node node;
typedef struct node* List; // Header
typedef struct node* Position; // adress of a node in a linked list 
// ? We will use header in our linked list to validate push, and empty linkedlist

List init_list(){
List list_header = malloc(sizeof(node));
if(list_header == NULL){
        printf("Memory allocation failed ! \n");
        exit(1);
}
list_header->next = NULL;
return list_header;
}

int push_front_list(List head,int val){
    if(head ==NULL) {
    printf("Invalid Header address");
    return 1;
}
    Position p = head->next;

    Position new_block = malloc(sizeof(node));
    if(new_block == NULL){
        printf("Memory allocation failed ! \n");
        return 1;
    }
    new_block->element = val;
    if(p == NULL){
        new_block->next = NULL;
        head->next = new_block;   
    }
    else {
        new_block->next = p;
        head->next = new_block;   
    }
    return 0;
}

void traverse_list(List head){
    Position p = head->next;
    printf("Linked List:\n");
    while (p!=NULL){
    printf("%d\n",p->element);
    p = p->next;
    }
}

int check_is_null(List head){
    if(head->next == NULL) return 1;
    else return 0;
}


Position find_elem_list(List head,int val){
    Position p = head->next;
    while (p!=NULL && p->element != val){
        p = p->next;
    }
    return p;
}



Position find_prev_elem_list(List head,int val){
    Position p = head;
    if(check_is_null(head)){
        return NULL;
    }
    while (p->next!=NULL && p->next->element != val){
        p = p->next;
        if(p->next==NULL){
            p = NULL ;
        }
    }
    return p;
}

int delete_elem(List head,int val){
    Position p ;
    p =  find_prev_elem_list(head,val);
    if(p== NULL){
        printf("Failed to delete : Not found\n");
        return 1;
    }

    Position temp = p->next->next;
    free(p->next);
    p->next = temp;

    // Position temp = p->next;
    // p->next = temp->next;
    // free(temp);

    return 0;
}

int delete_list(List head){
    Position p = head->next;

    while (p!=NULL){
        Position temp = p->next;
        free(p);
        p = temp;
    }

    head->next = NULL;

    return 0;
}

int main(){
List header = init_list() ;
push_front_list(header,5);
push_front_list(header,4);
push_front_list(header,3);

delete_list(header);

traverse_list(header);

}