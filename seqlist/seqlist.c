#include <stdio.h>
#include <malloc.h>
#include "seqlist.h"

typedef unsigned int TSeqListNode;
typedef struct _tag_SeqList
{
	int capacity;
	int length;
	TSeqListNode* Node;
}TSeqList;

SeqList* Seqlist_Create(int capacity)
{
	TSeqList* ret = NULL;
	if (capacity >= 0)
	{
		ret = (TSeqList*)malloc(sizeof(TSeqList)+sizeof(TSeqListNode)*capacity);
	}
	if (ret != NULL)
	{
		ret->capacity = capacity;
		ret->length = 0;
		ret->Node = (TSeqListNode*)(ret + 1);
	}
	return ret;
}
int Seqlist_Insert(SeqList* list, SeqListNode* Node, int Pos)
{
	TSeqList* sList = (TSeqList*)list;
	int ret = (sList != NULL);
	int i = 0;
	ret = ret && (sList->length + 1 <= sList->capacity);
	ret = ret && (Pos >= 0);
	if (ret)
	{
		if (Pos >= sList->length)
		{
			Pos = sList->length;
		}
		for (i=sList->length;i>Pos;i--)
		{
			sList->Node[i] = sList->Node[i - 1];
		}
		sList->Node[i] = (TSeqListNode)Node;
		sList->length++;

	}
	return ret;
}

int Seqlist_Length(SeqList* list)
{
	TSeqList* sList = (TSeqList*)list;
	int ret = -1;
	if (sList != NULL)
	{
		ret = sList->length;
	}
	return ret;
}

int Seqlist_Capacity(SeqList* list)
{
	TSeqList* sList = (TSeqList*)list;
	int ret = -1;
	if (sList != NULL)
	{
		ret = sList->capacity;
	}
	return ret;
}

SeqListNode* Seqlist_Get(SeqList* list, int Pos)
{
	TSeqList* sList = (TSeqList*)list;
	SeqListNode* ret = NULL;
	if ((sList != NULL) && (0 <= Pos) && (Pos < sList->length))
	{
		ret = (SeqListNode*)(sList->Node[Pos]);
	}
	return ret;
}

SeqListNode* Seqlist_Delete(SeqList* list,int Pos)
{
	TSeqList* sList = (TSeqList*)list;
	SeqListNode* ret = Seqlist_Get(list, Pos);
	int i = 0;

	if (ret != NULL)
	{
		for (i = Pos;i <sList->length;i++)
		{
			sList->Node[i] = sList->Node[i + 1];
		}
		sList->length--;
	}
	return ret;
}
void Seqlist_Destory(SeqList* list)
{
	free(list);
}

void Seqlist_Clear(SeqList* list)
{
	TSeqList* sList = (TSeqList*)list;

	if (sList != NULL)
	{
		sList->length = 0;
	}
}
