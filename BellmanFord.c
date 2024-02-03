// implementation of Bellman Ford Algorithm
#include <stdio.h>
#include <stdlib.h>

#define INFINITY 99999

typedef struct Edge {
	int u;
	int v;
	int w;
}e;

typedef struct Graph {
	int V;
	int E;
	struct Edge *edge;
}gr;

void display(int arr[], int size) {
	for (int i = 1; i <= size; i++)
		printf("%d ", arr[i]);
}

void bellmanFord(gr g, int source) { //logic
	int i, j, u, v, w;
	int tV = g.V;
	int tE = g.E;
	int d[tV];
	for (i = 1; i <= tV; i++)
		d[i] = INFINITY;

	d[source] = 0;
	for (i = 2; i <= tV; i++) {
		for (j = 0; j < tE; j++) {
			u = g.edge[j].u;
			v = g.edge[j].v;
			w = g.edge[j].w;
			if (d[u] != INFINITY && d[v] > d[u] + w)
				d[v] = d[u] + w;
		}
	}

	for (i = 0; i < tE; i++) {
		u = g.edge[i].u;
		v = g.edge[i].v;
		w = g.edge[i].w;
		if (d[u] != INFINITY && d[v] > d[u] + w) {
			printf("Negative weight cycle detected!\n");
			return;
		}
	}
	printf("\nDistance array: ");
	display(d, tV);
}

int main() { //main function
	gr g;
	printf("Enter number of vertices: ");
	scanf("%d", &g.V);
	printf("Enter number of edges: ");
	scanf("%d", &g.E);
	g.edge = (e*)malloc(g.E * sizeof(e));

	for (int i = 0; i < g.E; i++) {
		printf("\nFor edge %d:\n", i + 1);
		printf("Vertex u- ", i);
		scanf("%d", &g.edge[i].u);
		printf("Vertex v- ", i);
		scanf("%d", &g.edge[i].v);
		printf("Weight w- ", i);
		scanf("%d", &g.edge[i].w);
	}

	bellmanFord(g, 1);
	return 0;
}