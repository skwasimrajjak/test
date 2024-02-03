//Insertion sorting an array

#include <stdio.h>

void insertionSort(int arr[], int len);

int main(){
    int arr[10];
    int length;
    printf("Enter no. of elements of array: ");
    scanf("%d",&length);

    for(int i=0; i<length; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d",&arr[i]);
    }

    printf("Unsorted Array: ");
    for(int i=0; i<length; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    insertionSort(arr, length);

    printf("Sorted Array: ");
    for(int i=0; i<length; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}

//insertion sort function
void insertionSort(int arr[], int len)
{
    int key, i, j;
    for(i=1; i<len; i++)
    {
        key = arr[i];
        j = i-1;
        while(j>=0 && key<arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}