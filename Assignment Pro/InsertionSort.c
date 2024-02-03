//sorting an array
#include <stdio.h>

//insertion sort algorithm
void insertionSort(int a[], int l){
    int key, i, j;
    for(i=1; i<l; i++){
        key = a[i];
        j = i-1;
        while(j>=0 && key<a[j]){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
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

    insertionSort(arr, length);

    printf("Sorted Array: ");
    for(int i=0; i<length; i++)
        printf("%d ",arr[i]);
    printf("\n");

    return 0;
}