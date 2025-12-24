#include <stdio.h>
#include"func.h"
#include <string.h>

int main(){
    char* file_name = "data.txt";

    Node *list;
    create_node(&list);
    fill_node(list,file_name); // считываем базу данных

    int option;
    printf("\n--------menu--------\n");
    printf("type 1 to check full list\ntype 2 to add an element\ntype 3 to delete an element\ntype 4 to change an element\ntype 5 to check the sorted the list\n");
    
    scanf("%d",&option);
    switch (option)
    {
        case 1:

        print_data(list);
        break;

    case 2:

        add_element(list);
        write_data(list,file_name);
        break;

    case 3:

        del_element(list);
        write_data(list,file_name);
        break;

    case 4:

        change_element(list);
        write_data(list,file_name);

        break;

   case 5:

        sort_node(list);    //вывод в консоль реализован внутри

        break;
    default:
        break;
    }  
    

}
