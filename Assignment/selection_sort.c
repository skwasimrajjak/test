//Selection sorting an array
#include <stdio.h>

void swap(int* num1, int* num2);
void selectionSort(int arr[], int len);

int main()
{
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
        printf("%d ",arr[i]);
    printf("\n");

    selectionSort(arr, length);

    printf("Sorted Array: ");
    for(int i=0; i<length; i++)
        printf("%d ",arr[i]);
    printf("\n");

    return 0;
}

//swapping algorithm
void swap(int* num1, int* num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

//selection sort algorithm
void selectionSort(int arr[], int len)
{
    int s, pos = 0, temp;
    for (int i = 0; i < len; i++)
    {
        s = arr[i];
        pos = i;
        for (int j = i+1; j < len; j++)
        {
            if (s > arr[j])
            {
                pos = j;
                s = arr[j];
            } 
        }
        swap(&arr[pos], &arr[i]);
    }
}