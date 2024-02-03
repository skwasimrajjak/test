// Quick Sorting an array

#include<stdio.h>
#include<stdlib.h>

void swap(int* p, int* q);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int main()
{
    int arr[20];
    int i, n;

    printf("Enter no of elements of array: ");
    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
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

// swaping function
void swap(int* p, int* q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

//dividing array around pivot
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low-1;

    for(int j=low; j<high-1; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

//sorting function
void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}