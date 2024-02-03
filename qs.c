// program of randomized quick sort
#include <stdio.h>
#include <stdlib.h>

void swap(int* x, int* y){ //swap function
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int a[], int l, int h){ //function for partioning of array
    int up = h, down = l;
    int pivotIndex = l + rand() % (h - l + 1); //randomization of pivot index
	swap(&a[l], &a[pivotIndex]);
	int pivot = a[l];

    while(down < up){
        while(pivot < a[up] && up > l)
            up--;
        while(pivot > a[down] && down < h)
            down++;
        if(down < up)
            swap(&a[up], &a[down]);
    }
    swap(&a[up], &pivot);
    return up;
}

void quickSort(int a[], int l, int h){ //quick sort function
    if(l < h){
        int p=partition(a, l, h);
        quickSort(a, l, p-1);
        quickSort(a, p+1, h);
    }
}

int  main(){ //main function
    int num, arr[100];
    printf("Enter size of Array: ");
    scanf("%d", &num);
    printf("Enter elements of Array:\n");
    for(int i=0; i<num; i++)
        scanf("%d", &arr[i]);
    
    printf("\nUnsorted Array: ");
    for(int i=0; i<num; i++)
        printf("%d ", arr[i]);

    quickSort(arr, 0, num-1);
    printf("\nSorted Array: ");
    for(int i=0; i<num; i++)
        printf("%d ", arr[i]);
    return 0;
}

hellllllllllllllllllllllllllllllllllllllloooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo