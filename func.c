#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

///////////////////////////////


void print_data(Node* head){
    Node*ptr = head;

    int i = 1;
    
    while(ptr){
        printf("%d%s",i,". ");
        printf("%s",ptr->brand);
        printf("\t%s",ptr->type);
        printf("\t%s",ptr->gender);
        printf("\t%s",ptr->size);
        printf("\t%s",ptr->stock);
        printf("\n");
        
        ptr=ptr->next;
        i++;
    }
}



////////////



void create_node(Node** head)
{
    (*head) = (Node*)malloc(sizeof(Node));
    (*head)->brand =(char*)malloc(30*sizeof(char));
    (*head)->type =(char*)malloc(30*sizeof(char));
    (*head)->gender =(char*)malloc(12*sizeof(char));
    (*head)->size =(char*)malloc(5*sizeof(char));
    (*head)->stock =(char*)malloc(15*sizeof(char)); 
    (*head)->next = NULL;

}



//////////////////////





void fill_node(Node* head, char* file_name){
    FILE* f = fopen(file_name,"r");

    char* brand = (char *)malloc(30*sizeof(char)); if (brand == NULL) {printf("error with memory allocation");}
    char* type = (char *)malloc(30*sizeof(char)); if (type == NULL) {printf("error with memory allocation");}
    char* gender = (char *)malloc(12*sizeof(char)); if (gender == NULL) {printf("error with memory allocation");}
    char* size = (char *)malloc(5*sizeof(char)); if (size == NULL) {printf("error with memory allocation");}
    char* stock = (char *)malloc(15*sizeof(char)); if (stock == NULL) {printf("error with memory allocation");}
    
    Node* ptr = head;
    
    while(fscanf(f,"%s %s %s %s %s",brand,type,gender,size,stock) == 5){
    strcpy(ptr->brand, brand);
    strcpy(ptr->type, type);
    strcpy(ptr->gender, gender);
    strcpy(ptr->size,size);
    strcpy(ptr->stock, stock);

    ptr = ptr->next;
    create_node(&ptr);
}
    
    free(brand);
    free(type);
    free(gender);
    free(size);
    free(stock);

    fclose(f);
}


////////////////



void write_data(Node* head, char*file_name){
    FILE* f = fopen(file_name,"w+");

    Node* ptr = head;
    while(ptr){
        fprintf(f,"%s %s %s %s %s",ptr->brand,ptr->type,ptr->gender,ptr->size,ptr->stock);
        ptr = ptr->next;
    }

    fclose(f);
}




//////////////////////





void add_element(Node* head)
{
    char* brand = (char *)malloc(30*sizeof(char)); if (brand == NULL) {printf("error with memory allocation");}
    char* type = (char *)malloc(30*sizeof(char)); if (type == NULL) {printf("error with memory allocation");}
    char* gender = (char *)malloc(12*sizeof(char)); if (gender == NULL) {printf("error with memory allocation");}
    char* size = (char *)malloc(5*sizeof(char)); if (size == NULL) {printf("error with memory allocation");}
    char* stock = (char *)malloc(15*sizeof(char)); if (stock == NULL) {printf("error with memory allocation");}

    printf("\nWhat kind of brand?: ");
    scanf("%s",brand);
    printf("\nWhat type of clothes?: ");
    scanf("%s",type);
    printf("\nFor what gender?: ");
    scanf("%s",gender);
    printf("\nWhat size?: ");
    scanf("%s",size);
    printf("\nIs it in stock?: ");
    scanf("%s",stock);

    Node* ptr = head;
    while(ptr){ptr = ptr->next;}
    
    create_node(&ptr);

    ptr->brand = brand;
    ptr->type = type;
    ptr->gender = gender;
    ptr->size = size;
    ptr->stock = stock;
    ptr->next = NULL;
    
    
    free(brand);
    free(type);
    free(gender);
    free(size);
    free(stock);

}




////////////////////////




void del_element(Node* head)
{
    int indx;
    printf("Which element would you like to delete? ");
    scanf("%d",&indx);
    
    
    Node* ptr = head;

    if(indx == 1)
    {
        head = ptr->next;
        free(ptr);
        return;
    }

    int i = 1;

    while(i < indx-1)
    {
        ptr = ptr->next; 
        i++;
    }

    Node* ptr2 = ptr->next;
    ptr->next = ptr2->next;     //ptr2 == элемент, который хочем удалить
    free(ptr2);
    
}



