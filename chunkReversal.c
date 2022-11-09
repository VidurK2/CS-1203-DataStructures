
#include <stdio.h>
#include <stdlib.h>

//Defining the node
struct node {
    int val;            //Value
    struct node *next;  // Address of the next element
};
struct node *head = NULL; //Delcaring head = NULL as a global variable


//Function to create Linked List
int createLinkedList () {
    struct node *tmp, *node2; //Making two nodes
    tmp=(struct node *)malloc(sizeof(struct node)); //Allocating memory for tmp
    
    printf("Enter value for linked list : ");
    scanf("%d", &tmp->val);
    tmp->next = NULL; //Setting next element's address to NULL
    
    //If head is null, it sets heaf's value as tmp
    if (head == NULL) {
        head = tmp;
    }
    
    //Otherwise, sets node2 as the head
    else {
        node2 = head;
        
        //As long as the next address isn't NULL, it goes through the linked list
        while (node2->next!=NULL) {
            node2 = node2->next;
        }
        node2->next = tmp;
    }
    
    return 0;
    
}

//Function to print list
int printList () {
    struct node *node2;
    
    //If the head is NULL, that means the list is empty
    if (head == NULL) {
        printf("The linked list has no elements!\n");
    }
    
    //Otherwise, traverse through the list to print out values
    else {
        node2 = head;
        printf("The Original linked list :-\n");
        
        while (node2 != NULL) {
            int x = node2->val;
            printf("%d\n", x);
            
            node2 = node2->next;
        }
    }
    
    return 0;
}

void reverse(struct node** head, int cnt)
{
    struct node* prev = NULL;   //Points to the previous element
    struct node* curr = *head;  //Points to the current element

    
    
    //While current doesn't reach end of the chunk size of the linked list, loop
    for (int i=0; i<cnt; i++)
    {
        //Next will be the next element of current
        struct node* next = curr->next;
        
        curr->next = prev;    //Set prev to new value
        
        //Moves prev and curr one step forward
        prev = curr;
        curr = next;
    }
    
    if (next != NULL) {
        head->next = reverse(next, cnt);
    }
    //The head is not the previous element
    *head = prev;
    
    printf("Reversed Linked List :-");
    printList();
}

//Main function to ask for size of list, create it, and display it
int main () {
    
    int n;
    printf("Enter number of elements in the linked list : ");
    scanf("%d", &n);
    
    for (int i; i<=n; i++) {
        createLinkedList();
    }
    
    printList();
    
    int cnt;
    printf("Enter chunk size : ");
    scanf("%d", &cnt);
    
    reverse(&head, cnt);
    
    return 0;
}
