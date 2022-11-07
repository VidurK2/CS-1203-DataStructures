//Reference : https://www.w3resource.com/c-programming-exercises/linked_list/c-linked_list-exercise-1.php

#include <stdio.h>
#include <stdlib.h>

struct node //Defining the node
{
    int number; //Value
    struct node *next; //Address of the next element
}*startnode;

void listPrint() //function to print list
{
    struct node *tmp;
    if(startnode == NULL)
    {
        printf("The List is empty!"); //If the first node is empty, then the list is empty
    }
    else
    {
        tmp = startnode;
        while(tmp != NULL)
        {
            printf(" Node Value : %d\n", tmp->number); //prints out all values of the list
            tmp = tmp->next; //Goes to next
        }
    }
}

void linkedList(int n) //function to make linked list
{
    struct node *node2, *tmp;
    int number, i;
    startnode = (struct node *)malloc(sizeof(struct node)); // allocates size of the node

    if(startnode == NULL) //startnode cant be 0
    {
        printf("Error! First node is NULL!");
    }
    else
    {


        printf("Enter value for node 1 : ");
        scanf("%d", &number); //asks for first value
        startnode->number = number;
        startnode->next = NULL;
        tmp = startnode;

        for(i=2; i<=n; i++) //loops and asks for input for the list
        {
            node2 = (struct node *)malloc(sizeof(struct node));
            if(node2 == NULL)
            {
                printf("Memory is NULL!");
                break;
            }
            else
            {
                printf("Enter value for node %d : ", i);
                scanf(" %d", &number);
 
                node2->number = number;
                node2->next = NULL;
 
                tmp->next = node2;
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
