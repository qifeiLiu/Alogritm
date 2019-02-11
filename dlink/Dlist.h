#pragma once
#include <stdio.h>
typedef struct DlistNode
{
	struct DlistNode *prev;
	struct DlistNode *next;
	
}stDlistNode;

typedef struct Dlisthead
{
	int size;
	stDlistNode *head;
	stDlistNode *tail;
}stDlistHead;