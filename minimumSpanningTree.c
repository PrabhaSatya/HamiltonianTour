#include<malloc.h>
#include<stdio.h>
#include<string.h>
#include "minimumSpanningTree.h"



struct setNode* findset(struct setNode *v)
{	
	if(v != v->parent)
	v->parent=findset(v->parent);
	return v->parent;
}
int sunion(struct setNode *uroot,struct setNode *vroot)
{
	if((uroot->rank)>(vroot->rank))
		{	vroot->parent=uroot;
			return 1;
		}
	else 
	{	uroot->parent=vroot;
		if((uroot->rank)==(vroot->rank))
		vroot->rank=vroot->rank+1;
		return 2;
	}
}
struct setNode* makeset(int vertexId)
{	struct setNode *new;
	new=(struct setNode *)malloc(sizeof(struct setNode));
	new->vertexId=vertexId;
	new->rank=0;
	new->parent=new;
	return new;
}


int buildMinSpanningTree(struct Edge *sortedEdgeList,struct spanningedge **minSpanningTreeEdges,struct Edge *excludededges,struct adjvertex** adjlist)
{
	int i,k=0,check,representative,append,ncomponents=0;	
	struct setNode  **stVertices,*u,*v,*uroot,*vroot;
	struct spanningedge *new,*temp;	
	struct adjvertex  *vtemp1,*vtemp2,*atemp,*prev;
	stVertices=(struct setNode**)(malloc((numVertices)*sizeof(struct setNode *)));
	for(i=0;i<numVertices;i++)
	stVertices[i]=makeset(i);
	for(i=0;i<numVertices;i++)
	adjlist[i]=NULL;
	for(i=0;i< numEdges;i++)
	{ 	u=stVertices[sortedEdgeList[i].vertexId1]; 
	  	v=stVertices[sortedEdgeList[i].vertexId2];
	  	uroot=findset(u);
	  	vroot=findset(v);
	  	if(uroot!=vroot)
		{			
			check=sunion(uroot,vroot);
			if(check==1)
			{	representative=uroot->vertexId;
			 	append=vroot->vertexId;
			}
			if(check==2)
			{	representative=vroot->vertexId;
				append=uroot->vertexId;
			}
			new=(struct spanningedge*)malloc(sizeof(struct spanningedge));
			new->edge.vertexId1=sortedEdgeList[i].vertexId1;
			new->edge.vertexId2=sortedEdgeList[i].vertexId2;
			new->edge.weight=sortedEdgeList[i].weight;
			sweight = sweight + sortedEdgeList[i].weight;
			new->next=minSpanningTreeEdges[append];
			minSpanningTreeEdges[append]=NULL;
			temp=minSpanningTreeEdges[representative];
			if(temp==NULL)
			minSpanningTreeEdges[representative]=new;
			else
			{	while(temp->next!=NULL)
				{temp=temp->next;}
				temp->next=new;
			}
			vtemp1=(struct adjvertex*)((malloc(sizeof(struct adjvertex))));
			vtemp1->vertexId=sortedEdgeList[i].vertexId1;
			vtemp1->next=NULL;
			vtemp2=(struct adjvertex*)((malloc(sizeof(struct adjvertex))));
			vtemp2->vertexId=sortedEdgeList[i].vertexId2;
			vtemp2->next=NULL;
			atemp=adjlist[sortedEdgeList[i].vertexId1];
			if(atemp==NULL)
				adjlist[sortedEdgeList[i].vertexId1]=vtemp2;
			else
			{	while(atemp->next!=NULL&&atemp->vertexId>vtemp2->vertexId)
				{	prev=atemp;
					atemp=atemp->next;
//					printf("in MST check1\n");
				}
				if(atemp->next==NULL)
				atemp->next=vtemp2;
				else 
				{	prev->next=vtemp2;
					vtemp2->next=atemp;
				}
			}
			atemp=adjlist[sortedEdgeList[i].vertexId2];
			if(atemp==NULL)
				adjlist[sortedEdgeList[i].vertexId2]=vtemp1;
			else
			{	while((atemp->next!=NULL)&&((atemp->vertexId)>(vtemp1->vertexId)))
				{	prev=atemp;
					atemp=atemp->next;
//					printf("in MST check2\n");
//					printf("%d\t%d",atemp->vertexId,vtemp1->vertexId);
				}
				if(atemp->next==NULL)
				atemp->next=vtemp1;
				else
				{	prev->next=vtemp1;
					vtemp1->next=atemp;
				}
			}
			
					
		}
		else 
		{	excludededges[k].vertexId1=sortedEdgeList[i].vertexId1;
			excludededges[k].vertexId2=sortedEdgeList[i].vertexId2;
			excludededges[k].weight=sortedEdgeList[i].weight;

			 k++;	
		}
	}
	nexcludededges = k;
	for(i=0;i<numVertices;i++)
	if(minSpanningTreeEdges[i]!=NULL)
	{	ncomponents++;representative=i;}
	if(ncomponents==1)
	return representative;
	else return -1;
}


