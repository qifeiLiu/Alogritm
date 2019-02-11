#pragma once
#include <stdio.h>

struct DlinkNode
{
	struct DlinkNode *prev;
	int data;
	struct DlinkNode *next;
};

typedef struct DlinkNode stDlinkNode;

struct  DlinkHead
{
	struct DlinkNode *Head;
	int size;
	struct DlinkNode *Tail;
};
typedef struct DlinkHead stDlinkHead;