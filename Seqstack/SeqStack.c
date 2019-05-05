#include <stdio.h>
#include "seqlist.h"
#include "Seqstack.h"


SeqStack* SeqStack_Create(unsigned int capacity)
{
	return (SeqStack*)SeqList_Create(capacity);
}
int SeqStack_Push(SeqStack* stack, void* item)
{
	return SeqList_Insert((SeqList*)stack,(SeqListNode*)item, SeqList_Length((SeqList*)stack));
}
void* SeqStack_Pop(SeqStack* stack)
{
	return SeqList_Delete((SeqList*)stack, SeqList_Length((SeqList*)stack)-1);
}
void* SeqStack_Top(SeqStack* stack)
{
	return SeqList_Get((SeqList*)stack, SeqList_Length((SeqList*)stack)-1);
}
int  SeqStack_Size(SeqStack* stack)
{
	return SeqList_Length((SeqList*)stack);
}
void SeqStack_Clear(SeqStack* stack)
{
	SeqList_Clear((SeqList*)stack);
}
void SeqStack_Destory(SeqStack* stack)
{
	SeqList_Destory((SeqList*)stack);
}
void SeqStack_Display(SeqStack* stack)
{
	SeqList_Display((SeqList*)stack);
}