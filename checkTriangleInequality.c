#ifndef CTI_H
#define CTI_H
#include"checkTriangleInequality.h"
#include"main.h"
#include<stdio.h>


extern int numVertices;
extern int b_weight;
extern int typeA;


int checkTriangleInequality(struct Edge *sortedEdgeList,struct edgeHashTable *edgeHash)
{ 
  // printf("\n Entering Triangle inequality nw!!");
   struct Edge *Sorted;
  int v1,v2,v3;
  int w1,w2,w3;
  int j=0;
  int find=0;
  int i;
  struct Edge *newEdge;//= (struct Edge *)malloc(sizeof(struct Edge));
  //struct Edge *newEdge2= (struct Edge *)malloc(sizeof(struct Edge));
  struct Edge *temp;//,*temp2;
  Sorted=sortedEdgeList;

	//printf("Entering Triangle inequality nw!!");
  while(j < edgeHash->edge_count)
  {//6
  //printf("\n entering while loop \n");

  w1=Sorted[j].weight;
  v1=Sorted[j].vertexId1;
  v2=Sorted[j].vertexId2;
  //printf("\nv1 id: %d \t v2 id: %d\n",v1,v2);
	  for(i=0;i<numVertices;i++)
	  {//5
            v3=i;
	    //printf("\n %d \t %d \t %d",v1,v2,v3); 
	    	
		//if(vertices[i]!=NULL)
	        //{//3
		        //printf("%d     %s\n",i,vertices[i]);
		        if(i>=typeA)
		        {//4
			        w2=b_weight;
			        w3=b_weight;
		        }//4		
		//printf("\n if cond satisfied");
		//}//3
		else
		{//2		
			if(v1!=v3 && v2!=v3)
	    		{//1		
				newEdge= (struct Edge *)malloc(sizeof(struct Edge));
				if(v1<v3){
				newEdge->vertexId1=v1;
			        newEdge->vertexId2=v3;
	        		newEdge->weight=0;
				}
				else{
				newEdge->vertexId1=v3;
			        newEdge->vertexId2=v1;
	        		newEdge->weight=0;
				}

				temp=edgeHashSearch(edgeHash,newEdge);
				if(temp==NULL)
        			w2=b_weight;
                	        else
			        w2=temp->weight;
				if(v2<v3){
				newEdge->vertexId1=v2;
			        newEdge->vertexId2=v3;
	        		newEdge->weight=0;
				}
				else
				{
				newEdge->vertexId1=v3;
			        newEdge->vertexId2=v2;
	        		newEdge->weight=0;
				}   			
			        temp=edgeHashSearch(edgeHash,newEdge);
   				if(temp==NULL)
			        w3=b_weight;
        			else
        			w3=temp->weight;
        			//printf("\nv1: %s\tv2 %s \tv3 %s\n",vertices[v1],vertices[v2],vertices[v3]);
        			//printf("\nw1: %d\tw2 %d \tw3 %d\n",w1,w2,w3);
	        		find=check(w1,w2,w3);
      				//if(find==1)
				//{
				//printf("\nThese vertices cannot form a triangle: ");
				//printf("\n%s %s %s\n",vertices[v1],vertices[v2],vertices[v3]);      				
				//return 1;
				//}
        		}//1
        	}//2
        }//5       
   
     // printf("\n");
      j++;
    }//6
    return 0;
}

int check(int a,int b,int c)
{
if(((a+b)<c) || ((b+c)<a) || ((a+c)<b))
return 1;
else
return 0;
}



#endif
