#ifndef DFS_H
#define DFS_H
#include "graph.h"
#include"hash.h"



struct nvertex
{	int vertexId;
	int neighborid1;
	int neighborid2;
};

struct adjvertex
{	int vertexId;
	struct adjvertex* next;
};
void DFS_visit(struct adjvertex** adjlist,char *color,int* prevertexId,int i,int *DFSA_tour);
void DFS(struct adjvertex **adjlist,char *color,int *prevertexId,int *DFSA_tour);
void DFS_B(struct edgeHashTable *edgeHash,int *DFSB_tour);
int dfsacost;
int dfsbcost;
int nearestneighbourcost;
int optdfsacost;
int optdfsbcost;
int optnearestneighbourcost;

#endif
