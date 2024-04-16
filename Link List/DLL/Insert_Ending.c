#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *lpt;
    int info;
    struct node *rpt;
};
struct node *first;

void creates();
void insert_ending();
void display();

int main()
{
    creates();
    insert_ending();
    display();
    return 0;
}

void creates(){
    char ch; 
    struct node *ptr, *cpt;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value for first->info\n");
    scanf("%d", &ptr->info);
    ptr->lpt=NULL;
    ptr->rpt=NULL;
    first =ptr;
    do{
        cpt= (struct node *)malloc(sizeof(struct node));
        scanf("%d", &cpt->info);
        cpt->rpt=NULL;
        cpt->lpt=ptr;
        ptr->rpt=cpt;
        ptr = cpt;
        printf("Press y for new node and n for exit");
        scanf(" %c", &ch);
    } while(ch == 'y');
    ptr->rpt=NULL;
    printf("\n");
}

void insert_ending(){
    struct node *ptr, *cpt;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value for first->info of new structure\n");
    scanf("%d", &ptr->info);
    cpt = first;
    while (cpt->rpt!=NULL)
    {
        cpt= cpt->rpt;
    }
    cpt->rpt=ptr;
    ptr->rpt=NULL;
    ptr->lpt=cpt;
    printf("\n");
}

void display(){
    struct node *ptr;
    ptr = first;
    while (ptr!=NULL)
    {
        printf("%u  |  %d  |  %u  |  %u\n", ptr->lpt, ptr->info, ptr->rpt, ptr);
        ptr= ptr->rpt;
    }
}