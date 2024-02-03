//Bubble sorting an array
#include <stdio.h>

void swap(int* num1, int* num2);
void bubbleSort(int arr[], int len);

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

    bubbleSort(arr, length);

    printf("Sorted Array: ");
    for(int i=0; i<length; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}

//swapping function
void swap(int* num1, int* num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

//bubble sort function
void bubbleSort(int arr[], int len)
{
    int pos;
    for(int i=0; i<len-1; i++)
    {
        for(int j=0; j<len-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
                
        }
    }
}