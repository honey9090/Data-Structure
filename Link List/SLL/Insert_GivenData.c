#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};
struct node *first;

void creates();
void insert_givendata();
void display();

int main()
{
    creates();
    insert_givendata();
    display();
    return 0;
}

void creates(){
    char ch; 
    struct node *ptr, *cpt;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value for first->info\n");
    scanf("%d", &ptr->info);
    ptr->link=NULL;
    first =ptr;
    do{
        cpt= (struct node *)malloc(sizeof(struct node));
        scanf("%d", &cpt->info);
        cpt->link=NULL;
        ptr->link= cpt;
        ptr = cpt;
        printf("Press y for new node and n for exit");
        scanf(" %c", &ch);
    } while(ch == 'y');
    ptr->link=NULL;
}

void insert_givendata(){
    struct node *ptr, *cpt;
    int data;
    ptr = (struct node *)malloc(sizeof(struct node));
    cpt = first;
    printf("Enter the value where you want to add new structure\n");
    scanf("%d", &data);
    printf("Enter the value for first->info of new structure\n");
    scanf("%d", &ptr->info);
    while (cpt->info!=data)
    {
        cpt = cpt->link;
    }
    ptr->link=cpt->link;
    cpt->link=ptr;
    printf("\n");
}

void display(){
    struct node *ptr;
    ptr = first;
    while (ptr!=NULL)
    {
        printf("%d  |  %u  |  %u\n", ptr->info, ptr->link, ptr);
        ptr= ptr->link;
    }
}