#include <stdio.h>
#include <malloc.h>
#include "MGraph.h"

typedef struct _tag_MGraph
{
	int count;
	MVertex** v;
	int** matrix;
}TMGraph;


/*创建并返回有n个顶点的图*/
MGraph* MGraph_Create(MVertex**v,int n)  //O(n)
{
	TMGraph* ret = NULL;
	if ((v != NULL) && (n > 0))
	{
		ret = (TMGraph*)malloc(sizeof(TMGraph));
		if (ret != NULL)
		{
			int* p = NULL;
			ret->count = n;
			ret->v = (MVertex**)malloc(sizeof(MVertex*)* n);
			ret->matrix = (int**)malloc(sizeof(int*)*n);
			p = (int*)calloc(n*n,sizeof(int));
			if ((ret->v != NULL) && (ret->matrix != NULL) && (p != NULL))
			{
				int i = 0;
				for (i = 0; i < n; i++)
				{
					ret->v[i] = v[i];
					ret->matrix[i] = p + i * n;
				}
			}
			else
			{
				free(p);
				free(ret->matrix);
				free(ret->v);
				free(ret);
				ret = NULL;
			}
		}
	}
	return ret;
}
/*销毁graph所指向的图*/
void MGraph_Destory(MGraph* graph) //O(1)
{
	TMGraph* tGraph = (TMGraph*)graph;
	if (tGraph != NULL)
	{
		free(tGraph->v);
		free(tGraph->matrix[0]);
		free(tGraph->matrix);
		free(tGraph);
	}
}
/*将graph所指图的边集合清空*/
void MGraph_Clear(MGraph* graph) //O(n*n)
{
	TMGraph* tGraph = (TMGraph*)graph;
	if (tGraph != NULL)
	{
		int i = 0;
		int j = 0;
		for (i = 0; i < tGraph->count; i++)
		{
			for (j = 0; j < tGraph->count; j++)
			{
				tGraph->matrix[i][j] = 0;
			}
		}
	}

}
/*在 graph 所指的 v1 v2 之间加上边，且边的权为w*/
int MGraph_AddEdge(MGraph* graph, int v1, int v2, int w)//O(1)
{
	TMGraph* tGraph = (TMGraph*)graph;
	int  ret = (tGraph != NULL);
	ret = ret && (0 <= v1) && (v1 < tGraph->count);
	ret = ret && (0 <= v2) && (v2 < tGraph->count);
	if (ret)
	{
		tGraph->matrix[v1][v2] = w;
	}
	return ret;
}

/*将graph所指图中的v1和v2之间的边的权值返回*/
int MGraph_RemoveEdge(MGraph* graph, int v1, int v2)//O(1)
{
	TMGraph* tGraph = (TMGraph*)graph;
	int condition = (tGraph != NULL);
	condition = condition && (0 <= v1) && (v1 < tGraph->count);
	condition = condition && (0 <= v2) && (v2 < tGraph->count);
	int ret = 0;
	 
	if (condition)
	{
		ret = tGraph->matrix[v1][v2];
		((TMGraph*)graph)->matrix[v1][v2] = 0;
	}
	return ret;
}
/*将graph所指的图中v1 和 v2 之间的边的权值返回*/
int MGraph_GetEdge(MGraph* graph, int v1, int v2)//O(1)
{
	TMGraph* tGraph = (TMGraph*)graph;
	int condition = (tGraph != NULL);
	condition = condition && (0 <= v1) && (v1 < tGraph->count);
	condition = condition && (0 <= v2) && (v2 < tGraph->count);
	int ret = 0;

	if (condition)
	{
		ret = tGraph->matrix[v1][v2];
		//((TMGraph*)graph)->matrix[v1][v2] = 0;
	}
	return ret;
}

/*将Graph所指图中的顶点数返回*/
int MGraph_TD(MGraph* graph, int v)
{
	TMGraph* tGraph = (TMGraph*)graph;
	int ret = 0;
	int condition = (tGraph != NULL);
	condition = condition && (0 <= v) && (v < tGraph->count);
	if (condition)
	{
		int i = 0;
		for (i = 0; i < tGraph->count; i++)
		{
			if (tGraph->matrix[v][i] != 0)
			{
				ret++;
			}
			if (tGraph->matrix[i][v] != 0)
			{
				ret++;
			}
		}
	}

	return ret;
}
/*将graph所指图中的顶点数返回*/
int MGraph_VertexCount(MGraph* graph)
{
	TMGraph* tGraph = (TMGraph*)graph;
	int ret = 0;
	if (tGraph != NULL)
	{
		ret = tGraph->count;
	}
	return ret;
}
/*将graph所指图中的边数返回*/
int MGraph_EdgeCount(MGraph* graph)
{
	TMGraph* tGraph = (TMGraph*)graph;
	int ret = 0;
	if (tGraph != NULL)
	{
		int i = 0;
		int j = 0;
		for (i = 0; i < tGraph->count; i++)
		{
			for (j = 0; j < tGraph->count; j++)
			{
				if (tGraph->matrix[i][j] != 0)
				{
					ret++;
				}
			}
		}
	}

	return ret;
}

void MGraph_Display(MGraph* graph, MGraph_printf* pFunc)
{
	TMGraph* tGraph = (TMGraph*)graph;

	if ((tGraph != NULL) && (pFunc != NULL))
	{
		int i = 0;
		int j = 0;
		for (i = 0; i < tGraph->count; i++)
		{
			printf("%d:",i);
			pFunc(tGraph->v[i]);
			printf(" ");
		}
		printf("\n");

		for (i = 0; i < tGraph->count; i++)
		{
			for (j = 0; j < tGraph->count; j++)
			{
				if (tGraph->matrix[i][j] != 0)
				{
					printf("<");
					pFunc(tGraph->v[i]);
					printf(", ");
					pFunc(tGraph->v[j]);
					printf(",  %d", tGraph->matrix[i][j]);
					printf(">");
					printf(" ");
				}
			}
		}
		printf("\n");
	}
}

