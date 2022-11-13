//Reference : https://www.w3resource.com/c-programming-exercises/linked_list/c-linked_list-exercise-1.php
#include <stdio.h>
#include <stdlib.h>

//Defining the node
struct node {
    int val;            //Value
    struct node *next;  // Address of the next element
};
struct node *head = NULL; //Delcaring head = NULL as a global variable

//Function for finding the middle
int tortHare(struct node *head) {
    
    //Declaring tort and hare
    struct node *tort;
    struct node *hare;
    
    //Hare has a headstart
    tort = head;
    hare = head->next;
    
    while (hare != NULL) {
        
        tort = tort->next;
        
        if (hare->next == NULL) {
            hare = NULL;
        }
        
        //Hare is faster
        else {
            hare = hare->next->next;
        }
        
    }
    
    return tort->val;
}


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
        printf("The linked list :-\n");
        
        while (node2 != NULL) {
            int x = node2->val;
            printf("%d\n", x);
            
            node2 = node2->next;
        }
    }
    
    return 0;
}

//Main function to ask for size of list, create it, and display it
int main () {
    
    int n;
    printf("Enter number of elements in the linked list : ");
    scanf("%d", &n);
    
    for (int i=0; i<n; i++) {
        createLinkedList();
    }
    
    printList();
    
    int mid = tortHare(head);
    printf("The middle element is : %d\n", mid);
    
    return 0;
}
