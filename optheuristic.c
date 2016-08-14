#include"optheuristic.h"
#include"graph.h"
#include"hash.h"
#include"DFS.h"
#include"llist.h"
#include<stdio.h>
#include<stdlib.h>
void arr2ds(int *tour,struct edgeHashTable* edgeHash,struct Edge *tedges,struct nvertex  *tnvertices)
{
	int i,k=0;

	int p;

	int prev;
	prev=tour[numVertices-1];
	for(i=0;i<numVertices;i++)
	{	p=tour[i];
		tnvertices[p].vertexId=tour[i];
		tnvertices[p].neighborid1=prev;
		
		//*tnvertices[p].neighborid2=tour[0];
		if(i!=(numVertices-1))
		
			tnvertices[p].neighborid2=tour[i+1];
		
		else
			tnvertices[p].neighborid2=tour[0];
		
		prev=tour[i];
	}
	struct Edge *temp1,*temp2;
	temp1=(struct Edge*)malloc(sizeof(struct Edge));
	temp2=(struct Edge*)malloc(sizeof(struct Edge));
	k=0;
	for(i=0;i<numVertices-1;i++)
	{	if(k!=numVertices-1)
		{	
		temp1->vertexId1=tour[k];
		temp1->vertexId2=tour[k+1];
		temp1->weight=0;
		tedges[i].vertexId1=tour[k];
		tedges[i].vertexId2=tour[k+1];
		temp2=edgeHashSearch(edgeHash,temp1);
		if(temp2!=NULL)	
		{		
			tedges[i].weight=temp2->weight;
		}
		else
			tedges[i].weight=b_weight;
		k++;
		}
	}
	temp1->vertexId1=tour[numVertices-1];
	temp1->vertexId2=tour[0];
	temp1->weight=0;
	tedges[i].vertexId1=tour[numVertices-1];
	tedges[i].vertexId2=tour[0];
	temp2=edgeHashSearch(edgeHash,temp1);
	if(temp2!=NULL)	
		{		
			tedges[i].weight=temp2->weight;
		}
		else
		{	tedges[i].weight=b_weight;
		}
}
void exchange(struct nvertex *tnvertices,int v1,int v2,int in2,int jn2)
{	int t,dummy;
	tnvertices[v1].neighborid2=v2;
	tnvertices[jn2].neighborid1=in2;
	t=tnvertices[v2].neighborid1;
	tnvertices[v2].neighborid1=v1;
	tnvertices[v2].neighborid2=t;
	while(t!=in2)
	{
	dummy=tnvertices[t].neighborid1;
	tnvertices[t].neighborid1=tnvertices[t].neighborid2;
	tnvertices[t].neighborid2=dummy;
	t=tnvertices[t].neighborid2;
        }
	tnvertices[in2].neighborid1=tnvertices[in2].neighborid2;
	tnvertices[in2].neighborid2=jn2;
	//printf("yes1");
	//int p;	
	//for(p=0;p<numVertices;p++)
	 //printf("\n%s\t%s\t%s\n",vertices[p],vertices[tnvertices[p].neighborid1],vertices[tnvertices[p].neighborid2]);
	
}
void BtoA(struct Edge *tedges,struct nvertex *tnvertices,struct edgeHashTable *edgeHash)
{		
	int j,i,v1,v2,in1,in2,jn1,jn2,w1,w2,tw1,tw2,flag=1,t,dummy,t1;
	
	for(i=0;i<numVertices;i++)
	{	v1=tnvertices[i].vertexId;
		in1=tnvertices[i].neighborid1;
		in2=tnvertices[i].neighborid2;
		w1=getWeight(v1,in2,edgeHash);	
		for(j=0;j<numVertices;j++)
		{     	
			v2=tnvertices[j].vertexId;
			jn1=tnvertices[j].neighborid1;
			jn2=tnvertices[j].neighborid2;	
			if(v2!=v1&&v2!=in2&&jn2!=v1&&jn2!=in2)
			{	w2=getWeight(v2,jn2,edgeHash);
				tw1=getWeight(v1,v2,edgeHash);
				tw2=getWeight(in2,jn2,edgeHash);
				/*printf("%s\t%s\t%d\t%s\t%s\t%d\t%s\t%s\t%d\t%s\t%s\t%d\n",vertices[v1],vertices[in2],w1,vertices[v2],vertices[jn2],w2,vertices[v1],vertices[v2],tw1,vertices[in2],vertices[jn2],tw2);*/
				if((w1==b_weight&&w2==b_weight)&&(tw1!=b_weight||tw2!=b_weight))
				{	flag=1;
					exchange(tnvertices,v1,v2,in2,jn2);
					break;
				}
				else if((w1==b_weight&&w2!=b_weight)||(w1!=b_weight&&w2==b_weight))
				{   
					if(tw1!=b_weight&&tw2!=b_weight)
					{  exchange(tnvertices,v1,v2,in2,jn2);
						flag=1;
						break;
					}
					else if((tw1==b_weight&&tw2!=b_weight)||(tw1!=b_weight&&tw2==b_weight))
					{	if((w1+w2)>(tw1+tw2))
						{exchange(tnvertices,v1,v2,in2,jn2);						
						flag=1;
						break;
					        }
					}
//					else{ }	

				}
//				else {}
			}
			
			}
		}

		
	}
