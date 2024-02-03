//greedy approach for Job sequencing
#include <stdio.h>
#include <stdlib.h>

//structure for Jobs
typedef struct Job{
    int id;
    int deadline;
    int profit;
}Job;

//sorts the job array according to profit
void sortFunc(Job* jobArr, int n){
    for(int i=1; i<n; i++){
        Job key = jobArr[i];
        int j = i-1;
        while(j>=0 && key.profit>jobArr[j].profit){
            jobArr[j+1] = jobArr[j];
            j--;
        }
        jobArr[j+1] = key;
    }
}

//greedy method
void sequencing(Job* jobArr, int max, int n){
    int sequence[max+1];
    for (int i=1; i<=max; i++){
        sequence[i] = -1;
    }
    int totProfit = 0;

    for(int i=0; i<n; i++){
        int j = jobArr[i].deadline;
        while(j >= 0){
            if(sequence[j] == -1){
                sequence[j] = jobArr[i].id;
                totProfit += jobArr[i].profit;
                break;
            }
            j--;
        }
    }

    printf("\nJob Sequence Array: ");
    int i=1;
    do{
        printf("%d ", sequence[i]);
        i++;
    }while(sequence[i] != -1 && i <= max);

    printf("\nTotal Profit: %d\n", totProfit);
}

int main(){
    int n;
    printf("Enter no. of Jobs: ");
    scanf("%d", &n);
    Job* jobArr = (Job*)malloc(n * sizeof(Job*));
    for(int i=0; i<n; i++){
        printf("Enter Job id %d: ",(i+1));
        scanf("%d", &jobArr[i].id);
        printf("Enter Job profit %d: ",(i+1));
        scanf("%d", &jobArr[i].profit);
        printf("Enter Job deadline %d: ",(i+1));
        scanf("%d", &jobArr[i].deadline);
    }

    printf("\nJob Details:\n");
    printf("Id\tProfit\tDeadline\n");
    for(int i=0;i<n;i++){
        printf("%d\t", jobArr[i].id);        
        printf("%d\t", jobArr[i].profit);
        printf("%d\n", jobArr[i].deadline);
    }

    int m = 0; //to find maximum
    for(int i=0; i<n; i++){
        if(m < jobArr[i].deadline)
            m = jobArr[i].deadline;
    }
    printf("\nMaximum Deadline: %d\n", m);
    
    sortFunc(jobArr, n);
    printf("\nSorted Jobs (by profit in descending order):\n");
    printf("Id\tProfit\tDeadline\n");
    for(int i=0;i<n;i++){
        printf("%d\t", jobArr[i].id);
        printf("%d\t", jobArr[i].profit);
        printf("%d\n", jobArr[i].deadline);
    }

    sequencing(jobArr, m, n);
    free(jobArr); //free dynamically allocated memory
    return 0;
}