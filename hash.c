#include <stdio.h>
#include "hash.h"
void edgeHashInit(struct edgeHashTable *edgeHash) 
{
	int i;
	for(i = 0; i < MAXBUCKETS; i++)
		edgeHash->buckets[i] = NULL;
	edgeHash->edge_count = 0;
}		

struct edgeHashTable *edgeHash;
/*Use your own hash function to calculate the hash value*/
int calcEdgeHash(struct Edge *edgeInfo) {
	int a = edgeInfo->vertexId1;
	int b = edgeInfo->vertexId2;
	/*if (a > b) {
		a = b;
		b = edgeInfo->vertexId1;
	}		*/
	char * s1 = getVertexName(a);
	char * s2 = getVertexName(b);
	unsigned int hash = 5381;
	int c;
	while(c = *s1++) {
		hash = (hash << 5 + hash) + c; /* hash*33 + c */
	}
	while(c = *s2++) {
		hash = (hash << 5 + hash) + c; /* hash*33 + c */
	}
	return (int) (hash % MAXBUCKETS);	
}

/*Insert the Type A edge in hash table. Return 0 on success and -1 on failure*/
int edgeHashInsert(struct edgeHashTable *edgeHash, struct Edge *data) {
	struct Edge * res = edgeHashSearch(edgeHash, data);
	if (res != NULL) {
	    if(res->weight != data->weight) {
	      res->weight = data->weight;
	      return 0;
	    }      
	    return -1;
	}    
	unsigned int h = calcEdgeHash(data);
	int r = llEdgeInsert(&(edgeHash->buckets[h]), data);
	edgeHash->edge_count++;
	numEdges++;
	return r;
}

/*Search for the given edge. If it is found return a pointer to the edge. If not found return NULL*/
struct Edge * edgeHashSearch(struct edgeHashTable *edgeHash,struct Edge *key) {
	int h;
	h = calcEdgeHash(key);
	struct llEdgeNode * head;
	if(edgeHash==NULL) printf("yes");
	head = edgeHash->buckets[h];
	struct Edge *res;
	res = llGetEdge(head, key);
	return res;
}


/*This function creates an array 'edges' of all the edge entries from the hash table. Return 0 on success and -1 on failure*/
//Need to allocate space for the array 'edges' before passing here
int getArray(struct edgeHashTable *edgeHash, struct Edge *edges) {
    int i, c = 0;
	for (i = 0; i < MAXBUCKETS; i++) {
		struct llEdgeNode *t = edgeHash->buckets[i]; 
		if (t == NULL)
			continue;
		while (t != NULL) {
			edges[c].vertexId1 = (t->edgeInfo)->vertexId1;
			edges[c].vertexId2 = (t->edgeInfo)->vertexId2;
			edges[c].weight = (t->edgeInfo)->weight;
			c++;
			t = t->next;
		}	
	}
	if (c != edgeHash->edge_count)
		return -1;
	return 0;
}











