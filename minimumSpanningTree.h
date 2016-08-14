#include "graph.h"
#include "malloc.h"
#include "DFS.h"
struct setNode
{	int vertexId;
	int rank;
	struct setNode *parent;
};
struct spanningedge
{	
    struct Edge edge;
	struct spanningedge* next;
};	
int sweight;
int nexcludededges;
struct setNode* findset(struct setNode *v);
int sunion(struct setNode *u,struct setNode *v);
struct setNode* makeset(int vertexId);
struct spanningedge **minSpanningTreeEdges;
int buildMinSpanningTree(struct Edge *sortedEdgeList, struct spanningedge **minSpanningTreeEdges, struct Edge *excludededges,struct adjvertex** adjlist);


