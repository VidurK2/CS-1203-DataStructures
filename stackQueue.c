#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct stack {
    int *data;
    int size;
    int top;
};

typedef struct stack * StackAddress;

StackAddress init () {
    StackAddress s = malloc(sizeof(struct stack));
    
    s->top = -1;
    s->size = 100;
    s->data = malloc( s->size * sizeof(int) );
    
    return s;
}


void insertEl (StackAddress s, int val) {
    
    if (s->top >= s->size-1) {
        printf("Stack is full!\n");
        return;
    }
    
    else if ( val < 0 ) {
        printf("Value invalid!\n");
        return;
    }
    
    else {
        s->data[ ++s->top ] = val;
    }
}

void delEl (StackAddress s) {
    free(s->data);
    free(s);
}

void printStack (StackAddress s) {
    int n = s->size;
    
    for (int i=0; i<n; i++) {
        printf("%d\t", s->data[ s->top-- ]);
    }
}


//==============================================================================================================
//==============================================================================================================
//==============================================================================================================

struct queue {
    int *data;
    int size;
    int n;
    int start;
};

typedef struct queue *QueueAddress;

QueueAddress initQ () {
    QueueAddress q = malloc(sizeof(struct queue));
    
    q->size  = 100;
    q->n     = 0;
    q->start = 0;
    q->data  = malloc( q->size * sizeof(int) );
    
    return q;
}

void insertQ (QueueAddress q, int val) {
    
    if (q->n == q->size) {
        printf("Queue is full!\n");
        return;
    }
    
    q->data[ q->start + q->n++ ] = val;
}


void freeQ (QueueAddress q) {
    free(q);
}

void printQ (QueueAddress q) {
    if (q->n == 0) {
        printf("Queue is empty!\n");
        return;
    }
    
    int n = q->n;
    for (int i=0; i<n; i++) {
        printf("%d\t", q->data[ q->start++ ]);
    }
    
}

int main () {
    StackAddress s = init();
    QueueAddress q = initQ();
    
    insertEl(s, 10);
    insertEl(s, 15);
    insertEl(s, 7);
    insertEl(s, 32);
    
    printStack(s);
    
    printf("\n\n");
    
    insertQ(q, 23);
    insertQ(q, 56);
    insertQ(q, 12);
    insertQ(q, 89);
    
    printQ(q);
    
    
    return 0;
}
