#ifndef _TREE_H_
#define _TREE_H_

typedef void GTree;
typedef void GTreeData;
typedef void (GTree_Printf)(GTreeData*);

GTree* GTree_Create();


void GTree_Destory(GTree* tree);

int GTree_Insert(GTree* tree, GTreeData* data, int pos);

GTreeData* GTree_Delete(GTree* tree, int pos);

GTreeData* GTree_Get(GTree* GTree, int pos);

GTreeData* GTree_Root(GTree* tree);

int GTree_Height(GTree* tree);

int GTree_Count(GTree* tree);

int GTree_Degree(GTree* tree);

void GTree_Display(GTree* tree, GTree_Printf* pFunc, int gap, char div);
#endif
