#pragma once
#ifndef _STATICLIST_H_
#define _STATICLIST_H_
typedef void StaticListNode;
typedef void StaticList;

StaticList* StaticList_Create(int capacity);
int StaticList_Insert(StaticList* list, StaticListNode* node, int pos);
int StaticList_Length(StaticListNode* list);
void StaticList_Destroy(StaticListNode* list);
void StaticList_Clear(StaticListNode* list);
int StaticList_Capacity(StaticListNode* list);
StaticListNode* StaticList_Get(StaticList* list, int pos);
StaticListNode* StaticList_Delete(StaticList* list, int pos);
#endif
