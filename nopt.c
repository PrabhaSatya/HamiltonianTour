	int j,i,v1,v2,in1,in2,jn1,jn2,w1,w2,tw1,tw2,flag=1;
	while(flag==1)
	{flag=0;
	for(i=0;i<numVertices;i++)
	{	v1=tnvertices[i].vertexId;
		in1=tnvertices[i].neighborid1;
		in2=tnvertices[i].neighborid2;
		w1=getWeight(v1,in2,edgeHash);	
		for(j=0;j<numVertices;j++)
		{     	v2=tnvertices[j].vertexId;
			jn1=tnvertices[j].neighborid1;
			jn2=tnvertices[j].neighborid2;	
			if(v2!=v1&&v2!=in1&&v2!=in2&&in2!=jn2&&jn2!=in1)
			{	w2=getWeight(v2,jn2,edgeHash);
				tw1=getWeight(v1,v2,edgeHash);
				tw2=getWeight(in2,jn2,edgeHash);
				printf("%s\t%s\t%d\t%s\t%s\t%d\t%s\t%s\t%d\t%s\t%s\t%d\n",vertices[v1],vertices[in2],w1,vertices[v2],vertices[jn2],w2,vertices[v1],vertices[v2],tw1,vertices[in2],vertices[jn2],tw2);
				if((w1==b_weight||w2==b_weight)&&(tw1!=b_weight||tw2!=b_weight))
				{	printf("entered if");
					tnvertices[v1].neighborid2=v2;
					tnvertices[in2].neighborid2=jn2;
					tnvertices[v2].neighborid1=v1;
					tnvertices[jn2].neighborid1=in2;
					tnvertices[v2].neighborid2=in2;
					tnvertices[in2].neighborid1=v2;
					flag=1;				

				}
			}
		}
	}
	}
	printf("\n\n...............neighbors of vertices in the tour................");
	for(i=0;i<numVertices;i++)
	{ printf("\n%s\t%s\t%s\n",vertices[i],vertices[tnvertices[i].neighborid1],vertices[tnvertices[i].neighborid2]);
	}

