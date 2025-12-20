#include <stdio.h>
#include"func.h"
#include <string.h>

int main(){
    FILE* f = fopen("data.txt","a+");
    if (f == NULL){
        printf("Error! The file can't be opened");
        return 1;
    }
    Node *list;
    list->next = NULL;
    int option;
    printf("--------menu--------\n");
    printf("type 1 to check full list\ntype 2 to add an element\ntype 3 to delete an element\ntype 4 to change an element\ntype 5 to check the sorted the list\n");
    
    char brand[50]; char type[50]; char gender[10]; char size[10]; char stock[10]; //буфер для считывания строк из файла
    
    scanf("%d",&option);
    switch (option)
    {
        case 1:
        
        int i = 1;
        while(fscanf(f,"%s%s%s%s%s",brand,type,gender,size,stock) == 5){
          
          list->brand = brand;
          list->type = type;
          list->gender = gender;
          list->size = size;
          list->stock = stock;
          printf("%d%s",i,". ");
          print_data(list);
          i++;
        }
        break;
    case 2:
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
        fprintf(f,"\n");
        fprintf(f,"%s %s %s %s %s ",brand,type,gender,size,stock);
        break;
    case 3:
        FILE* tmp = fopen("temporary_file.txt","a");
        int del_line;
        if (tmp == NULL)
        {
            printf("Error! The file can't be opened");
            return 1;
        }

        printf("\nwhich element would you like to delete?: ");
        scanf("%d",&del_line);

        char buf[256];
        int line = 1;
        while(fgets(buf,sizeof(buf), f)){
            if (line != del_line)
            {
                fputs(buf,tmp);
            }
            line++;
        }

        fclose(f);
        fclose(tmp);

        remove("data.txt");
        rename("temporary_file.txt","data.txt");
        
        break;

    case 4:

        FILE* temp = fopen("temporary_file.txt","a");
        if (temp == NULL)
        {
            printf("Error! The file can't be opened");
            return 1;
        }
        
        printf("\nwhich element would you like to change?: ");
        int change_line;
        scanf("%d",&change_line);

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

        char buffer[256];
        int Line = 1;
        while(fgets(buffer,sizeof(buffer), f)){
            if (Line == change_line)
            {
                fprintf(temp,"%s %s %s %s %s ",brand,type,gender,size,stock);
                fprintf(temp,"\n");
            }            
            else{
                fputs(buffer,temp);
            }
            Line++;
        }

        fclose(f);
        fclose(temp);

        remove("data.txt");
        rename("temporary_file.txt","data.txt");

        break;
    case 5:
        char* srtbrand = NULL;
        char* srttype = NULL;
        char* srtgender = NULL;
        char* srtsize = NULL;
        char* srtstock = NULL;
        printf("How many filters you wanna use? (1 - 5) ");
        
        int sort_numb; 
        scanf("%d",&sort_numb);
        if (sort_numb <=5 && sort_numb >= 1){
            printf("What sort would you like to use:\ntype 1 to sort by Brand\ntype 2 to sort by Type\ntype 3 to sort by Gender\ntype 4 to sort by Size\ntype 5 to sort by Stock\n");
            for(int i = 0; i < sort_numb; i++){
                int sort_option;
                scanf("%d",&sort_option);
                
                if(sort_option == 1){
                    printf("\nType Brand you wanna see ");
                    scanf("%ms",&srtbrand);
                }
                if(sort_option == 2){
                    printf("\nType what kind of clothes you wanna see ");
                    scanf("%ms",&srttype);
                }
                if(sort_option == 3){
                    printf("\nType what gender you wanna see ");
                    scanf("%ms",&srtgender);
                }
                if(sort_option == 4){
                    printf("\nType what size you wanna see ");
                    scanf("%ms",&srtsize);
                }
                if(sort_option == 5){
                    printf("\nType (in_stock) if you wanna see it in stock and (not_in_stock) if not ");
                    scanf("%ms",&srtstock);
                }
                
            }
            
            while(fscanf(f,"%s%s%s%s%s",brand,type,gender,size,stock) == 5){

                if(srtbrand == NULL){list->brand = brand;} else {list->brand = srtbrand;}
                if(srttype == NULL){list->type = type;} else {list->type = srttype;}
                if(srtgender == NULL){list->gender = gender;} else {list->gender = srtgender;}
                if(srtsize == NULL){list->size = size;} else {list->size = srtsize;}
                if(srtstock == NULL){list->stock = stock;} else {list->stock = srtstock;}

                if (strcmp(brand, list->brand) == 0 && strcmp(type,  list->type)  == 0 && strcmp(gender,list->gender)== 0 && strcmp(size,  list->size)  == 0 && strcmp(stock, list->stock) == 0){
                    printf("\n%s %s %s %s %s",brand,type,gender,size,stock);
                }
            }
        free(srtbrand);
        free(srttype);
        free(srtgender);
        free(srtsize);
        free(srtstock);

        }
        else{printf("\nWrong amount of elements to sort"); return 1;}
        break;
    default:
        break;
    }  
    

}
