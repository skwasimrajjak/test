//sorting an array
#include <stdio.h>

//swapping algorithm
void swap(int* n1, int* n2){
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

//bubble sort algorithm
void bubbleSort(int a[], int l){
    int pos;
    for(int i=0; i<l-1; i++){
        for(int j=0; j<l-i-1; j++){
            if(a[j] > a[j+1])
                swap(&a[j], &a[j+1]);
        }
    }
}

int main(){
    int arr[10];
    int length;
    printf("Enter no. of elements of array: ");
    scanf("%d",&length);

    for(int i=0; i<length; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d",&arr[i]);
    }

    printf("Unsorted Array: ");
    for(int i=0; i<length; i++)
        printf("%d ",arr[i]);
    printf("\n");

    bubbleSort(arr, length);

    printf("Sorted Array: ");
    for(int i=0; i<length; i++)
        printf("%d ",arr[i]);
    printf("\n");

    return 0;
}