/////////////////




void change_element(Node* head)
{
    int indx;
    printf("Which element would you like to change ");
    scanf("%d",&indx);
    
    
    char* brand = (char *)malloc(30*sizeof(char)); if (brand == NULL) {printf("error with memory allocation");}
    char* type = (char *)malloc(30*sizeof(char)); if (type == NULL) {printf("error with memory allocation");}
    char* gender = (char *)malloc(12*sizeof(char)); if (gender == NULL) {printf("error with memory allocation");}
    char* size = (char *)malloc(5*sizeof(char)); if (size == NULL) {printf("error with memory allocation");}
    char* stock = (char *)malloc(15*sizeof(char)); if (stock == NULL) {printf("error with memory allocation");}

    printf("\nWhat kind of brand?: ");
    scanf("%s",brand);
    printf("\nWhat type of clothes?: ");
    scanf("%s",type);
    printf("\nFor what gender?: ");
    scanf("%s",gender);
    printf("\nWhat size?: ");
    scanf("%s",size);
    printf("\nIs it in stock?: ");
    scanf("%s",stock);

    Node* ptr = head;

    int i = 1;

    while(i < indx)
    {
        ptr = ptr->next; 
        i++;
    }

    ptr->brand = brand;
    ptr->type = type;
    ptr->gender = gender;
    ptr->size = size;
    ptr->stock = stock;
    
    free(brand);
    free(type);
    free(gender);
    free(size);
    free(stock);

}




//////////////////




void sort_node(Node* head)
{
     char* srtbrand = (char *)malloc(30*sizeof(char)); if (srtbrand == NULL) {printf("error with memory allocation");}
     char* srttype = (char *)malloc(30*sizeof(char)); if (srttype == NULL) {printf("error with memory allocation");}
     char* srtgender = (char *)malloc(12*sizeof(char)); if (srtgender == NULL) {printf("error with memory allocation");} 
     char* srtsize = (char *)malloc(5*sizeof(char)); if (srtsize == NULL) {printf("error with memory allocation");}
     char* srtstock = (char *)malloc(15*sizeof(char)); if (srtstock == NULL) {printf("error with memory allocation");}
        
     printf("How many filters you wanna use? (1 - 5) ");
        
        int sort_numb; 
        scanf("%d",&sort_numb);
        if(sort_numb == 5)
        {
            print_data(head);   //если пользователь выбрал сортировку по всем элементам, то просто вывод базы данных
            return;
        }

        if (sort_numb < 5 && sort_numb >= 1)
        {
            printf("What sort would you like to use:\ntype 1 to sort by Brand\ntype 2 to sort by Type\ntype 3 to sort by Gender\ntype 4 to sort by Size\ntype 5 to sort by Stock\n");
            for(int i = 0; i < sort_numb; i++){
                int sort_option;
                scanf("%d",&sort_option);
                
                if(sort_option == 1){
                    printf("\nType Brand you wanna see ");
                    scanf("%s",&srtbrand);
                }
                if(sort_option == 2){
                    printf("\nType what kind of clothes you wanna see ");
                    scanf("%s",&srttype);
                }
                if(sort_option == 3){
                    printf("\nType what gender you wanna see ");        //выбор элементов по которым будет производиться сортировка
                    scanf("%s",&srtgender);
                }
                if(sort_option == 4){
                    printf("\nType what size you wanna see ");
                    scanf("%s",&srtsize);
                }
                if(sort_option == 5){
                    printf("\nType (in_stock) if you wanna see it in stock and (not_in_stock) if not ");
                    scanf("%s",&srtstock);
                }
                
            }


        Node* ptr = head;
        while(ptr)
        {
            if (strcmp(srtbrand, ptr->brand) == 0 && strcmp(srttype,  ptr->type)  == 0 && strcmp(srtgender,ptr->gender)== 0 && strcmp(srtsize,  ptr->size)  == 0 && strcmp(srtstock, ptr->stock) == 0){
                    printf("\n%s %s %s %s %s",ptr->brand,ptr->type,ptr->gender,ptr->size,ptr->stock);
                }
                    //сравнение и вывод пользовательских данных с актуальными
            ptr = ptr->next;
        }

    }
}