void AtoB(struct Edge *tedges,struct nvertex *tnvertices,struct edgeHashTable *edgeHash)
{		
	int j,i,v1,v2,in1,in2,jn1,jn2,w1,w2,tw1,tw2,flag=1,t,dummy,t1;
	
	for(i=0;i<numVertices;i++)
	{	v1=tnvertices[i].vertexId;
		in1=tnvertices[i].neighborid1;
		in2=tnvertices[i].neighborid2;
		w1=getWeight(v1,in2,edgeHash);	
		for(j=0;j<numVertices;j++)
		{     	
			v2=tnvertices[j].vertexId;
			jn1=tnvertices[j].neighborid1;
			jn2=tnvertices[j].neighborid2;	
			if(v2!=v1&&v2!=in2&&jn2!=v1&&jn2!=in2)
			{	w2=getWeight(v2,jn2,edgeHash);
				tw1=getWeight(v1,v2,edgeHash);
	/*			tw2=getWeight(in2,jn2,edgeHash);
				printf("%s\t%s\t%d\t%s\t%s\t%d\t%s\t%s\t%d\t%s\t%s\t%d\n",vertices[v1],vertices[in2],w1,vertices[v2],vertices[jn2],w2,vertices[v1],vertices[v2],tw1,vertices[in2],vertices[jn2],tw2);*/
				if((w1!=b_weight&&w2!=b_weight)&&(tw1==b_weight||tw2==b_weight))
				{	flag=1;
					exchange(tnvertices,v1,v2,in2,jn2);
					break;
				}
				else if((w1==b_weight&&w2!=b_weight)||(w1!=b_weight&&w2==b_weight))
				{   
					if(tw1==b_weight&&tw2==b_weight)
					{  exchange(tnvertices,v1,v2,in2,jn2);
						flag=1;
						break;
					}
					else if((tw1==b_weight&&tw2!=b_weight)||(tw1!=b_weight&&tw2==b_weight))
					{	if((w1+w2)>(tw1+tw2))
						{exchange(tnvertices,v1,v2,in2,jn2);						
						flag=1;
						break;
					        }
					}
//				else{ }	

				}
//				else {}
			}
			
			}
		}

		
	}

void optimise(struct Edge *tedges,struct nvertex *tnvertices,struct edgeHashTable *edgeHash)
{
	int j,i,v1,v2,in1,in2,jn1,jn2,w1,w2,tw1,tw2,flag=1,t,dummy,t1;
	for(i=0;i<numVertices;i++)
	{	v1=tnvertices[i].vertexId;
		in1=tnvertices[i].neighborid1;
		in2=tnvertices[i].neighborid2;
		w1=getWeight(v1,in2,edgeHash);	
		for(j=0;j<numVertices;j++)
		{     	
			v2=tnvertices[j].vertexId;
			jn1=tnvertices[j].neighborid1;
			jn2=tnvertices[j].neighborid2;	
			if(v2!=v1&&v2!=in2&&jn2!=v1&&jn2!=in2)
			{	w2=getWeight(v2,jn2,edgeHash);
				tw1=getWeight(v1,v2,edgeHash);
				tw2=getWeight(in2,jn2,edgeHash);
				/*printf("%s\t%s\t%d\t%s\t%s\t%d\t%s\t%s\t%d\t%s\t%s\t%d\n",vertices[v1],vertices[in2],w1,vertices[v2],vertices[jn2],w2,vertices[v1],vertices[v2],tw1,vertices[in2],vertices[jn2],tw2);*/
				if((w1+w2)>(tw1+tw2)&&(tw1!=b_weight&&tw2!=b_weight))
				{	flag=1;
					exchange(tnvertices,v1,v2,in2,jn2);
						break;
	
					

				}
			}
		}

	
	}
}
int Aoptheuristic(struct Edge *tedges,struct nvertex *tnvertices,struct edgeHashTable *edgeHash)
{	BtoA(tedges,tnvertices,edgeHash);
	//printf("now optimising...\n");
        optimise(tedges,tnvertices,edgeHash);
        //printf("\n\n...............neighbors of vertices in the tour................");
	int i;
	//for(i=0;i<numVertices;i++)
	 //printf("\n%s\t%s\t%s\n",vertices[i],vertices[tnvertices[i].neighborid1],vertices[tnvertices[i].neighborid2]);
		
		int weight=0,t=0,in1,in2,w1,v1;
		for(i=0;i<numVertices;i++)
		{	v1=tnvertices[t].vertexId;
			in1=tnvertices[t].neighborid1;
			in2=tnvertices[t].neighborid2;
			w1=getWeight(v1,in2,edgeHash);
			weight=weight+w1;
			t=in2;	

		}
		return weight;

}
void Boptheuristic(struct Edge *tedges,struct nvertex *tnvertices,struct edgeHashTable *edgeHash)
{	AtoB(tedges,tnvertices,edgeHash);
        //printf("\n\n...............neighbors of vertices in the tour................");
	int i;
	//for(i=0;i<numVertices;i++)
	 //printf("\n%s\t%s\t%s\n",vertices[i],vertices[tnvertices[i].neighborid1],vertices[tnvertices[i].neighborid2]);
		
		int weight=0,t=0,in1,in2,w1,v1;
		for(i=0;i<numVertices;i++)
		{	v1=tnvertices[t].vertexId;
			in1=tnvertices[t].neighborid1;
			in2=tnvertices[t].neighborid2;
			w1=getWeight(v1,in2,edgeHash);
			optdfsbcost=optdfsbcost+w1;
			t=in2;	

		}
	//	printf("cost of dfsb after 2opt:%d\n",weight);

}


