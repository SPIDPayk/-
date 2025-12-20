#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    char *brand;
    char *type;
    char *gender;
    char *size;
    char *stock;

    struct Node* next;
} Node;


void print_data(Node* head);

