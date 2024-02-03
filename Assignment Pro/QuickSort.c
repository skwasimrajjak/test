// sorting an array using Quick Sort

// header files
#include<stdio.h>
#include<stdlib.h>

// swaping algo
void swap(int* p, int* q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

//dividing array around pivot
int partition(int a[], int low, int high){
    int pivot = a[high];
    int i = low-1;

    for(int j=low; j<high-1; j++){
        if(a[j] < pivot){
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1], &a[high]);
    return i+1;
}

//sorting algorithm
void quickSort(int a[], int low, int high){
    if(low < high){
        int pivot = partition(a, low, high);
        quickSort(a, low, pivot-1);
        quickSort(a, pivot+1, high);
    }
}

int main(){
    int arr[20];
    int i, n;

    printf("Enter no of elements of array: ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("Enter element %d: ",(i+1));
        scanf("%d",&arr[i]);
    }

    printf("Unsorted Array: ");
    for(i=0; i<n; i++)
        printf("%d ",arr[i]);
    printf("\n");
    
    quickSort(arr, 0, n-1);
    
    printf("Sorted Array: ");
    for(i=0; i<n; i++)
        printf("%d ",arr[i]);
    printf("\n");

    return 0;
}