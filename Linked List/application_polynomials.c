
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "applications.h"


int Addition(List head_p1,List head_p2,List result_p){
    Position p1 = head_p1->next;
    Position p2 = head_p2->next;

    while (p1 || p2){
        int exp =0,coef = 0;
        if(p1->exponent == p2->exponent){
            exp = p1->exponent;
            coef = p1->coeffecient + p2->coeffecient;
            p1 = p1->next;
            p2 = p2->next;

        }
        else if(p1->exponent > p2->exponent){
            exp = p1->exponent;
            coef = p1->coeffecient;
            p1 = p1->next;
        }
        else {
            exp = p2->exponent;
            coef = p2->coeffecient;
            p2 = p2->next;
        }
        
        if(push_back_list(result_p,exp,coef)){
            printf("Operation Aborted!\n");
            break;
            return 1;
        }
        
    }
    
return 0;
}


int main(void) {
    
    List poly1  = init_list();
    List poly2  = init_list();

    List result  = init_list();

    push_front_list(poly1,0,4);
    push_front_list(poly1,1,8);
    push_front_list(poly1,2,1);
    traverse_list(poly1);

    push_front_list(poly2,0,5);
    push_front_list(poly2,1,16);
    push_front_list(poly2,2,4);
    traverse_list(poly2);

    Addition(poly1,poly2,result);

    traverse_list(result);

    
    return 0;
}
