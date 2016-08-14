#include "heapsort.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern struct edgeHashTable *edgeHash;
//extern struct Edge *edges;
int heapsize;

//struct Edge *t = (struct Edge *)malloc(sizeof(struct Edge));

void build_heap(struct Edge *edges, int numEdges) {
    //printf("Hi in build_heap! \n");
   // printf("\nNumedges: %d", numEdges);
    int i, n;
    heapsize = numEdges;
    for (i = (numEdges-1)/2; i >= 0; i--)
        max_heapify(edges, i);
}

//struct Edge *t = (struct Edge *)malloc(sizeof(struct Edge));
int heapsort(struct Edge *edges, int numEdges) {
    //printf("Hi in heapsort! \n");
    build_heap(edges, numEdges);
    int i, f;
   
    struct Edge *t = (struct Edge *)malloc(sizeof(struct Edge));
    //struct Edge t;
    for (i = numEdges-1; i >= 1; i--) {
        t->vertexId1 = edges[0].vertexId1;
        t->vertexId2 = edges[0].vertexId2;
        t->weight = edges[0].weight;
        
        edges[0].vertexId1 = edges[i].vertexId1;
        edges[0].vertexId2 = edges[i].vertexId2;
        edges[0].weight = edges[i].weight;
        
        edges[i].vertexId1 = t->vertexId1;
        edges[i].vertexId2 = t->vertexId2;
        edges[i].weight = t->weight;
        
        heapsize = heapsize - 1;
        max_heapify(edges, 0);        
    }
    //printf("\nHeapsort done!\n\n");
    //printf("Printing sorted edges from heapsort: \n");
    //printf("numEdges: %d\n", numEdges);
    //for(f=0; f < numEdges; f++)
      //  printf("%s \t %s \t%d\n",getVertexName(edges[f].vertexId1), getVertexName(edges[f].vertexId2), edges[f].weight);
    return 0;
}


void max_heapify(struct Edge *edges, int index) {
    //printf("Hi in max_heapify!\n");
    int l, r, largest;
    struct Edge t;
    //struct Edge *t = (struct Edge *)malloc(sizeof(struct Edge));
    l = 2*index;
    r = 2*index + 1;
    if ((l < heapsize) && (edges[l].weight > edges[index].weight)) 
        largest = l;
    else
        largest = index;
    if ((r < heapsize) && (edges[r].weight > edges[largest].weight))
        largest = r;
    if (largest != index) {
        //t = edges[index];
        t.vertexId1 = edges[index].vertexId1;
        t.vertexId2 = edges[index].vertexId2;
        t.weight = edges[index].weight;
        
        //edges[index] = edges[largest];
        
        edges[index].vertexId1 = edges[largest].vertexId1;
        edges[index].vertexId2 = edges[largest].vertexId2;
        edges[index].weight = edges[largest].weight;
        
        //edges[largest] = t;
        
        edges[largest].vertexId1 = t.vertexId1;
        edges[largest].vertexId2 = t.vertexId2;
        edges[largest].weight = t.weight;
        max_heapify(edges, largest);
    }    
}







