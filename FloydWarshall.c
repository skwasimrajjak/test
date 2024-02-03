//implementation of Floyd Warshall Algorithm
#include <stdio.h>
#define MAX 100

int min(int x, int y) { //to find smaller of 2 numbers
	if(x < y) return x;
	else return y;
}

void floydWarshall(int n, int w[][MAX]) { //logic
	int d[MAX][MAX];
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			d[i][j] = w[i][j];
		}
	}
	for(int k=0; k<n; k++) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				d[i][j] = min((d[i][k]+d[k][j]), d[i][j]);
			}
		}
	}
	printf("\nD matrix is:\n");
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++)
			printf("%d ", d[i][j]);
		printf("\n");
	}
}

int main() { //main function
	int w[MAX][MAX];
	int n;
	printf("Enter number of rows and columns: ");
	scanf("%d", &n);
	printf("Enter Weights (For infinity, enter a large value compared to other inputs):\n");
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			printf("W[%d][%d]: ",i+1, j+1);
			scanf("%d", &w[i][j]);
		}
	}
	floydWarshall(n, w);
	return 0;
}
