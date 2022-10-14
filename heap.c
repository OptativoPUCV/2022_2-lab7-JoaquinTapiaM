#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;

//2. Implemente la función `void* heap_top(Heap* pq)`. Esta función retorna el dato con mayor prioridad del montículo. 
 //   > Recuerde que este dato se encuentra en la raíz el montículo, es decir, en la primera casilla del arreglo.

void* heap_top(Heap* pq){
    heapElem * dato = pq->heapArray[0];
    return dato->data;
}



void heap_push(Heap* pq, void* data, int priority){

}


void heap_pop(Heap* pq){

}

//1. Implemente la función `Heap* createHeap()`. Esta función crea un nuevo dato de tipo Heap inicializando sus variables. Considere que la capacidad incial es de 3 casillas para el arreglo.
// > Recuerde reservar memoria para el Heap y también para el arreglo `heapArray`.

Heap* createHeap(){
    Heap * heap = (Heap*)calloc(1,sizeof(Heap));
    heap->capac = 3;
    heap->size = 0;
    heapElem * array = (heapElem*)calloc(3,sizeof(heapElem)) ; 
    heap->heapArray = array;
   return heap;
}
