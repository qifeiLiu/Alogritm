#include <stdio.h>
#include <malloc.h>
#include "seqlist.h"


typedef unsigned int TSeqListNode;
typedef struct _tag_SeqList
{
	unsigned int capacity;
	unsigned int length;
	TSeqListNode* ListNode;
}TSeqList;

SeqList* SeqList_Create(unsigned int capacity)//O(1)
{
	TSeqList* ret = NULL;
	ret = (TSeqList*)malloc(sizeof(TSeqList)+sizeof(TSeqListNode)*capacity);
	if (ret != NULL)
	{
		ret->capacity = capacity;
		ret->length = 0;
		ret->ListNode = (TSeqList*)(ret + 1); // This is very important
	}
	else {
		printf("malloc for SeqList Failed!!!");
	}
	return ret;
}
int SeqList_Length(SeqList* list)//O(1)
{
	int ret = -1;
	TSeqList* sList = (TSeqList*)list;
	if (sList != NULL)
	{
		ret = sList->length;
	}
	return ret;
}
int SeqList_Capacity(SeqList* list)//O(1)
{
	int ret = -1;
	TSeqList* sList = (TSeqList*)list;
	if (sList != NULL)
	{
		ret = sList->capacity;
	}
	return ret;
}
int SeqList_Insert(SeqList* list, SeqListNode* node, unsigned int pos)//O(n)
{
	TSeqList* sList = (TSeqList*)list;
	int ret = (sList != NULL);
	ret = ret &&  (0 <= pos) && (pos < sList->capacity) && (sList->length + 1 <= sList->capacity);
	if (ret)
	{
		if (pos >= sList->length)
		{
			pos = sList->length;
		}
		else {
			for (int i = sList->length - 1; i > pos ; i--)
			{
				sList->ListNode[i] = sList->ListNode[i - 1];
			}
		}
		sList->ListNode[pos] = (TSeqListNode*)node;
		sList->length++;
	}
	return ret;
}
SeqListNode* SeqList_Get(SeqList* list, unsigned int pos) //O(1)
{
	TSeqList* sList = (TSeqList*)list;
	TSeqListNode* ret = NULL;
	if ((sList != NULL) && (pos >= 0) && (pos < sList->length))
	{
		ret = (SeqListNode*)(sList->ListNode[pos]);
	}
	return ret;
}
SeqListNode* SeqList_Delete(SeqList* list, unsigned int pos) //O(n)
{
	TSeqList* sList = (TSeqList*)list;

	TSeqListNode* ret = SeqList_Get(list,pos);
	if (ret != NULL)
	{
		for (int i = pos; i < sList->length; i++)
		{
			sList->ListNode[i] = sList->ListNode[i + 1];
		}
		sList->length--;
	}
	return ret;
}
void  SeqList_Clear(SeqList* list)  //O(1)
{
	TSeqList* sList = (TSeqList*)list;
	if (sList != NULL)
	{
		sList->length = 0;
	}

}
void  SeqList_Destory(SeqList* list) //O(1)
{
	free(list);
}
void  SeqList_Display(SeqList* list)
{
	TSeqList* sList = (TSeqList*)list;
	if (sList != NULL)
	{
		for (int i = 0;i < sList->length; i++)
		{
			printf("%d:%d\n",i,sList->ListNode[i]);
		}

	}
}