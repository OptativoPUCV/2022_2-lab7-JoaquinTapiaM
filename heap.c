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
    heapElem * dato = pq->heapArray;
    if(pq->size==0){
      return NULL;
    }
    return dato[0].data;
}

//3. Implemente la función `void heap_push(Heap* pq, void* data, int p)`. Esta función inserta un nuevo dato con prioridad `p` en el montículo. Si no recuerda como insertar datos en el montículo puede ver las [diapositivas](https://docs.google.com/presentation/d/1ZjXWMf6g05WdICqvno_oyRvorjAThABgbRGbEqc7mYU/edit#slide=id.g55ac49ed61_0_167).

 //   > Si el arreglo está lleno aumente la capacidad al **doble + 1** usando la función `realloc` así:
   // > `arreglo = realloc(arreglo, nueva_capacidad)`

void heap_push(Heap* pq, void* data, int priority){
  heapElem elem;
  heapElem aux;
  
  elem.data = data;
  elem.priority = priority;

  if(pq->size == pq->capac){
    pq->capac = (pq->capac*2)+1;
    pq->heapArray = realloc(pq->heapArray, sizeof(int)*pq->capac);
    }
  
  int i = pq->size;
  pq->heapArray[i] = elem;
  while (i!=0){
    if(elem.priority > pq->heapArray[(i-1)/2].priority){
      aux.priority = pq->heapArray[(i-1)/2].priority;
      aux.data = pq->heapArray[(i-1)/2].data;
      pq->heapArray[(i-1)/2].priority = pq->heapArray[i].priority;
      pq->heapArray[(i-1)/2].data = pq->heapArray[i].data;
      pq->heapArray[i].priority= aux.priority;
      pq->heapArray[i].data= aux.data;
      i = (i-1)/2;
    }
    else if(elem.priority < pq->heapArray[(i-1)/2].priority){
      pq->heapArray[i] = elem;
      break;
    }
    else if(elem.priority == pq->heapArray[(i-1)/2].priority){
      break;
    }
  }
  pq->size++;
}

//4. Implemente la función `void heap_pop(Heap* pq)`. Esta función elimina el mayor elemento del montículo (la raíz).

void heap_pop(Heap* pq){
  pq->size--;
  heapElem aux;
  if(pq->size==0){
    return;
  }
  pq->heapArray[0]=pq->heapArray[pq->size];
  int i = 0;
  int j = 1;
  //si no tiene hijos se saldra del while
  while (j < pq->size){
    //caso que tenga 2 nodos hijos
    if(j+1 < pq->size){
      //al menos uno de los 2 hijos tiene mayor prioridad que el i 
      if(pq->heapArray[i].priority<pq->heapArray[j].priority ||pq->heapArray[i].priority<pq->heapArray[j+1].priority){
        //caso que j sea mayor que j+1
        if(pq->heapArray[j+1].priority < pq->heapArray[j].priority){
          aux = pq->heapArray[j];
          pq->heapArray[j] = pq->heapArray[i];
          pq->heapArray[j] = aux;
          i = j;
          j = (2*i)+1;
        }
        //caso que j+1 sea mayor que j
        if(pq->heapArray[j+1].priority > pq->heapArray[j].priority){
          aux = pq->heapArray[j+1];
          pq->heapArray[j+1] = pq->heapArray[i];
          pq->heapArray[j+1] = aux;
          i = j+1;
          j = (2*i)+1;
        }
      }
      else{
        break;
      }
    }
    //caso que solo tenga el primer hijo
    else{
      if(pq->heapArray[i].priority < pq->heapArray[j].priority){
          aux = pq->heapArray[j];
          pq->heapArray[j] = pq->heapArray[i];
          pq->heapArray[j] = aux;
          i = j;
          j = (2*i)+1;
      }
      break;
    }
  }
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
