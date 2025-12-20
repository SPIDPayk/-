#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void print_data(Node* head){
    Node*ptr = head;

    while(ptr){
        printf("%s",ptr->brand);
        printf("\t%s",ptr->type);
        printf("\t%s",ptr->gender);
        printf("\t%s",ptr->size);
        printf("\t%s",ptr->stock);
        printf("\n");
        ptr=ptr->next;
    }
}
