#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "heap.h"

extern VERTEX *V;
void printPath(int n, int source, int destination, int s, int t) 
{

    PATH *pPath;
    PATH *pNode;
    int u, v;

    if (V[t].color == 0){
        if (destination < 1 || destination > n || t == destination){
            printf("NO %d-%d path exists. \n", s, t);
            return;
        }
        else{
            printf("No %d-%d path has been computed. \n", s, t);
            return;
        }
    }
    else if (V[t].color == 1){
        printf("Path not known to be shortest: <%d", s);
    }
    else if (V[t].color == 2){
        printf("Shortest path: <%d", s);
    }

    pNode = (PATH *) malloc(sizeof(PATH));
    pNode->vertex = t;
    pNode->next = NULL;
    pPATH = pNode;
    v = pNode ->vertex;
    while (V[v].pi){
        u = V[v].pi;
        pNode = (PATH *) malloc(sizeof(PATH));
        pNode->vertex = u; pNode->next = pPath;
        pPATH = pNode;
        v = pNode->vertex;
    }

    while (pPath){
        pNode = pPATH;
        printf(", %d", pNode->vertex);
        pPATH = pPATH->next;
        free(pNode);
    }
    printf(">\n");
    printf("The path weight is: %12.4f\n", V[t].dist);
}

int dijkstra(int n, pNODE *A, int s, int t, int flag){
    pNODE node;
    HEAP *heap;
    ELEMENT *element;

    int u, v, i;
    float w;

    int pos;
    int count_Heapify;

    for (i = 1; i <= n; i++) {
        V[i].color = 0;
        V[i].pi = 0;
    }
    V[s].dist = 0;
    V[s].color = 1;

    heap = heapInit(n);
    element = (ELEMENT *) malloc(sizeof(ELEMENT));
    element->vertex = s;
    element->key = 0;
    Insert(heap, element);
    if (flag == 1){
        printf("Insert vertex %d, key=%12.4f\n", element->vertex, element->key);
    }

    while (heap->size){
        element = DeleteMin(heap, &flag, &count_Heapify);
        if (flag == 1) {
            printf("Delete vertex %d, key=%12.4f\n", element->vertex, element->key);
        }
        u = element->vertex;
        V[u].color = 2;
        if (elment->vertex == t) {
            break;
        }
        free(element);

        node = A[u];
        while (node) {
            v = node->v;
            w = node->w;
            if (V[v].color == 0){
                V[v].dist = V[u].dist + w;
                V[v].pi = u;
                V[v].color = 1;
                V[v].pos = heap->size + 1;
                element = (ELEMENT *) malloc(sizeof(ELEMENT));
                element->vertex = v;
                element->key = V[v].dist;

                // missing
            }
            //missing
        }

        //missing
    }

    //missing

}