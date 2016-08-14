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

int parseInputDescription(char *inputFileName,struct vertexHashTable *vertexHash,struct edgeHashTable *edgeHash)
{	
	FILE *fp;
	int flag=1,i=0,l=0,j=0,f=0,Id1,Id2,num=0;
	struct vertex  *v1,*v2,*v;struct edge *e;
	char *token,line[80],check[]="num_vertices";
	char vertex1[30],vertex2[30],stemp[15];
	const char delim[]=" ,:()";
	fp=fopen(inputFileName,"r");
	if(fgetc(fp)==EOF) 
	{	printf("error:input file empty");
		exit(1);
	}
	fseek(fp,0,0);
	fgets(line,80,fp);
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
	printf("total number of vertices %d\n",numVertices);
	vertices=(char**)malloc(numVertices*sizeof(char *));
	for(i=1;i<=numVertices;i++)
	{	vertices[i]=(char*)(malloc(30));
	}
	
	while(fgets(line,80,fp))
	{	v1=(struct vertex *)(malloc(sizeof(struct vertex)));
		v2=(struct vertex *)(malloc(sizeof(struct vertex)));
		e=(struct edge *)(malloc(sizeof(struct edge)));
		token=strtok(line,delim);
		if(strcmp(token,"type")==0)
		{	 f=1;
			break;
		}
		strcpy(v1->vertexName,token);
	 	v1->vertexId=0;
		flag=vertexHashInsert(vertexHash,v1);
		//if(flag==-1) return -1;
		token=strtok(NULL,delim);
		if(token[0]!='v')
		{	printf("error.........vertex number is missing in an edge");
			exit(1);
		}
	 	strcpy(v2->vertexName,token);
	 	v2->vertexId=0;
		flag=vertexHashInsert(vertexHash,v2);
		//if(flag==-1) return -1;
		token=strtok(NULL,delim);
		Id1=getVertexId(vertexHash,v1->vertexName);
		Id2=getVertexId(vertexHash,v2->vertexName);
		if(Id1<Id2)
		{e->vertexId1=Id1;
		 e->vertexId2=Id2;
		}
		else
		{e->vertexId1=Id2;
		 e->vertexId2=Id1;
		}
		if(atoi(token)==0)
		{	printf("error......edge weight of a type A edge is missing");
			exit(1);
		}
		e->weight=atoi(token);
		
		flag=edgeHashInsert(edgeHash,e);
		//if(flag==-1) return -1;
	}
	if(f==0)
	{	 printf("error.......missing TYPE B edges");
		exit(1);
	}
	token=strtok(NULL,delim);
	token=strtok(NULL,delim);
	B_weight=atoi(token);
	if(B_weight==0)
	{	printf("error..........missing type B edge weight");
		exit(1);
	}
	
	if(Id==0)
	{	printf("error........edge list missing");
		exit(1);
	}
	i=Id;
	numAVertices=Id;
	while(i<numVertices)
	{	i++;
		sprintf(stemp,"dummy%d",i);
		v=(struct vertex *)(malloc(sizeof(struct vertex)));
		strcpy(v->vertexName,stemp);
	 	v->vertexId=0;
		flag=vertexHashInsert(vertexHash,v);
		
	
	}

}
	//gets(line,80,fp);
	//token = strtok(line,delim);
	if (strchr(line, ':') != NULL) {
	    if (strcspn(numbers, line) >10) {
	        printf("Error...value of num_vertices missing!\n");
	        exit(1);
	    }    
	}
	else {
	  printf("Error...whole line of num_vertices field missing!\n");
	  exit(1);  
	}
	  
	  
	char *a = strtok(line, ": ");
	a = strtok(NULL,": ");
		numVertices = atoi(a);
	
	int j;
	vertices= (char **)malloc(sizeof(char *)*numVertices);
	for(j = 0;j < numVertices; j++)
	    vertices[j] = (char *)malloc(30);
	int i = 0;
	struct Vertex *vertex = (struct Vertex *)malloc(sizeof(struct Vertex));
	struct Edge *edge = (struct Edge *)malloc(sizeof(struct Edge));
	
	
	
	
	int flag1 = 0, flag2 = 0, flag3 = 0;
	while (1) {
		fgets(line, 30, fp);
	
		
		if (strchr(line, ':') != NULL) {
		        flag3 = 1;
		        if (strcspn(numbers, line) >10) {
		            flag1 = 1;
			        break;
			    }   
			    else
			        break; 
		}	
	    if (fgetc(fp) == EOF) {
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
    
         /*   printf("Printing edges array... \n");
	        if(edgeHash->edge_count != 0) {
	            
	            printf("\n \nEdges array: \n");
	            for(n = 0; n < edgeHash->edge_count; n++) {
	                printf("%s ", getVertexName(edges[n].vertexId1));    
	                //printf("%d ", edges[n].vertexId1);    
	                printf("%s ", getVertexName(edges[n].vertexId2));  
	                //printf("%d ", edges[n].vertexId2);      
	                printf("%d\n", edges[n].weight);
	            }
	            printf("Printing done! \n\n");
	            //fgets(line, 30, fp);
	       }
           else
                printf("\nIt is empty, there are no type A edges.\n");    
	*/
	//GETTING LAST LINE OF FILE, TYPE B VERTICES WEIGHT
	char *typeB = strtok(line, ": ");
	typeB = strtok(NULL,": ");
	typeB = strtok(NULL,": ");
	//printf("Type B: %s\n",typeB);
	    
	b_weight = atoi(typeB);
//	printf("\nWeight of type B edges: %d\n",b_weight);
//	printf("No. of type A vertices : %d\n", i);
	typeA = i;
	int no_b = numVertices - i;
//	printf("No. of vertices left: %d\n\n", no_b);
	
	
	//CREATING NAMES FOR TYPE B VERTICES AND PRINTING
	//char b[] = "vertexB_";
	//for(m = 1, n = i; m <= no_b, n < numVertices ; m++, n++) 
	//	snprintf(vertices[n], 15, "%s%d", b, m);
		
	/*printf("Printing vertices array after adding type B vertices: \n");	
	for(m = 0; m < numVertices; m++) {
       printf("Vertex %d: ", m);
       puts(vertices[m]);
    }   
    
    printf("\nInserting Type B vertices in vertex hash tables... \n");*/
    /*int res;
    for(n = i; n < numVertices; n++) {
        strcpy(vertex->vertexName, vertices[n]);
        vertex->vertexId = n;
        res = vertexHashInsert(vertexHash, vertex);
    }*/
    
    /*printf("\nPrinting vertex hash table: \n");
    struct llVertexNode * temp;
    for(m = 0; m < MAXBUCKETS; m++) {
        if(vertexHash->buckets[m] != NULL) {
            temp = vertexHash->buckets[m];
            while(temp != NULL) {
                printf("%d  ", (temp->vertexInfo)->vertexId);
                puts((temp->vertexInfo)->vertexName);
                temp = temp->next;
            }
        }
    }       
    
    /*if(edgeHash->edge_count != 0) {
        printf("\nPrinting edge hash table: \n");
        struct llEdgeNode * temp1;
        for(m = 0; m < MAXBUCKETS; m++) {
            if(edgeHash->buckets[m] != NULL) {
            	if(m == 50){
            		printf("\n%p\n",edgeHash->buckets[m]);
            		printf("\n seee this!\n");
            	}	
                temp1 = edgeHash->buckets[m];
                while(temp1 != NULL) {
                    printf("%s  ", getVertexName((temp1->edgeInfo)->vertexId1));
                    printf("%s  ", getVertexName((temp1->edgeInfo)->vertexId2));
                    printf("%d\n", (temp1->edgeInfo)->weight);
                    temp1 = temp1->next;
                }
            }
        } 
     } }
	else{ printf("file not found");
		exit(1);
		}*/
} 
    
}


   
