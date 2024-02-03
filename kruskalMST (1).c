//implementation of Kruskal's MST
#include <stdio.h>
#include<stdlib.h>
#define MAX 30

//global variables
int n;
int e;
int *p;
int *r;

typedef struct edge { //structure of edge
    int u, v, w;
} edge;

int make_set(int x) {
	p[x]=x;
	r[x]=0;
}

void sort(edge ar[]) {
    int i, j;
    edge temp;
    for (i = 0; i<e-1; i++)
    for (j = 0; j <e-1-i; j++)
      if (ar[j].w > ar[j + 1].w) {
        temp = ar[j];
        ar[j] = ar[j + 1];
        ar[j + 1] = temp;
    }
}

int findset(int x) {
	if(x != p[x])
	    p[x]=findset(p[x]);		
	return p[x];
}

void link(int x, int y) {
	if(r[x]>r[y])
		p[y]=x;
	else {
		p[x]=y;
		if(r[x] == r[y])
			r[y]=r[y]+1;
	}
}

void union_set(int x, int y) {
	link(findset(x), findset(y));
}

int kruskal(edge a[]) { //main logic
	int A[MAX];
	int i,j;
	p = (int*)malloc(n * sizeof(int));
    r = (int*)malloc(n * sizeof(int));
	for(i=0;i<n;i++)
		make_set(i);
	sort(a);
	for(i=0;i<e;i++) {
		if(findset(a[i].u) != findset(a[i].v)) {
	     	A[i] = a[i].w;
	     	union_set(a[i].u,a[i].v);
		}
		else
			A[i]=0;
	}
	
    printf("\n");
	for(i=0;i<e;i++) {
		if(A[i] != 0)
            printf("Weight of (%d, %d) = %d\n", a[i].u, a[i].v, A[i]);
	}
	free(p);
    free(r);
}

int main() {
	int i,j;
	printf("Enter the number of vertices: ");
	scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);
	edge *edges = (edge*)malloc(n * sizeof(edge));
	for(i=0;i<e;i++){
        printf("\nFor edge %d:\nEnter u- ", (i+1));
        scanf("%d", &edges[i].u);
        printf("Enter v- ");
        scanf("%d", &edges[i].v);
        printf("Enter w- ");
        scanf("%d", &edges[i].w);
    }
	kruskal(edges);
    free(edges);
    return 0;
}
