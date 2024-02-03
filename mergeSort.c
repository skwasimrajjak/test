// merge sort program
#include <stdio.h>

void merge(int a[], int l, int m, int h){ //merges parts of array in sorted manner
    int i = l;
    int j = m+1;
    int k = l;
    int aux[100]; //stores sorted array

    while(i<=m && j<=h){
        if(a[i]<a[j])
        aux[k++] = a[i++];
        else
        aux[k++] = a[j++];
    }
    while(i<=m)
        aux[k++] = a[i++];
    while(j<=h)
        aux[k++] = a[j++];

    //copy values to original array
    for(int k=l; k<=h; k++)
    a[k] = aux[k];
}

void mergeSort(int a[], int l, int h){ //function of merge sort
    if(l<h){
        int m = (l+h)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, h);
        merge(a, l, m, h);
    }
}

int main(){ //main function
    int num, arr[100];
    printf("Enter size of Array: ");
    scanf("%d", &num);
    printf("Enter elements of Array:\n");
    for(int i=0; i<num; i++)
        scanf("%d", &arr[i]);
    
    printf("\nUnsorted Array: ");
    for(int i=0; i<num; i++)
        printf("%d ", arr[i]);

    mergeSort(arr, 0, num-1);
    printf("\nSorted Array: ");
    for(int i=0; i<num; i++)
        printf("%d ", arr[i]);
    return 0;
}