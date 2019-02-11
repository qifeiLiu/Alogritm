#pragma once
#ifndef _SEQLIST_H
#define _SEQLIST_H


typedef void SeqList;
typedef void SeqListNode;


SeqList* Seqlist_Create(int capacity);
void Seqlist_Clear(SeqList* list);
SeqListNode* Seqlist_Delete(SeqList* list,int Pos);
int  Seqlist_Insert(SeqList* list,SeqListNode* Node,int Pos);
void Seqlist_Destory(SeqList* list);
SeqListNode*  Seqlist_Get(SeqList* list,int Pos);
int Seqlist_Length(SeqList* list);
int Seqlist_Capacity(SeqList* list);
#endif