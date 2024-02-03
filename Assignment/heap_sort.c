// Heap Sorting an array

#include<stdio.h> 

void swap(int* p, int* q);
void heapify(int arr[], int len);
void heapSort(int arr[], int len);

int main()
{
    int arr[20];
    int i, len;

    printf("Enter no of elements of array: ");
    scanf("%d", &len);

    for(i=0; i<len; i++)
    {
        printf("Enter element %d: ",(i+1));
        scanf("%d",&arr[i]);
    }

    printf("Unsorted Array: ");
    for(i=0; i<len; i++)
        printf("%d ",arr[i]);
    printf("\n");
    
    heapSort(arr, len);

    printf("Sorted Array: ");
    for(i=0; i<len; i++)
        printf("%d ",arr[i]);
    printf("\n");

    return 0;
}

// swap items of heap
void swap(int* p, int* q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

// arrange heap
void heapify(int arr[], int len)
{
    int i, child, parent;
    for(i = len/2 - 1; i>=0; i--)
    {
        parent = i;
        while(parent < len)
        {
            child = 2*parent + 1;
            if(child >= len)
                break;
            if(child < len-1 && arr[child] < arr[child+1])
                child = child + 1;
            if(arr[parent] < arr[child])
            {
                swap(&arr[parent], &arr[child]);
                parent = child;
            }
            else
                break;
        }
    }
}

// sorting logic
void heapSort(int arr[], int len)
{
    heapify(arr, len);
    for(int i = len-1; i>0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i);
    }
}