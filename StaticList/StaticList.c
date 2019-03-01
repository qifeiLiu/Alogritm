#include <stdio.h>
#include "StaticList.h"

#define AVAILABLE -1
typedef struct _tag_StaticListNode
{
	unsigned int data;
	int next;
}TStaticListNode;

typedef struct _tag_StaticList
{
	int capacity;
	TStaticListNode header;
	TStaticListNode Node[];
}TStaticList;

StaticList* StaticList_Create(int capacity)
{
	TStaticList* ret = NULL;
	int i = 0;
	if (capacity >= 0)
	{
		ret = (TStaticList*)malloc(sizeof(TStaticList) + (capacity+1) * sizeof(TStaticListNode));
	}
	if (ret != NULL)
	{
		ret->capacity = capacity;
		ret->header.data = 0;
		ret->header.next = 0;
		for (i = 1; i <= capacity; i++)
		{
			ret->Node[i].next = AVAILABLE;
		}
	}
	return ret;
}

int StaticList_Insert(StaticList* list,StaticListNode* node,int pos)
{
	TStaticList* sList = (TStaticList*)list;
	int ret = (sList != NULL);
	int i = 0;
	int current = 0;
	int index = 0;

	ret = ret && (sList->header.data + 1 <= sList->capacity);
	ret = ret && (pos >= 0 ) && (node != NULL);
	if (ret)
	{  
		for (i=1; i<= sList->capacity;i++)
		{
			if (sList->Node[i].next == AVAILABLE)
			{
				index = i;
				break;
			}
		}
		sList->Node[index].data = (unsigned int)node;
		sList->Node[0] = sList->header;
		for (i = 0; (i < pos) && (sList->Node[current].next != 0); i++)
		{
			current = sList->Node[current].next;
		}
		sList->Node[index].next = sList->Node[current].next;
		sList->Node[current].next = index;
		sList->Node[0].data++;
		sList->header = sList->Node[0];
	}
	return ret;
}
StaticListNode* StaticList_Delete(StaticList* list,int pos)
{
	TStaticList* sList = (TStaticList*)list;
	StaticListNode* ret = NULL;
	int current = 0;
	int i = 0;
	int object = 0;
	if (sList != NULL && (0 <= pos) && (pos < sList->header.data))
	{
		sList->Node[0] = sList->header;
		for (i = 0; i < pos; i++)
		{
			current = sList->Node[current].next;
		}
		object = sList->Node[current].next;
		sList->Node[current].next = sList->Node[object].next;
		sList->Node[0].data--;
		sList->header = sList->Node[0];
		sList->Node[current].next = AVAILABLE;
		ret = (StaticListNode*)sList->Node[object].data;
	}
	return ret;
}
int StaticList_Length(StaticListNode* list)
{
	TStaticList* sList = (TStaticList*)list;
	int ret = -1;
	if (sList != NULL)
	{
		ret = sList->header.data;
	}
	return ret;
}
void StaticList_Destroy(StaticListNode* list)
{
	free(list);
}

void StaticList_Clear(StaticListNode* list)
{
	TStaticList* sList = (TStaticList*)list;
	int i = 0;
	if (sList != NULL)
	{
		sList->header.data = 0;
		sList->header.next = 0;
		for (i = 1; i <= sList->capacity; i++)
		{
			sList->Node[i].next = AVAILABLE;
		}
	}
}

int StaticList_Capacity(StaticListNode* list)
{
	TStaticList* sList = (TStaticList*)list;
	int ret = -1;
	if (sList != NULL)
	{
		ret = sList->capacity;
	}
	return ret;
}

StaticListNode* StaticList_Get(StaticList* list, int pos)
{
	TStaticList* sList = (TStaticList*)list;
	StaticListNode* ret = NULL;
	int current = 0;
	int object = 0;
	int i = 0;
	if ((sList != NULL) && (0 <= pos) && (pos < sList->header.data))
	{
		sList->Node[0] = sList->header;

		for (i = 0; i<pos; i++)
		{
			current = sList->Node[current].next;
		}

		object = sList->Node[current].next;

		ret = (StaticListNode*)(sList->Node[object].data);
	}

	return ret;
}