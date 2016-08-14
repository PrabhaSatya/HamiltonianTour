#include "graph.h"
/* Function to create max / descending heap as required
   edges - pointer to array of edges
*/

int heap_size;      

void max_heapify(struct Edge *edges , int index);

/* Function to build the  heap*/ 
void build_heap(struct Edge *edges , int numEdges);

/*Function to perform heap sort i.e call heapify and recreate_heap from here . 
   edges - pointer to array of edges
Return 0 on success and -1 on failure*/
int heapsort(struct Edge *edges , int numEdges);
