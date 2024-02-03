//Implementaation of linear search

#include<stdio.h>
#include<stdlib.h>

void Linear_search(int arr[], int size, int item);

int main()
{
    int i, size;
    int arr[100];
    int item;
    char choice;
    do
    {
        printf("Enter total number of elements: ");
        scanf("%d",&size);

        
        for(i=0; i<size; i++)
        {
            printf("Enter the element-%d: ", i+1);
            scanf("%d",&arr[i]);
        }

        printf("Enter the element to be searched: ");
        scanf("%d",&item);

        Linear_search(arr, size, item);

        printf("\nWant to continue(y/n): ");
        scanf(" %c", &choice);
    }while(choice=='y');
    return 0;
}

//Linear Search Function
void Linear_search(int arr[], int size, int item)
{
    int i, flag = 0;
    
    while(i<=size)  //loop to search element
    {
        if(arr[i] == item)
        {
            printf("%d is present at position %d.",item,i+1);
            flag = 1;
            break;
        }
        i++;
    }
        if(flag == 0)
        {
            printf("%d is not in this Array.",item);
        }
}