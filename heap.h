#ifndef heap_H_
#define heap_H_
#include <stdio.h>

typedef struct TAG_ELEMENT{
    int key;
}ELEMENT;

typedef ELEMENT *ElementT;

typedef struct TAG_HEAP{
    int capacity; /* max size of the heap */
    int size; /* current size of the heap */
    ElementT *elements; /* pointer to pointers to elements */
}HEAP;

HEAP *heapInit(int capacity);
void heapPrint(HEAP *H);
void heapWrite(HEAP *H);
void insert(HEAP *H, ELEMENT *E);
int extractMin(HEAP *H);
void decreaseKey(HEAP *H, int i, int value) ;
int buildHeap(HEAP *H);
void minHeapify(HEAP *H, int index);
int right(int i);
int left(int i);
#endif