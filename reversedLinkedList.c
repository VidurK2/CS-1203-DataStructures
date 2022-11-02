#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int val;
  struct Node *next;
}
*start = NULL;

void makeLinkedList(int A[], int n)
{
    int i;
    struct Node *tmp, *last;
    start = (struct Node *) malloc (sizeof (struct Node));
    start->val = A[0];
    start->next = NULL;
    last = start;
    for (i = 1; i < n; i++)
    {
        tmp = (struct Node *) malloc (sizeof (struct Node));
        tmp->val = A[i];
        tmp->next = NULL;
        last->next = tmp;
        last = tmp;
    }
}
int Count(struct Node * p) {
    int l = 0;
    while (p) {
        l++;
        p = p -> next;
    }
    return l;
}
void printList(struct Node *p)
{
    while (p != NULL)
    {
        printf ("%d ", p->val);
        p = p->next;
    }
}
void reverseList(struct Node *p)
{
    int *A, i = 0;
    struct Node *q = p;
    A = (int *) malloc(sizeof(int) * Count(p));
    while (q != NULL)
    {
        A[i] = q->val;
        q = q->next;
        i++;
    }
    
    q = p;
    i--;
    while (q != NULL)
    {
        q->val = A[i];
        q = q->next;
        i--;
    }
}
int main()
{
    int num;
    printf("Enter number of elements : ");
    scanf("%d", &num);
    
    int Ar[num];
    
    for (int i = 0; i<num; i++) {
        printf("Enter an element : ");
        scanf("%d", &Ar[i]);
    }
    
    makeLinkedList(Ar, num);
    printf("Original Linked List : \n");
    printList(start);
    reverseList(start);
    printf("\nReversed Linked List : \n");
    printList(start);
    return 0;
}
