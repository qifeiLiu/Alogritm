#include <stdio.h>
#include <malloc.h>
#include "GTree.h"
#include "LinkList.h"

typedef struct _tag_GTreeNode GTreeNode;
struct _tag_GTreeNode
{
	GTreeData* data;
	GTreeNode* parent;
	LinkList* child;
};

typedef struct _tag_TLNode TLNode;
struct _tag_TLNode
{
	LinkListNode header;
	GTreeNode* node;
};

static void recursive_display(GTreeNode* node, GTree_Printf* pFunc, int format, int gap, char div)
{
	int i = 0;
	if (node != NULL)
	{
		for (i = 0; i<format; i++)
		{
			printf("%c", div);
		}
		//printf("%c",(int)node->data);
		pFunc(node->data);
		printf("\n");

		for (i = 0; i<LinkList_Length(node->child); i++)
		{
			TLNode* trNode = (TLNode*)LinkList_Get(node->child, i);
			recursive_display(trNode->node, pFunc, format + gap, gap, div);
		}
	}
}

static void recursive_delete(LinkList* list, GTreeNode* node)
{
	if ((list != NULL) && (node != NULL))
	{
		GTreeNode* parent = node->parent;
		int index = -1;
		int i = 0;
		for (i = 0; i<LinkList_Length(list); i++)
		{
			TLNode* trNode = (TLNode*)LinkList_Get(list, i);
			if (trNode->node == node)
			{
				LinkList_Delete(list, i);
				free(trNode);
				index = i;
				break;
			}
		}
		if (index >= 0)
		{
			if (parent != NULL)
			{
				for (i = 0; i<LinkList_Length(parent->child); i++)
				{
					TLNode* trNode = (TLNode*)LinkList_Get(parent->child, i);
					if (trNode->node == node)
					{
						LinkList_Delete(parent->child, i);
						free(trNode);
						break;
					}
				}
			}
			while (LinkList_Length(node->child)> 0)
			{
				TLNode* trNode = (TLNode*)LinkList_Get(node->child, 0);
				recursive_delete(list, trNode->node);
			}
			LinkList_Destroy(node->child);
			free(node);
		}
	}
}

static int recursive_height(GTreeNode* node)
{
	int ret = 0;
	if (node != NULL)
	{
		int subHeight = 0;
		int i = 0;

		for (i = 0; i< LinkList_Length(node->child); i++)
		{
			TLNode* trNode = (TLNode*)LinkList_Get(node->child, i);
			//printf("Data:%c\n",trNode->node->data);
			subHeight = recursive_height(trNode->node);
			if (ret < subHeight)
			{
				ret = subHeight;
			}
		}
		ret = ret + 1;
	}
	return ret;
}

static int recursive_degree(GTreeNode* node)
{
	int ret = 0;
	if (node != NULL)
	{
		int subDegree = 0;
		int i = 0;

		ret = LinkList_Length(node->child);
		for (i = 0; i<LinkList_Length(node->child); i++)
		{
			TLNode* trNode = (TLNode*)LinkList_Get(node->child, i);
			subDegree = recursive_degree(trNode->node);

			if (ret < subDegree)
			{
				ret = subDegree;
			}

		}

	}
	return ret;
}
GTree* GTree_Create()
{
	return LinkList_Create();
}
void GTree_Clear(GTree* tree)
{
	GTree_Delete(tree, 0);
}

void GTree_Destory(GTree* tree)
{
	GTree_Clear(tree);
	LinkList_Destroy(tree);
}


int GTree_Insert(GTree* tree, GTreeData* data, int pPos)//Parent pos
{
	LinkList* list = (LinkList*)tree;
	int ret = (list != NULL) && (data != NULL) && (pPos < LinkList_Length(list));
	if (ret)
	{
		TLNode* trNode = (TLNode*)malloc(sizeof(TLNode));//as a part of full linklist
		TLNode* cldNode = (TLNode*)malloc(sizeof(TLNode));// as a part of parent linklist

		TLNode* pNode = (TLNode*)LinkList_Get(list, pPos);//parent Node
		GTreeNode* cNode = (GTreeNode*)malloc(sizeof(GTreeNode));//current Node need to insert

		ret = (trNode != NULL) && (cldNode != NULL) && (cNode != NULL);

		if (ret)
		{
			cNode->data = data;
			cNode->parent = NULL;
			cNode->child = LinkList_Create();

			trNode->node = cNode;
			cldNode->node = cNode;

			LinkList_Insert(list, (LinkListNode*)trNode, LinkList_Length(list));

			if (pNode != NULL) // = NULL  not Root
			{
				cNode->parent = pNode->node;
				LinkList_Insert(pNode->node->child, (LinkListNode*)cldNode, LinkList_Length(pNode->node->child));
			}
			else
			{
				free(cldNode);// Root , not cldNode
			}
		}
		else
		{
			free(trNode);
			free(cldNode);
			free(cNode);
		}
	}
	return ret;
}

GTreeData* GTree_Delete(GTree* tree, int pos)
{
	TLNode* trNode = (TLNode*)LinkList_Get(tree, pos);
	GTreeData* ret = NULL;
	if (trNode != NULL)
	{
		ret = trNode->node->data;
		recursive_delete(tree, trNode->node);
	}
	return ret;
}

GTreeData* GTree_Get(GTree* tree, int pos)
{
	TLNode* trNode = (TLNode*)LinkList_Get(tree, pos);
	GTreeData* ret = NULL;
	if (trNode != NULL)
	{
		ret = trNode->node->data;
	}
	return ret;
}

GTreeData* GTree_Root(GTree* tree)
{
	//GTreeData* ret = NULL;

	//return LinkList_Get(tree,0);
	return GTree_Get(tree, 0);
}

int GTree_Height(GTree* tree)
{
	TLNode* trNode = (TLNode*)LinkList_Get(tree, 0);
	int ret = 0;
	if (trNode != NULL)
	{
		ret = recursive_height(trNode->node);
	}
	return ret;
}

int GTree_Count(GTree* tree)
{
	return LinkList_Length(tree);
}

int GTree_Degree(GTree* tree)
{
	TLNode* trNode = (TLNode*)LinkList_Get(tree, 0);
	int ret = 0;

	if (trNode != NULL)
	{
		ret = recursive_degree(trNode->node);
	}
	return ret;
}

void GTree_Display(GTree* tree, GTree_Printf* pFunc, int gap, char div)
{
	TLNode* trNode = (TLNode*)LinkList_Get(tree, 0);
	if (trNode != NULL)
	{
		recursive_display(trNode->node, pFunc, 0, gap, div);
	}
}