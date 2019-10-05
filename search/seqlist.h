#pragma once
#ifndef _SEQLIST_H
#define _SEQLIST_H


typedef void SeqList;
typedef void SeqListNode;


SeqList* SeqList_Create(int capacity);
void SeqList_Clear(SeqList* list);
SeqListNode* SeqList_Delete(SeqList* list,int Pos);
int  SeqList_Insert(SeqList* list,SeqListNode* Node,int Pos);
void SeqList_Destory(SeqList* list);
SeqListNode*  SeqList_Get(SeqList* list,int Pos);
int SeqList_Length(SeqList* list);
int SeqList_Capacity(SeqList* list);
#endif
