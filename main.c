#include "main.h"
#define BUFLEN 200

extern int typeA;
extern int nexcludededges;
extern int numVertices;
int main(int argc, char *argv[])
 {
	if(argc != 2)
	 {
		printf("Usage:\n\t%s <input-file>\n", argv[0]);
		exit(1);
	}
		struct vertexHashTable *vertexHash = (struct vertexHashTable *)malloc(sizeof(struct vertexHashTable));//vertex structure
	struct edgeHashTable *edgeHash = (struct edgeHashTable *)malloc(sizeof(struct edgeHashTable));//edgehash structure

	vertexHashInit(vertexHash); //calling the Vertex Initialisation 
	edgeHashInit(edgeHash);	   //Calling the Edge Initialisation
	parseInputDescription(argv[1], vertexHash, edgeHash);	//Calling the ParseInput Description
	
	//Declaration of variables
	int *prevertexId;
	char *color;
	int top = -1;		
	int i=0,m=0;
	int count, n = 1,nomst=0;
	int flag, flag1 = 0; 
	int v1,v2,choice,c,t=0;
	//Declaring structures

	struct Edge*  tedges;
	struct nvertex *tnvertices;
	struct adjvertex  **adjlist;				//adjacent list structure
	struct Edge *excludededges;				//excluded edges structure
    	struct spanningedge **minSpanningTreeEdges,*temp1; 
	int *DFSB_tour;
	DFSB_tour=(int *)malloc(numVertices*(sizeof(int)));
	int *DFSA_tour;
	DFSA_tour=(int *)malloc(numVertices*(sizeof(int)));
	int *nearneighbour;
	nearneighbour=(int *)malloc(numVertices*(sizeof(int)));
		
	struct Edge*  tedges2;
	struct nvertex *tnvertices2;
	tedges2=(struct Edge *)(malloc((numVertices)*sizeof(struct Edge)));
	tnvertices2=(struct nvertex*)(malloc((numVertices)*sizeof(struct nvertex))); 
	struct Edge*  tedges1;
	struct nvertex *tnvertices1;
	tedges1=(struct Edge *)(malloc((numVertices)*sizeof(struct Edge)));
	tnvertices1=(struct nvertex*)(malloc((numVertices)*sizeof(struct nvertex))); 
		
							     //spanning edge structure
	
	//Memory allocation for the variable

	adjlist=(struct adjvertex **)(malloc((numVertices)*sizeof(struct adjvertex *))); //memory allocation for adjaceny list
	excludededges=(struct Edge *)(malloc((numEdges)*sizeof(struct Edge)));           //memory  allocation for excluded edges
	color=(char *)(malloc(numVertices*(sizeof(char)))); 				//memory allocation for 
	prevertexId=(int *)(malloc(numVertices*(sizeof(int))));				//
	stack = (int *)malloc(numVertices*sizeof(int));  				//
	tedges=(struct Edge *)(malloc((numVertices)*sizeof(struct Edge)));		//
	tnvertices=(struct nvertex*)(malloc((numVertices)*sizeof(struct nvertex))); 	//

		
	if(edgeHash->edge_count != 0)
	 {

	    	int a = heapsort(edges, edgeHash->edge_count);  //Calling the Heap Sort function
	    
    	}
    	if (NULL == (minSpanningTreeEdges=(struct spanningedge **)(malloc((numVertices)*sizeof(struct spanningedge*))))) //allocation of memory for spanning edge
	{
	        printf("\nmalloc cannot be done!");
	}
	flag=buildMinSpanningTree(edges,minSpanningTreeEdges,excludededges,adjlist);//calling the function to Build minimum spanning tree
		if(flag==-1) nomst=1;
		//Calling the DFS
	if(!nomst) 
	{	DFS(adjlist,color,prevertexId,DFSA_tour);	//Calling the DFS
		for(i=0;i<numVertices;i++)
		{	v1=DFSA_tour[i];
			if(i!=numVertices-1)	 		
			v2=DFSA_tour[i+1];
			else
			v2=DFSA_tour[0];	
			dfsacost=dfsacost+getWeight(v1,v2,edgeHash);
	
		}
		arr2ds(DFSA_tour,edgeHash,tedges,tnvertices);	
		optdfsacost=Aoptheuristic(tedges,tnvertices,edgeHash);
	} 
	DFS_B(edgeHash,DFSB_tour);
	arr2ds(DFSB_tour,edgeHash,tedges2,tnvertices2);
	Boptheuristic(tedges2,tnvertices2,edgeHash);
	for(i=0;i<numVertices;i++)
	{		v1=DFSB_tour[i];	
			if(i!=numVertices-1)	 		
			v2=DFSB_tour[i+1];
			else
			v2=DFSB_tour[0];
			
		dfsbcost=dfsbcost+getWeight(v1,v2,edgeHash);
	}
	nearest_neighbour(edgeHash,0,nearneighbour);
		for(i=0;i<numVertices;i++)
	 	{	v1=nearneighbour[i];
			if(i!=numVertices-1)	 		
			v2=nearneighbour[i+1];
			else
			v2=nearneighbour[0];
			
		nearestneighbourcost=nearestneighbourcost+getWeight(v1,v2,edgeHash);
	}

	arr2ds(nearneighbour,edgeHash,tedges1,tnvertices1);
	optnearestneighbourcost=Aoptheuristic(tedges1,tnvertices1,edgeHash);
	    	
		
		while(1)
		{
		printf("\n==============================");
		printf("\n    Enter your Choice       \n");
		printf("==============================\n");
		
		printf("\t0) Exit\n\n");
		printf("\t1) Vertex Names\n\n");
		printf("\t2) Vertex Ids\n\n");
		printf("\t3) Hash table\n\n");
		printf("\t4) Heap sort\n\n");
		printf("\t5) Minimum Spanning Tree\n\n");
		printf("\t6) Triangular Inequality\n\n");
		printf("\t7) Type A graph tour\n\n");		
		printf("\t8) Type B graph tour\n\n");
		printf("\t9) Nearest neighbour graph tour\n\n");
		printf("ENTER YOUR CHOICE (0-9): ");
				
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 0: //Exit
				flag=0;
				exit(1);

			case 1: //Vertex Names
				    printf("\nPrinting vertex Names: \n");
				    struct llVertexNode * temp;
				    for(m = 0; m < MAXBUCKETS; m++) 
				    {
        			   if(vertexHash->buckets[m] != NULL) 
				    	{
        			    		temp = vertexHash->buckets[m];
        			    		while(temp != NULL) 
						       {
        			    			  puts((temp->vertexInfo)->vertexName);
			            			  temp = temp->next;
					            	}

				    	}
				   }
    

				break;
			
			case 2: //Vertex Ids
				printf("\nPrinting vertex Ids: \n");
				//    struct llVertexNode * temp;
				    for(m = 0; m < MAXBUCKETS; m++) 
				    {
        			    	if(vertexHash->buckets[m] != NULL) 
				    	{
        			    		temp = vertexHash->buckets[m];
        			    		while(temp != NULL) 
						       {
        			    			  printf("%d  ", (temp->vertexInfo)->vertexId);
						          //puts((temp->vertexInfo)->vertexName);
			            			  temp = temp->next;
					            	}

				    	}
				   }		 
				break;
			
			case 3: //Hash Table
				printf("\nPrinting vertex hash table: \n");
				   // struct llVertexNode * temp;
					    for(m = 0; m < MAXBUCKETS; m++) 
					   {
					        if(vertexHash->buckets[m] != NULL) 
						{
					            temp = vertexHash->buckets[m];
					            while(temp != NULL) 
							{
						                printf("%d  ", (temp->vertexInfo)->vertexId);
						                puts((temp->vertexInfo)->vertexName);
						                temp = temp->next;
						         }
        					}
    					  }       
    
    				if(edgeHash->edge_count != 0) {
			        printf("\nPrinting edge hash table: \n");
			        struct llEdgeNode * temp2;
			        for(m = 0; m < MAXBUCKETS; m++) 
				{
				        if(edgeHash->buckets[m] != NULL) 
					{
				          
					                temp2 = edgeHash->buckets[m];
					                while(temp2 != NULL) 
							{
						                printf("%s  ", getVertexName((temp2->edgeInfo)->vertexId1));
					                        printf("%s  ", getVertexName((temp2->edgeInfo)->vertexId2));
						                printf("%d\n", (temp2->edgeInfo)->weight);
						                temp2 = temp2->next;
                					}
            				}
        			} 
    						
				break;
			
			case 4: 
				 printf("\nHeapsort done!\n\n");
				 printf("Printing sorted edges from heapsort: \n");
    				 printf("numEdges: %d\n", numEdges);
				int f;
	
				for(f=0; f < numEdges; f++)
			        printf("%s \t %s \t%d\n",getVertexName(edges[f].vertexId1), getVertexName(edges[f].vertexId2), edges[f].weight);
				break;
			
			case 5: //Minimum Spanning Tree
				
				printf("\n...............spanning tree edges................\n");
				if(flag!=-1&&(numVertices==typeA))
				{	printf("Minimum Spanning Tree  constructed\n");		
				temp1=minSpanningTreeEdges[flag];
				while(temp1!=NULL)
				{
		
					printf("%s \t%s \t%d \n",vertices[temp1->edge.vertexId1],vertices[temp1->edge.vertexId2],temp1->edge.weight);
					temp1=temp1->next;
				}
				printf("cost of the spanning tree is %d\n",sweight);
				nexcludededges=numEdges-typeA+1;
				printf("number of excluded edges:%d\n",nexcludededges);
				if(nexcludededges!=0)	
				{	
					printf("excludededges are:\n");
					for(i=0;i<nexcludededges;i++)
					printf("%s \t%s \t%d \n",vertices[excludededges[i].vertexId1],vertices[excludededges[i].vertexId2],excludededges[i].weight);
				}
	
		
				}	
				else 
				{	
				printf("Minimum Spanning Tree not constructed\n");
				
				printf("connected components\n");
				for(i=0;i<typeA;i++)
				{	
					count=0;
					temp1=minSpanningTreeEdges[i];
					while(temp1!=NULL)
					{	
						if(count==0)
						{	printf("component %d\n",n++);
						}
					printf("%s \t%s \t%d \n",vertices[temp1->edge.vertexId1],vertices[temp1->edge.vertexId2],temp1->edge.weight);
					temp1=temp1->next;count++;
					}
				}
		
			}	
			break;
			
			case 6: //Triangle Inequality
				c= checkTriangleInequality(edges, edgeHash);
    				if(c == 0)
					printf("\nTriangle inequality satisfied.\n");
				else
					printf("\nTriangle inequality not satisfied.\n");
				break;
		
			case 7:// Type A DFS
					if(nomst==1)
					{
						printf("Since MST is not constructed DFS is not done for Type A\n ");
					}
					else 
					{
						printf("\n\nDFS Traversal of Type A\n");
						printf("\n\n");
						for(i=0;i<numVertices;i++)
						{
							printf("%s -> ",vertices[DFSA_tour[i]]);		
						}
						printf("%s",vertices[0]);
						printf("cost of the DFS A tour %d:\n",dfsacost);
											
						for(i=0;i<numVertices;i++)
						{v1=tnvertices[t].vertexId;
						printf("%s->",vertices[v1]);
						t=tnvertices[t].neighborid2;
						}
						printf("%s",vertices[tnvertices[0].vertexId]);
						printf("cost of the DFS A tour after 2opt %d:\n",optdfsacost);						
					}	
					break;
			case 8://Type B DFS
					printf("\nDFS traversal of Type B\n\n");
											
						printf("\n\n");
						for(i=0;i<numVertices;i++)
						{
							printf("%s -> ",vertices[DFSB_tour[i]]);		
						}
						printf("%s",vertices[DFSB_tour[0]]);
						printf("\ncost of the DFS B tour %d:\n",dfsbcost);
											
						for(i=0;i<numVertices;i++)
						{v1=tnvertices2[t].vertexId;
						printf("%s->",vertices[v1]);
						t=tnvertices2[t].neighborid2;
						}
						printf("%s",vertices[tnvertices2[0].vertexId]);
						
						printf("\ncost of the DFS B tour after 2opt :%d\n",optdfsbcost);						
					
					break;
			case 9:	
						printf("\nnearest neighbor traversal \n\n");
											
						printf("\n\n");
						for(i=0;i<numVertices;i++)
						{
							printf("%s -> ",vertices[nearneighbour[i]]);		
						}
						printf("%s",vertices[nearneighbour[0]]);
						printf("\ncost of the nearest  neighbour tour %d:\n",nearestneighbourcost);
													
						for(i=0;i<numVertices;i++)
						{v1=tnvertices1[t].vertexId;
						printf("%s->",vertices[v1]);
						t=tnvertices1[t].neighborid2;
						}
						printf("%s",vertices[tnvertices1[0].vertexId]);
						
						printf("\ncost of the nearest neighbour tour after 2optd:%d\n",optnearestneighbourcost);						
					
					break;
			
			default : break;
			}
		}
	}
	}

