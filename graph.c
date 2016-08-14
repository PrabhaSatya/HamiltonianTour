#include "graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//struct Edge *edges;
#define BUFLEN 200
int numVertices;
int numEdges;
int b_weight;
int typeA;

int parseInputDescription(char *inputFileName, struct vertexHashTable *vertexHash, struct edgeHashTable *edgeHash) {
	char numbers[] = "0123456789";
	
	

	char line[BUFLEN];
	FILE *fp = fopen(inputFileName, "r");
	if(fp!=NULL) 
	{
		if(fgetc(fp) == EOF) {
	    printf("Error...File is empty!\n");
	    exit(1);
		} 
		fseek(fp,0,0);   
		fgets(line, 30, fp);
	int num=0;
	char *token;
	const char delim[]=" ,:()";
	int	i=0;
	token=strtok(line,delim);
	if(strcmp(token,"num_vertices")!=0)
	{	printf("error ..............missing num_vertices");
		exit(1);
	}fseek(fp,0,0);
	 fgets(line,80,fp);
	while(line[i]!=':')
	i++;
	i++;
	while(line[i]!='\n')
	{	if(isdigit(line[i]))
		{num=num*10+(line[i]-'0');}
		i++;
	}
	if(num==0)
	{	printf("error........value of num_vertices missing");
		exit(1);
	}
	numVertices=num;
//	printf("total number of vertices %d\n",numVertices);
	
	
	int j;
	vertices= (char **)malloc(sizeof(char *)*numVertices);
	for(j = 0;j < numVertices; j++)
	    vertices[j] = (char *)malloc(30);
	 i = 0;
	struct Vertex *vertex = (struct Vertex *)malloc(sizeof(struct Vertex));
	struct Edge *edge = (struct Edge *)malloc(sizeof(struct Edge));
	
	
	
	
	int flag1 = 0, flag2 = 0, flag3 = 0;
	while (1) 
	{
		fgets(line, 30, fp);
		if (strchr(line, ':') != NULL) 
			{
		        flag3 = 1;
		        if (strcspn(numbers, line) >10)
			 {
		            flag1 = 1;
			        break;
			    }   
			    else
			        break; 
			}	
	    	if (fgetc(fp) == EOF) 
		{
	        flag2 = 1;
	        break;
	   		 }    
		char *s = strtok(line, "( )");
	
		strcpy(vertex->vertexName, s);
		vertex->vertexId = i;
		
		int res = vertexHashInsert(vertexHash, vertex);
		if (res == 0) {
	
		    strcpy(vertices[i], s);
		    i++;
		}
		edge->vertexId1 = getVertexId(vertexHash, vertex->vertexName);    
		s = strtok(NULL, "( )");
	
		if (strspn(s, numbers) != 0) {
		    printf("A vertex name is missing in type A field!\n");
		    exit(1);
		}
		    
		//printf("%s \n", s);
		//strcpy(vertices[i], s);
		strcpy(vertex->vertexName, s);
		vertex->vertexId = i;
		res = vertexHashInsert(vertexHash, vertex);
		
		if (res == 0) {
		    //printf("Successfully inserted above vertex\n");
		    strcpy(vertices[i], s);
		    i++;
		}  
		edge->vertexId2 = getVertexId(vertexHash, vertex->vertexName);   
		s = strtok(NULL, "( )");
		//printf("Hey this is edge weight! %s\n",s);
		//if (strchr(line, ':') != NULL) {
	        if (strcspn(numbers, s) >= 10) {
	            printf("Error...weight of type A edge missing!\n");
	            exit(1);
	        }    
	    //}
	    //else {
	      //printf("Error...weight of type A edge missing!\n");
	      //exit(1);  
	   // }
		//if(strcspn(numbers, s) == 0) {
		   //printf("Weight of type A edge missing!\n"); 
		  // exit(1);
		//}
		//printf("%s \n", s);
		int w = atoi(s);
		//printf("Edge weight: %d",w);
		edge->weight = w;
		int t;
		if(edge->vertexId1 > edge->vertexId2) {
	        t = edge->vertexId1;
	        edge->vertexId1 = edge->vertexId2;
	        edge->vertexId2 = t;
	    }
		int r = edgeHashInsert(edgeHash, edge);
	}//end of while loop
	
	if((flag2) && (!flag3)) {
	    printf("Error...Whole line of Type B edge weight field missing!\n");
	    exit(1);
	}
	if((flag3) && (flag1)) {
	    printf("Error...value of Type B edge weight field missing!\n");
	    exit(1);
	}
	
	//FILLING THE "EDGES" ARRAY	
	edges = (struct Edge *)malloc((edgeHash->edge_count)*sizeof(struct Edge));
	int g = getArray(edgeHash, edges);
	
	int m, n;
	
	
	//PRINTING "EDGES" ARRAY
    
        //    printf("Printing edges array... \n");
	        if(edgeHash->edge_count == 0) 
		{
		  printf("\nIt is empty, there are no type A edges.\n");
			exit(1);
		}//GETTING LAST LINE OF FILE, TYPE B VERTICES WEIGHT
	char *typeB = strtok(line, ": ");
	typeB = strtok(NULL,": ");
	typeB = strtok(NULL,": ");
	
	    
	b_weight = atoi(typeB);
	if(b_weight==0) 
	{	printf("error.......... type B edge weight missing");
		exit(1);
	}
	typeA = i;
	int no_b = numVertices - i;

}	
	else{ printf("file not found");
		exit(1);
		}
} 
    



   
