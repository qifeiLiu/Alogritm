#ifndef _MGRAPH_H_
#define _MGRAPH_H_

typedef void MGraph;
typedef void MVertex;
typedef void (MGraph_printf)(MVertex*);

/*������������n�������ͼ*/
MGraph* MGraph_Create(int n);
/*����graph��ָ���ͼ*/
void MGraph_Destory(MGraph* graph);
/*��graph��ָͼ�ı߼������*/
void MGraph_Clear(MGraph* graph);
/*�� graph ��ָ�� v1 v2 ֮����ϱߣ��ұߵ�ȨΪw*/
int MGraph_AddEdge(MGraph* graph,int v1,int v2,int w);

/*��graph��ָͼ�е�v1��v2֮��ıߵ�Ȩֵ����*/
int MGraph_RemoveEdge(MGraph* graph,int v1,int v2);
/*��graph��ָ��ͼ��v1 �� v2 ֮��ıߵ�Ȩֵ����*/
int MGraph_GetEdge(MGraph* graph,int v1,int v2);

/*��Graph��ָͼ�еĶ���������*/
int MGraph_TD(MGraph* graph, int v);
/*��graph��ָͼ�еĶ���������*/
int MGraph_VertexCount(MGraph* graph);
/*��graph��ָͼ�еı�������*/
int MGraph_EdgeCount(MGraph* graph);

void MGraph_Display(MGraph* graph, MGraph_printf* pFunc);

#endif