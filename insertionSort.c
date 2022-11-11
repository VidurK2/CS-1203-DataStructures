#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sortInsertion (int A[], int num) {
    
    int z;
    
    for (int i = 1; i < num; i++) {
       z = i;
        
       while (z > 0 && A[z - 1] > A[z])
       {
           swap(&A[z], &A[z-1]);
           z--;
       }
   }
   
   for (int i = 0; i < num; i++)
   {
       printf("%d\n", A[i]);
   }
}

int main () {
    
    int num;
    printf("Enter the size of the array : ");
    scanf("%d", &num);
    int A[num];

    for (int i=0; i<num; i++) {
        int x;
        printf("Enter an element : ");
        scanf("%d", &x);
        A[i] = x;
    }

    printf("Array after Insertion Sort :- \n");
    sortInsertion(A, num);
    
   return 0;
}
