#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};
struct node *first;

void creates();

int main()
{
    creates();
    return 0;
}

void creates(){
    char ch; 
    struct node *ptr, *cpt;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value for first->info\n");
    scanf("%d", &ptr->info);
    ptr->link=ptr;
    first =ptr;
    do{
        cpt= (struct node *)malloc(sizeof(struct node));
        scanf("%d", &cpt->info);
        ptr->link=cpt;
        ptr = cpt;
        printf("Press y for new node and n for exit");
        scanf(" %c", &ch);
    } while(ch == 'y');
    ptr->link=first;
}