#include <stdio.h>
#include <stdlib.h>
#include "MGraph.h"

void print_data(MVertex* v)
{
	printf("%s", (char*)v);
}


int main(int argc, char *argv[])
{
	MVertex* v[] = { "A", "B", "C", "D", "E" };
	MGraph* graph = MGraph_Create(v,5);

	MGraph_AddEdge(graph, 0, 1, 1);
	MGraph_AddEdge(graph, 1, 2, 1);
	MGraph_AddEdge(graph, 2, 3, 1);
	MGraph_AddEdge(graph, 2, 4, 1);
	MGraph_AddEdge(graph, 3, 4, 9);

	MGraph_Display(graph, print_data);

	printf("Weight <D,E>: %d\n", MGraph_GetEdge(graph,3,4));
	MGraph_Destory(graph);
	system("pause");
}