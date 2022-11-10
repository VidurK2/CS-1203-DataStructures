#include <stdio.h>
#include <stdlib.h>

//Function to do selection sort on array
int selectSort(int A[], int num) {
    
    int pos; //Keeps track of the minimum index
    
    //Traversing through the list and selecting elements as 'pos'
    for (int i=0; i<num-1; i++) {
        pos = i;
        
        //Comparing that pos with j of Array
        for (int j=i+1; j<num; j++) {
            if (A[j] < A[pos]) {
                pos = j;
            }
            
            //If the pos isnt the same as i, then we swap the elements
            if (pos!=i) {
                int z = A[pos];
                A[pos] = A[i];
                A[i] = z;
            }
        }
    }
    
    return 0;
}

//Function to print out the array
int printArr(int A[], int num) {
    for (int i=0; i<num; i++) {
        int x = A[i];
        printf("%d \t", x);
    }
    printf("\n");
    
    return 0;
}

//Main function that creates the array with input
int main () {
    int num;
    printf("Enter number of elements : ");
    scanf("%d", &num);
    
    int A[num];
    
    for (int i=0; i<num; i++) {
        int x;
        printf("Enter element : ");
        scanf("%d", &x);
        
        A[i] = x;
    }
    
    selectSort(A, num);
    
    printf("========Sorted List=========\n");
    printArr(A, num);
    
    return 0;
}
