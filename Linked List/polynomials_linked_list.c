#include <stdio.h>
#include <stdlib.h>
#include "applications.h"

List init_list(){
List list_header = malloc(sizeof(node));
if(list_header == NULL){
        printf("Memory allocation failed ! \n");
        exit(1);
}
list_header->next = NULL;
return list_header;
}

int push_front_list(List head,int exp,int coef){
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
    new_block->exponent = exp;
    new_block->coeffecient = coef;
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



int push_back_list(List head,int exp,int coef){
    if(head ==NULL) {
    printf("Invalid Header address");
    return 1;
}
    Position p = head;

    Position new_block = malloc(sizeof(node));
    if(new_block == NULL){
        printf("Memory allocation failed ! \n");
        return 1;
    }
    while (p&&p->next){
        p = p->next;
    }
    
    new_block->exponent = exp;
    new_block->coeffecient = coef;
    new_block->next = NULL;
    p->next = new_block;   
    
    return 0;
}


void traverse_list(List head){
    Position p = head->next;
    printf("Linked List:\n");
    while (p!=NULL){
    printf("%dx^%d\n",p->coeffecient,p->exponent);
    p = p->next;
    }
}

int check_is_null(List head){
    if(head->next == NULL) return 1;
    else return 0;
}


Position find_elem_list(List head,int exp){
    Position p = head->next;
    while (p!=NULL && p->exponent != exp){
        p = p->next;
    }
    return p;
}



Position find_prev_elem_list(List head,int exp){
    Position p = head;
    if(check_is_null(head)){
        return NULL;
    }
    while (p->next!=NULL && p->next->exponent != exp){
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

