// Implementation of  Counting Sort
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void countingSort(int arr[], int max, int num){
	int c[100];
	int b[100];
	for(int i=1; i<=max; i++) //initialising count array
		c[i] = 0;
	for(int i=0; i<num; i++) //storing count of elements
		c[arr[i]] = c[arr[i]] + 1;
	for(int i=2; i<=max; i++) //calculating cumulative count
		c[i] = c[i]+c[i-1];
	for(int i=num-1; i>=0; i--){ //sorting according to count array
		b[c[arr[i]]] = arr[i];
		c[arr[i]]--;
	}
	for (int i = 1; i <=num; i++)//copy sorted values to original array
        arr[i-1] = b[i];
}

int main(){
    int num, arr[100];
    printf("Enter size of Array: ");
    scanf("%d", &num);
    printf("Enter elements of Array:\n");
    for(int i=0; i<num; i++)
        scanf("%d", &arr[i]);
    
    printf("\nUnsorted Array: ");
    for(int i=0; i<num; i++)
        printf("%d ", arr[i]);

    //for finding maximum from array
    int max=INT_MIN;
    for(int i=0; i<num; i++){
        if(max<arr[i])
            max=arr[i];
    }

    countingSort(arr, max, num);
    printf("\nSorted Array: ");
    for(int i=0; i<num; i++)
        printf("%d ", arr[i]);
    return 0;
}