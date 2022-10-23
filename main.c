#include <stdio.h>
#include <stdlib.h>

struct node
{
    int number;
    struct node *next;
}*startnode;

void listPrint()
{
    struct node *tmp;
    if(startnode == NULL)
    {
        printf("The List is empty!");
    }
    else
    {
        tmp = startnode;
        while(tmp != NULL)
        {
            printf(" Node Value : %d\n", tmp->number);
            tmp = tmp->next;
        }
    }
}

void linkedList(int n)
{
    struct node *fnNode, *tmp;
    int number, i;
    startnode = (struct node *)malloc(sizeof(struct node));

    if(startnode == NULL)
    {
        printf("Error! First node is NULL!");
    }
    else
    {


        printf("Enter value for node 1 : ");
        scanf("%d", &number);
        startnode->number = number;
        startnode->next = NULL;
        tmp = startnode;

        for(i=2; i<=n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL)
            {
                printf("Memory is NULL!");
                break;
            }
            else
            {
                printf("Enter value for node %d : ", i);
                scanf(" %d", &number);
 
                fnNode->number = number;
                fnNode->next = NULL;
 
                tmp->next = fnNode;
                tmp = tmp->next;
            }
        }
    }
}



void linkedList(int n); // function to create the list
void listPrint();         // function to display the list

int main()
{
    int n;
        
    printf("How many nodes do you want : ");
    scanf("%d", &n);
    linkedList(n);
    printf("\n Linked List :--- : \n");
    listPrint();
    return 0;
}
