#include <stdio.h>
#include <stdlib.h>

int partTest(int *Arr, int first, int stop){
    int pivot = Arr[first];
    int i = first+1;
    int j = stop;

    while (i <= j){
        if (Arr[i] > pivot){
//            swap (Arr, i, j);
            j--;
        }
        else {
            i++;
        }
    }
//    swap (Arr, first, j);
    return j;
}

int partition(int *Arr, int first, int last){
    int pivot = Arr[last];
    int ind = first;
    for (int i = first; i < last; i++){
        if(Arr[i] <= pivot){
            int temp = Arr[i];
            Arr[i] = Arr[ind];
            Arr[ind] = temp;
            ind++;
        }
    }
    int temp = Arr[ind];
    Arr[ind] = Arr[last];
    Arr[last] = temp;
    return ind;
}

void quickSort(int *Arr, int first, int last){
    if(Arr && first < last){
        int ind = partition(Arr, first, last);
        quickSort(Arr, first, ind-1);
        quickSort(Arr, ind+1, last);
    }
}

int main(){
    int Arr[] = {1, 2, 3, 4, 10, 7, 33};
    int n = sizeof(Arr)/sizeof(Arr[0]);
    quickSort(Arr, 0, n-1);
    for (int i = 0; i < n; i++){
        printf("%d ", Arr[i]);
        
    return 0;
    }
}
