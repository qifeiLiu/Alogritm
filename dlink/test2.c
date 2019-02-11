#include "Dlink.h"
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

void init_linkHead(stDlinkHead *DlinkHead)
{
	DlinkHead->Head = NULL;
	DlinkHead->size = 0;
	DlinkHead->Tail = NULL;
	return;
}
int insert_Head(stDlinkHead *DlinkHead,stDlinkNode  *plinkNode,int data)
{
	if (DlinkHead == NULL)
	{
		printf("DlinkHead not init.\n");
		return -1;
	}
	if (plinkNode == NULL)
	{
		plinkNode = (stDlinkNode *)malloc(sizeof(stDlinkNode));
		if (plinkNode == NULL)
		{
			printf("malloc fail!\n");
			return -1;
		}
	}
	plinkNode->prev = NULL;
	plinkNode->next = NULL;
	plinkNode->data = data;
	if (DlinkHead->size == 0)
	{
		
		DlinkHead->Head = plinkNode;
		DlinkHead->Tail = plinkNode;	
	}
	else
	{
		plinkNode->next = DlinkHead->Head;
		DlinkHead->Head->prev = plinkNode;
		DlinkHead->Head = plinkNode;
	}
	++DlinkHead->size;
	return 0;
}
void dump_Dlinklist(stDlinkHead *DlinkHead)
{

	int i = 0;
	stDlinkNode *plinkNode = DlinkHead->Head;

	while (plinkNode != NULL)
	{
		printf("[%d]:%d\n", i, plinkNode->data);
		plinkNode = plinkNode->next;
		++i;
    }
	return;
}
stDlinkNode *search(stDlinkHead *DlinkHead,int data)
{
	stDlinkNode *plinkNode = NULL;
	plinkNode = DlinkHead->Head;
	while (plinkNode != NULL)
	{
		if (plinkNode->data == data)
		{
			return plinkNode;
		}
		plinkNode = plinkNode->next;
	}
	return NULL;
}
void remove_node(stDlinkHead *DlinkHead, stDlinkNode *plinkNode)
{
	if ((DlinkHead == NULL) || (plinkNode == NULL))
	{
		return;
	}
	if (DlinkHead->Head == plinkNode)
	{
		DlinkHead->Head = DlinkHead->Head->next;
	}
	else if (DlinkHead->Tail == plinkNode)
	{
		DlinkHead->Tail = DlinkHead->Tail->prev;
		DlinkHead->Tail->next = NULL;
	}
	else
	{
		plinkNode->prev->next = plinkNode->next;
		plinkNode->next->prev = plinkNode->prev;
	}
	DlinkHead->size--;
	plinkNode->prev = NULL;
	plinkNode->next = NULL;
	if (DlinkHead->size == 0)
	{
		memset(DlinkHead,0,sizeof(stDlinkHead));
	}
	return;
}

stDlinkNode * remove_tail(stDlinkHead *DlinkHead)
{
	stDlinkNode *plinkNode = NULL;
	if (DlinkHead->size == 0)
	{
		return NULL;
	}
	plinkNode = DlinkHead->Tail;
	if (DlinkHead->size > 1)
	{
		DlinkHead->Tail = DlinkHead->Tail->prev;
		DlinkHead->Tail->next = NULL;
	}
	else
	{
		DlinkHead->Head = NULL;
		DlinkHead->Tail = NULL;
	}
	DlinkHead->size--;
	return plinkNode;
}

void Lru(stDlinkHead *DlinkHead, int data)
{
	stDlinkNode  *plinkNode = NULL;
	plinkNode = search(DlinkHead,data);
	if (plinkNode != NULL)
	{
		remove_node(DlinkHead, plinkNode);
	}
	else if (DlinkHead->size >= 4)
	{
		remove_tail(DlinkHead);
	}
	insert_Head(DlinkHead,plinkNode,data);
	return;
}
int main()
{
	printf("int Size:%d\n", sizeof(int));
	printf("Dlink Node Size:%d\n", sizeof(struct DlinkNode));
	printf("Dlink Head Size:%d\n", sizeof(struct DlinkHead));

	/***************************************************************
	   init   
	**************************************************************/
	stDlinkHead DlinkHead = {0};
	stDlinkNode *plinkNode = NULL;
	/***********************************************************/
	init_linkHead(&DlinkHead);
	dump_Dlinklist(&DlinkHead);
	insert_Head(&DlinkHead,plinkNode,1);
	insert_Head(&DlinkHead, plinkNode, 2);
	insert_Head(&DlinkHead, plinkNode, 3);
	dump_Dlinklist(&DlinkHead);
	plinkNode = search(&DlinkHead, 2);
	Lru(&DlinkHead, 5);
	dump_Dlinklist(&DlinkHead);
	Lru(&DlinkHead, 6);
	dump_Dlinklist(&DlinkHead);
	Lru(&DlinkHead, 7);
	dump_Dlinklist(&DlinkHead);
	Lru(&DlinkHead, 5);
	dump_Dlinklist(&DlinkHead);
	system("pause");
	return 0;
}