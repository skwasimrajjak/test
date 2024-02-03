//program to find maximum from an array using Divide And Conquer
#include <stdio.h>
int findmax(int a[], int l, int h){ //recursion function
        if(l==h) return a[l];
        else{
                int m = (l+h)/2; 
                int max1 = findmax(a, l, m); 
                int max2 = findmax(a, m+1, h); 
                if(max1 > max2) return max1; 
                else return max2;
        }
}

int main(){ //main function
        int n; 
        printf("Enter number of elements: "); 
        scanf("%d", &n);

        int arr[100]; 
        printf("Enter elements of array:\n");
        for(int i=0; i<n; i++){
                scanf("%d", &arr[i]);
        }
        int res = findmax(arr, 0, n-1); 
        printf("Maximum: %d", res); 
        return 0;
}