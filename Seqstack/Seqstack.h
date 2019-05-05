#ifndef _SEQSTACK_H_
#define _SEQSTACK_H_

typedef void SeqStack;

SeqStack* SeqStack_Create(unsigned int capacity);
int SeqStack_Push(SeqStack* stack, void* item);
void* SeqStack_Pop(SeqStack* stack);
void* SeqStack_Top(SeqStack* stack);
int  SeqStack_Size(SeqStack* stack);
void SeqStack_Clear(SeqStack* stack);
void SeqStack_Destory(SeqStack* stack);
void SeqStack_Display(SeqStack* stack);
#endif // !_SEQSTACK_H_
