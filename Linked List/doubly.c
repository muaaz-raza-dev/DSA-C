#include <stdio.h>
#include <stdlib.h>


struct node{
    int value ;
    struct node *next;
    struct node *prev;
};

typedef struct node* Position;
typedef struct node Node;
typedef struct node* List;

List init_list(){
    Node *head = (Node*)malloc(sizeof(Node));
    head->value = 0;
    head->next = NULL;
    head->prev = NULL;
    return head;
}

int is_null(List head){
    if(!head->next)return 1;
    return 0;
}

Position find(List head,int value){
    if(is_null(head)){
        return NULL;
    }

    Position p = head->next;
    while (p && p->value != value){
        p = p->next;
    }
    return p;
    
}

int insert(List head ,Position p,int value){ // 0 for success
    if(!p){
        printf("Can't push to Invalid location\n");
        return 1;
    }
    Position new_node = (Position)malloc(sizeof(Node));
    if(!new_node){
        printf("Failed to access memory\n");
        return 1;
    }

    new_node->value = value;
    new_node->prev = p;
    new_node->next = p->next;
    p->next->prev = new_node;
    p->next = new_node;

    printf("Inserted\n");
    return 0;
}


int push(List head ,int value){ // 0 for success
    Position p = head;
    Position new_node = (Position)malloc(sizeof(Node));
    if(!new_node){
        printf("Failed to access memory\n");
        return 1;
    }

    new_node->value = value;
    new_node->prev = p;
    new_node->next = p->next;
    if(p->next) p->next->prev = new_node;
    p->next = new_node;

    return 0;
}

int delete(List head, Position p){
    if(!p) {
        printf("Invalid location\n");
        return 1;
    }

    p->prev->next = p->next;
    if(p->next){
        p->next->prev = p->prev; 
    }
    free(p);
    printf("Deleted\n");
    return 0;
}

int pop(List head){
    Position p = head;
    if(is_null(head)){
        printf("Already empty linked list\n");
        return 1;
    }
    while (p && p->next){
        p = p->next;
    }
    p->prev->next = NULL;
    free(p);
    return 0;
}

int free_list(List head){
    Position p = head->next;
    head->next = NULL;
    Position temp ;
    while (temp){
        temp=p->next;
        free(p);
        p = temp;
    }
    return 0;
}

void print_list(List head){
    Position p = head->next;
    printf("Linked list values : ");
    while(p){
        printf("%d ",p->value);
        p = p->next;
    }
    printf("\n");
}

int main(void) {
    List d_list = init_list();

    
    return 0;
}
