#ifndef _MGRAPH_H_
#define _MGRAPH_H_

typedef void MGraph;
typedef void MVertex;
typedef void (MGraph_printf)(MVertex*);

/*创建并返回有n个顶点的图*/
MGraph* MGraph_Create(int n);
/*销毁graph所指向的图*/
void MGraph_Destory(MGraph* graph);
/*将graph所指图的边集合清空*/
void MGraph_Clear(MGraph* graph);
/*在 graph 所指的 v1 v2 之间加上边，且边的权为w*/
int MGraph_AddEdge(MGraph* graph,int v1,int v2,int w);

/*将graph所指图中的v1和v2之间的边的权值返回*/
int MGraph_RemoveEdge(MGraph* graph,int v1,int v2);
/*将graph所指的图中v1 和 v2 之间的边的权值返回*/
int MGraph_GetEdge(MGraph* graph,int v1,int v2);

/*将Graph所指图中的顶点数返回*/
int MGraph_TD(MGraph* graph, int v);
/*将graph所指图中的顶点数返回*/
int MGraph_VertexCount(MGraph* graph);
/*将graph所指图中的边数返回*/
int MGraph_EdgeCount(MGraph* graph);

void MGraph_Display(MGraph* graph, MGraph_printf* pFunc);

#endif