// Implementation of  Radix Sort
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void countingSort(int arr[], int num, int pos){ //counting sort function
    int b[100];
    int c[100];
    for(int i=1; i<=10; i++) //initialising count array
        c[i] = 0;
    for(int i=1; i<=num; i++) //storing count of elements
        c[(arr[i]/pos)%10] = c[(arr[i]/pos)%10] + 1;
    for(int i=1; i<=10; i++) //calculating cumulative count
        c[i] = c[i] + c[i-1];
    for(int i=num; i>0; i--){ //sorting according to count array
        b[c[(arr[i]/pos)%10]] = arr[i];
        c[(arr[i]/pos)%10]--;
    }
    for (int i=1; i<=num; i++) //copy sorted values to original array
        arr[i] = b[i];
}

void radixSort(int arr[], int num, int max){
    for(int pos=1; max/pos>0; pos=pos*10){
        countingSort(arr, num, pos); //using couting sort
    }
}

int main(){
    int num,arr[100];
    printf("Enter size of Array: ");
    scanf("%d",&num);
    printf("Enter elements of Array:\n");
    for(int i=1;i<=num;i++){
        scanf("%d",&arr[i]);
    }
    
    //for finding maximum from array
    int max=INT_MIN;
    for(int i=1;i<=num;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }

    radixSort(arr,num,max);
    printf("\nSorted Array: ");
    for(int i=1; i<=num; i++)
        printf("%d ", arr[i]);
    return 0;
}