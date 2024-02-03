//sorting an array
#include <stdio.h>

//swapping algorithm
void swap(int* n1, int* n2){
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

//selection sort algorithm
void selectionSort(int a[], int l){
    int s, pos = 0, temp;
    for (int i = 0; i < l; i++){
        s = a[i];
        pos = i;
        for (int j = i+1; j < l; j++){
            if (s > a[j]){
                pos = j;
                s = a[j];
            } 
        }
        swap(&a[pos], &a[i]);
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

    selectionSort(arr, length);

    printf("Sorted Array: ");
    for(int i=0; i<length; i++)
        printf("%d ",arr[i]);
    printf("\n");

    return 0;
}


