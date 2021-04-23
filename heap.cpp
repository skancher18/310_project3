#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 
#include "heap.h"
int count = 0;

HEAP *heapInit(int capacity){
    HEAP *heap;
    heap = (HEAP *) calloc(1, sizeof(HEAP));
    heap->capacity = capacity; 
    heap->size = 0;
    heap->elements = (ElementT *) calloc(capacity+1, sizeof(ElementT));
    return heap;
}

void heapPrint(HEAP *H){
    printf("capacity=%d, size=%d\n", H->capacity, H->size);
    for(int j=1; j<H->size; j++){
        printf("%d, ", H->elements[j]->key);
    }
    if(H->size!=0){
        printf("%d\n", H->elements[H->size]->key);
    }
}

int left(int i){
    return(2 * i);
}

int right(int i){
    return((2 * i) + 1);
}

int parent(int i){
    return(i/2);
}

void minHeapify(HEAP *H, int index){
    int l = left(index);
    int r = right(index);
    int smallest = index;
    if( l <= H->size && H->elements[l]->key < H->elements[index]->key){
        smallest = l;
    }
    if( r <= H->size && H->elements[r]->key < H->elements[smallest]->key){
        smallest = r;
    }
    if(smallest != index) {
        int temp = H->elements[index]->key;
        H->elements[index]->key = H->elements[smallest]->key;
        H->elements[smallest]->key = temp;
        count++;
        minHeapify(H, smallest);
    }
}

int buildHeap(HEAP *H){
    count = 0;
    for (int i = ((H->size)/2); i >= 1; i--){
        count++;
        minHeapify(H, i);
    }
    return count;
}

int extractMin(HEAP *H){
    count = 0;
    int min = H->elements[1]->key;
    H->elements[1]->key = H->elements[H->size]->key;
    H->size--;
    count++;
    minHeapify(H, 1);
    printf("Deleted key: %d\n", min);

    return count;
}

void insert(HEAP *H, ELEMENT *E){
    H->size++;
    int i = H->size;
    while(i > 1 && H->elements[parent(i)]->key > E->key){
        H->elements[i] = H->elements[parent(i)];
        i = parent(i);
    }
    H->elements[i] = E;
}

void decreaseKey(HEAP *H, int i, int value){
    H->elements[i]->key = value;
    while(i > 1 && H->elements[parent(i)]->key > H->elements[i]->key){
        int temp = H->elements[i]->key;
        H->elements[i]->key = H->elements[parent(i)]->key;
        H->elements[parent(i)]->key = temp;
        i = parent(i);
    }
}

void heapWrite(HEAP *H){
    FILE *ofile;
    int j;
    ofile = fopen("HEAPoutput.txt","w");
    fprintf(ofile, "%d\n", H->size);
    for(j=1; j<=H->size; j++){
        fprintf(ofile, "%d\n", H->elements[j]->key);
    }
    fclose(ofile);
}