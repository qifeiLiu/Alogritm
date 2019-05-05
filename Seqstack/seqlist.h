#pragma once
#ifndef _SEQLIST_H
#define _SEQLIST_H
typedef void SeqList;
typedef void SeqListNode;

SeqList* SeqList_Create(unsigned int capacity);//O(1)
int SeqList_Length(SeqList* list);//O(1)
int SeqList_Capacity(SeqList* list);//O(1)
int SeqList_Insert(SeqList* list,SeqListNode* node,unsigned int pos);//O(n)
SeqListNode* SeqList_Get(SeqList* list, unsigned int pos);//O(1)
SeqListNode* SeqList_Delete(SeqList* list, unsigned int pos);//O(n)
void  SeqList_Clear(SeqList* list);//O(1)
void  SeqList_Destory(SeqList* list);//O(1)
void  SeqList_Display(SeqList* list);


#endif