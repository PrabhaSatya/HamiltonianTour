#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "nearest_neighbour.h"

void nearest_neighbour(struct edgeHashTable *edgeHash, int v,int *nearneighbour) {
	
	struct Edge newEdge, prevEdge, *temp;
	prevEdge.weight = 0;
	int count = 0,i,j,n;
	int visited[typeA];
	for(i = 0; i < typeA; i++) {
		visited[i] = 0;
	}
	if(edgeHash == NULL) {
		return;
	}
	visited[v] = 1;
	nearneighbour[count] = v;
	count++;
	int flag1, p = -1;
	while(count < typeA) {
		//printf("\nCount: %d\n",count);
		p = -1,flag1 = 0;
		//flag1 = flag2 = 0;
			for(j = 0;j < typeA; j++) {
				if(visited[j] == 1)
					continue;
				newEdge.vertexId1 = v;
				//printf("\n newEdge.vertexId1= %d\n",v);
				newEdge.vertexId2 = j;
				//printf("\n newEdge.vertexId2= %d\n",j);
				n = j;
				temp = edgeHashSearch(edgeHash, &newEdge);
				if((temp != NULL) && (flag1 == 0)){
					flag1 = 1;
					p = j;
					newEdge.weight = temp->weight;	
					//printf("\n first if!\n p = %d",j);
					continue;
					//prevEdge.weight = newEdge.weight;
						
				}	
				if((temp != NULL) && (flag1)) {
					if(temp->weight < newEdge.weight) {
						newEdge.weight = temp->weight;
						p = j;
						//printf("\n second if!\n p = %d",j);
						continue;
					}	
				}
			
			}
			if(p == -1) {
				
				newEdge.weight = b_weight;
				visited[n] = 1;
				v = n;
				nearneighbour[count] = n;
				//printf("\np == -1!!\n ");
				//printf("\nIn nearneighbour[]= %d\n",n);
				count++;
				
			}	
				
			else {
				visited[p] = 1;
				v = p;
				nearneighbour[count] = p;
				//printf("\nIn nearneighbour[]= %d\n",p);
				count++;
			}	
			
			
	}			
	
	

}
