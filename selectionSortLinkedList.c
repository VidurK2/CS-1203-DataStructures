#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node * next;
};
typedef struct node * NodeAddress;

NodeAddress makeLinked(int *A, int num) {
    NodeAddress head, tmp = NULL;

    if(num>0) {
        head = malloc( sizeof(struct node) );
        head->val  = A[0];
        head->next = NULL;
        tmp = head;
    }


    for(int i=1; i<num; i++) {
        tmp->next = malloc( sizeof(struct node) );
        tmp = tmp->next;
        tmp->val = A[i];
        tmp->next = NULL;
    }

    return head;
}

void selectionSort(int *A, int n) {
    int biggest;

    for(int i=n; i>1; i=i-1) {
        
        if(i<1) {
            biggest = -1;

        }

        biggest = 0;
        for(int j=1; j<i; j++) {
            if( A[j] > A[biggest] ) {
                biggest = j;
            }
        }
        
        int tmp = A[biggest];
        A[biggest] = A[i-1];
        A[i-1] = tmp;
    }
}

int main() {
    int num;
    NodeAddress linkedList;
    
    printf("Enter size of array : ");
    scanf("%d", &num);
    int A[num];
    
    for (int i=0; i<num; i++) {
        int x;
        printf("Enter an element : ");
        scanf("%d", &x);
        A[i] = x;
    }
        
    
    linkedList = makeLinked(A,num);
    selectionSort(A,num);
    
    printf("Linked List after Selection Sort :-\n");
    
    for (int i=0; i<num; i++) {
        printf("%d\n", A[i]);
    }

    return 0;
}
