#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "DFS.h"
#include "stack.h"
#include"graph.h"
int k=0;

void DFS_visit(struct adjvertex** adjlist,char *color,int* prevertexId,int i,int *DFSA_tour)
{	
	color[i]='G';
	DFSA_tour[k]=i;
//	printf("\n%s",vertices[DFSA_tour[k]]);
	k++;
	int j;
	struct adjvertex* atemp;
	atemp=adjlist[i];
	while(atemp!=NULL)
	{	if(color[atemp->vertexId]=='W')
		{	prevertexId[atemp->vertexId]=i;
			DFS_visit(adjlist,color,prevertexId,atemp->vertexId,DFSA_tour);	
			
		}
		atemp=atemp->next;
	}
	color[i]='B';
	
	
}
void DFS(struct adjvertex **adjlist,char *color,int *prevertexId,int *DFSA_tour)
{	
	int i;
	//printf("\n\nDFS Traversal of Type A\n");
	for(i=0;i<numVertices;i++)
	{color[i]='W';
	 prevertexId[i]=-1;
	}
	for(i=0;i<numVertices;i++)
		{
		if(adjlist[i]!=NULL)
		if(color[i]=='W')
			
			DFS_visit(adjlist,color,prevertexId,i,DFSA_tour);
		}
}



void DFS_B(struct edgeHashTable *edgeHash,int *DFSB_tour) {
	int count = 0;
	int i = 0, popped,present;
	struct Edge newEdge;
	//int DFS_ID[numVertices];
	
	int visited[numVertices];
	for(i = 0; i < numVertices; i++) 
		DFSB_tour[i] = visited[i] = 0;
		
	push(0);
	visited[0] = 1;
	while ((popped = pop()) != -1) {
		DFSB_tour[count] = popped;
		count++;
		present=popped;
		for( i = 0; i < numVertices; i++) {
			if((visited[i] == 1) || (i == popped))
				continue;
			newEdge.vertexId1 = popped;
			newEdge.vertexId2 = i;
			if(edgeHashSearch(edgeHash, &newEdge)== NULL) {
				visited[i] = 1;
				push(i);
				
			
			}	
				
					
		}	
	}
/*	printf("count:%d",count);
	printf("\nDFS traversal of Type B\n\n");
	for(i = 0;i < count; i++) {

		printf("%s\n",vertices[DFSB_tour[i]]);
	}
*/
}
	

