#ifndef HASH_H
#define HASH_H

#include "llist.h"

#define MAXBUCKETS 100

//structure for hash table for edges.
struct edgeHashTable
{
    int edge_count;
	struct llEdgeNode *buckets[MAXBUCKETS];
};

struct edgeHashTable *edgeHash;
/*Allocate the memory and initialize the hash table.*/
void edgeHashInit(struct edgeHashTable *edgeHash);

/*Use your own hash function to calculate the hash value*/
int calcEdgeHash(struct Edge* edgeInfo);

/*Insert the Type A edge in hash table. Return 0 on success and -1 on failure*/
int edgeHashInsert(struct edgeHashTable *edgeHash, struct Edge *data);

/*Search the given edge. If it is found return a pointer to the edge. If not found return NULL*/
struct Edge * edgeHashSearch(struct edgeHashTable *edgeHash, struct Edge *key);


/*This function creates an array 'edges' of all the edge entries from the hash table. Return 0 on success and -1 on failure*/
int getArray(struct edgeHashTable *edgeHash, struct Edge *edges);

#endif
