#include <stdio.h>

void swap(int *a, int *b) {
    int z = *a;
    *a = *b;
    *b = z;
}

int sortHeap(int A[], int num) {
    int x;
    int rootEl;
    int tmp;
    
    for (int i = 1; i <  num; i++) {
        x=i;
        
        while (x !=  0) {
            rootEl  = (x - 1)/2;
            /* to create MAX A  array */
            if  (A[rootEl] < A[x]) {
                swap(&A[rootEl], &A[x]);
            }
            x =  rootEl;
        }
    }
        
    for (int j = num - 1; j  >= 0; j--) {
        swap(&A[0], &A[j]);
        
        rootEl = 0;
        
        while (x<j) {
            x = 2*rootEl+1;
            
            if ((A[x] < A[x + 1]) && x < j-1) {
                x++;
            }

            if  (A[rootEl]<A[x] && x<j) {
                swap(&A[rootEl], &A[x]);
            }
            
            rootEl  = x;
        }

    }
    for (int i = 0; i <  num; i++) {
        printf("%d\n", A[i]);
    }

    return 0;

}

int main () {
    int num;
    printf("Enter size of array : ");
    scanf("%d", &num);
    int A[num];
    
    for (int i=0; i<num; i++) {
        int x;
        printf("Enter an element : ");
        scanf("%d", &x);
        A[i] = x;
    }
    
    printf("Array after Heap Sort :- \n");
    sortHeap(A, num);
    
    return 0;
}
