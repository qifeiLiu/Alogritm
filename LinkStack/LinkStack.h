#pragma once
#ifndef _LINK_STACK_H
#define _LINK_STACK_H

typedef void LinkStack;

LinkStack* LinkStack_Create();
void* LinkStack_Pop(LinkStack* stack);
int LinkStack_Push(LinkStack* stack,void* item);
void* LinkStack_Top(LinkStack* stack);
void LinkStack_Clear(LinkStack* stack);
void LinkStack_Destory(LinkStack* stack);
int LinkStack_Size(LinkStack* stack);
#endif


