#include <stdio.h>
#include <stdlib.h>

int quickPart(int A[], int start, int end) {
    int pivot = A[end]; //Setting the last element as the pivot
    
    //Traversing through the array from start to end
    for (int i=start; i<end; i++) {
        
        //If ith element is less than pivot then we swap and move one elment forward
        if (A[i] <= pivot) {
            int x = A[i];
            A[i] = A[start];
            A[start] = x;
            start++;
        }
    }
    
    //We swap the first and last element before returning the position to the quick sort function
    int x = A[start];
    A[start] = A[end];
    A[end] = x;
    return start;
}


//Function to do quick sort on array
int quickSortArr(int A[], int start, int end) {
    
    //Run as long as the first element is smaller than the last element
    if (start < end) {
        int pos = quickPart(A, start, end); //Taking out middle element pos
        
        //Recursing from start to middle and middle to last
        quickSortArr(A, start, pos-1);
        quickSortArr(A, pos+1, end);
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
    
    quickSortArr(A, 0, num-1);
    
    printf("========Sorted List=========\n");
    printArr(A, num);
    
    return 0;
}
