#include<stdio.h>
#include<stdlib.h>

int count = 0;

struct node{

    int data;
    struct node *link;
};

struct node *start = NULL, *temp, *loc; //loc for getting location of element in insert operations

void display(){

    if(start == NULL){
 
        printf("\nLinked list is empty!\n");
    }
    else{

        printf("\nThe linked list now is:\n");
 
        temp = start;
 
        if(temp -> link == NULL){
 
        printf("%d ", temp -> data);
    }
    else{
 
        do{

            printf("%d -> ", temp -> data);
            temp = temp -> link;

            if(temp -> link == NULL){
 
                printf("%d", temp -> data);
            }
        }while(temp -> link != NULL);
    }
 }
}

void reverse(){

    temp = start;
    struct node *next = NULL, *prev = NULL;

    while(temp != NULL){

        next = temp -> link;
        temp -> link = prev;
        prev = temp;
        temp = next;
    }

    start = prev;

    display();
}

void delete_beg(){

    if(start == NULL)
    printf("\nNothing to delete! Linked list is empty!\n");
    else{

        temp = start;
        start = start -> link;

        printf("\n%d is deleted!\n", temp -> data);

        free(temp);

        display();
    }
}

void delete_pos(){

    if(start == NULL)
    printf("\nNothing to delete! Linked list is empty!\n");
    else{

        printf("Enter the position of element to delete(starting from 1):");
        int pos;
        scanf("%d", &pos);

        if(pos == 1)
        delete_beg();
        else if(pos > count)
        printf("\nPosition %d doesn't exist!\n", pos);
        else{
            
            temp = start;
            loc = temp -> link;

            for(int i = 1; i < (pos - 1); i++){

                temp = temp -> link;
                loc = loc -> link;
            }   

            printf("\n%d is deleted!\n", loc -> data);
            temp -> link = loc -> link;
            free(loc);

            display();
        }
    }
}   

void delete_end(){

    if(start == NULL)
    printf("\nNothing to delete! Linked list is empty!\n");
    else if(start -> link == NULL)
    delete_beg();
    else{

        temp = start;
        loc = temp -> link;

        while(loc -> link != NULL){

        temp = temp -> link;
        loc = loc -> link;
    }
    temp -> link = NULL;

    printf("%d is deleted!", loc -> data);
    free(loc);
    display();
 }
}

void insert_beg(){

    int el, pos;
 
    printf("\nEnter the element to insert:");
    scanf("%d", &el);

    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));

 
    p -> data = el;
 
    if(start == NULL)
    p -> link = NULL;
    else
    p -> link = start;
 
    start = p;

    display();
}

void insert_at_pos(){

    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
 
    printf("Enter the position to enter:");
    int ele, pos;
    scanf("%d", &pos);

    if(pos == 1)
    insert_beg();
    else if(start == NULL)
    printf("\nThe linked list not initialized! Please initialize it first by inserting at least one element!");
    else if(pos > count)
    printf("\nPosition %d doesn't exist!\n", pos);
    else{

        printf("Enter the element to be inserted:");
        scanf("%d", &ele);

        p -> data = ele;

        temp = start;

        for(int i = 1; i < (pos - 1); i++){

            temp = temp -> link;
        }
        p -> link = temp -> link;
        temp -> link = p;
        display();
    }
}

void insert_end(){

    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));

    printf("Enter the element to be inserted:");
    int item;
    scanf("%d", &item);

    p -> data = item;
    if(start == NULL){

        p -> link = NULL;
        start = p;
    }
    else{

        temp = start;
        while(temp -> link != NULL){

        temp = temp -> link;
    }
    temp -> link = p;
    p -> link = p;
    p -> link = NULL;
 }

 display();
}

void main(){

    int ans = 0;
 
    while(1){

        printf("\n\nLinked List Operations:\n\n1.Insert beginning\n2.Insert at end\n3.Insert in the middle\n4.Delete beginning\n5.Delete end\n6.Delete in the middle\n7.Display\n8.Reverse\n9.Exit\n\nEnter your option:");
        scanf("%d", &ans);

        switch(ans){

            case 1 : ++count;
                     insert_beg();
                        break;
            case 2 : ++count;
                     insert_end();
                        break;
            case 3 : ++count;
                     insert_at_pos();
                        break;
            case 4 : --count;
                     delete_beg();
                        break;
            case 5 : --count;
                     delete_end();
                        break;
            case 6 : --count;
                     delete_pos();
                        break;
            case 7 : display();
                        break;
            case 8 : reverse();
                        break;
            case 9 : exit(0);
                        break;
            default : printf("\n!Wrong option!\n");
        }
    }
}