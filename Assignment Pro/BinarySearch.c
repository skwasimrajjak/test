//searching an element in a sorted array
#include <stdio.h>

//binary search algorithm
int binarySearch(int a[], int length, int key){
    int l = 0, u = length-1, mid, flag;

    while(l <= u){
        mid = (l+u)/2;

        if(a[mid] == key){
            flag = 1;
            break;
        }
        else if(a[mid] < key)
            l = mid + 1;
        else
            u = mid - 1;
    }

    if(flag == 1)
        return mid+1;
    else
        return -1;
}

int main(){
    int arr[10];
    int searchKey, length, position, flag;
    printf("Enter no. of elements of array: ");
    scanf("%d",&length);

    for(int i=0; i<length; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d",&arr[i]);
    }

    printf("Enter search item: ");
    scanf("%d",&searchKey);

    position = binarySearch(arr, length, searchKey);
    if(position != -1)
        printf("%d is present at position %d of given array\n", searchKey, position);
    else
        printf("%d is absent in given array\n", searchKey);
    return 0;
}