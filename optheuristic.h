#ifndef OPTHEURISTIC_H
#define OPTHEURISTIC_H

#include"llist.h"
#include "graph.h"
#include"DFS.h"
#include"hash.h"
void arr2ds(int *tour,struct edgeHashTable* edgeHash,struct Edge *tedges,struct nvertex  *tnvertices);
void BtoA(struct Edge *tedges,struct nvertex *tnvertices,struct edgeHashTable *edgeHash);
int Aoptheuristic(struct Edge *tedges,struct nvertex *tnvertices,struct edgeHashTable *edgeHash);
void Boptheuristic(struct Edge *tedges,struct nvertex *tnvertices,struct edgeHashTable *edgeHash);
void exchange(struct nvertex *tnvertices,int v1,int v2,int in2,int jn2);
void optimise(struct Edge *tedges,struct nvertex *tnvertices,struct edgeHashTable *edgeHash);

#endif
