//Binary Searching Program

#include<stdio.h>
#include<stdlib.h>

void Binary_search(int arr[], int n, int item);

int main()
{
    int i;
    int size,key;
    int arr[100];
    char choice;
    do{
        printf("\nTotal number of elements: ");
        scanf("%d",&size);
        printf("\nEnter the elements in ascending order (with spaces): ");
        for(i=0;i<size;i++)
        {
            scanf("%d",&arr[i]);
        }
        printf("\nEnter the element to be searched: ");
        scanf("%d",&key);
        Binary_search(arr, size, key);

        printf("WAnt to continue(y/n): ");
        scanf(" %c", &choice);
    }while(choice=='y');
    
    return 0;
}


//Binary Search function
void Binary_search(int arr[], int n, int item)
{
    int UB,LB;
    int i,mid;
    int flag = 0;
    UB=n-1;
    LB=0;
    while(LB<=UB)
    {
        mid=(LB+UB)/2;
        if(arr[mid]==item)
        {
            flag=1;
            break;
        }
        else
        {
            if(arr[mid]<item)
            {
                LB=mid+1;
            }
            else
            {
                UB=mid-1;
            }
        }
    }
    if(flag==1)
    {
        printf("\nElement found at position %d.\n",mid+1);
    } 
    else
    {
        printf("\nElement Not Found.\n");
    }
}