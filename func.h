#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    struct Node* head;
    char *brand;
    char *type;
    char *gender;
    char *size;
    char *stock;

    struct Node* next;
} Node;


void print_data(Node* head);

void create_node(Node** head);

void fill_node(Node* head, char* file_name);

void write_data(Node* head, char*file_name);

void add_element(Node* head);

void del_element(Node* head);

void change_element(Node* head);

void sort_node(Node* head);
