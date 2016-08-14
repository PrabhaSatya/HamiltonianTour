#ifndef LLIST_H
#define LLIST_H
#include "graph.h"

#include"hash.h"

//structure for linkedlist
struct llEdgeNode
{
	struct Edge *edgeInfo;
	struct llEdgeNode *next;
};

//structure for linkedlist
struct llVertexNode
{
	struct Vertex *vertexInfo;
	struct llVertexNode *next;
};

int getWeight(int vertexId1,int vertexId2,struct edgeHashTable * edgeHash);
/*Insert the Type A edge in linked list. Return 0 on success and -1 on failure*/
int llEdgeInsert(struct llEdgeNode **head,struct Edge *edgeData);

/*Return the node of the linked list containing the key. If not fonud, return NULL*/
struct Edge * llGetEdge(struct llEdgeNode *head,struct Edge *key); 


/*Insert the Type A edge in linked list. Return 0 on success and -1 on failure*/
int llVertexInsert(struct llVertexNode **head,struct Vertex *vertexData);


/*Return the node of the linked list containing the key. If not found, return NULL*/
struct Vertex * llGetVertex(struct llVertexNode *head,char *vertexName); 

#endif
