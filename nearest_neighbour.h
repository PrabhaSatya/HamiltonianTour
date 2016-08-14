#ifndef NN_H
#define NN_H
#include "graph.h"

extern int nearneighbour[5000];
void nearest_neighbour(struct edgeHashTable *edgeHash,int v,int *nearneighbour);
extern struct edgeHashTable *edgeHash;

#endif
