
#ifndef _graph_h
#define _graph_h 1

#include <stdio.h>

typedef struct TAG_VERTEX {
	int color;
	int pi;
	float dist;
	int pos;
	char *name;
}VERTEX;
typedef VERTEX *pVERTEX;

typedef struct TAG_NODE{
	int u;
	int v;
	float w;
	TAG_NODE *next;
}NODE;
typedef NODE *pNODE;

typedef struct TAG_PATH{
	int vertex;
	TAG_PATH *next;
}PATH;
typedef PATH *pPATH;

void printPath(int n, int source, int destination, int s, int t);
int dijkstra(int n, pNODE *A, int s, int t, int flag);

#endif