dbp : main.o graph.o hash.o vertices.o llist.o heapsort.o checkTriangleInequality.o minimumSpanningTree.o DFS.o stack.o optheuristic.o nearest_neighbour.o
	gcc  -o dbp main.o graph.o hash.o vertices.o llist.o heapsort.o checkTriangleInequality.o minimumSpanningTree.o DFS.o stack.o nearest_neighbour.o 	optheuristic.o
main.o : main.c main.h
	gcc -c  main.c  
graph.o : graph.c graph.h 
	gcc -c  graph.c
vertices.o : vertices.c hash.h
	gcc -c  vertices.c
llist.o : llist.c llist.h hash.h  graph.h
	gcc -c  llist.c
hash.o : hash.c hash.h llist.h
	gcc -c  hash.c
heapsort.o : heapsort.c heapsort.h
	gcc -c  heapsort.c
checkTriangleInequality.o : checkTriangleInequality.c checkTriangleInequality.h
	gcc -c checkTriangleInequality.c 
minimumSpanningTree.o : minimumSpanningTree.c minimumSpanningTree.h DFS.h
	gcc -c  minimumSpanningTree.c 
DFS.o : DFS.c DFS.h
	gcc -c  DFS.c
stack.o : stack.c stack.h graph.h hash.h
	gcc -c  stack.c
nearest_neighbour.o : nearest_neighbour.c nearest_neighbour.h graph.h
	gcc -c nearest_neighbour.c
optheuristic.o : optheuristic.c optheuristic.h llist.h DFS.h graph.h hash.h 
	gcc -c  optheuristic.c 	
clean : 
	rm *.o
	#rm project main.o graph.o hash.o vertices.o llist.o heapsort.o checkTriangleInequality.o minimumSpanningTree.o



