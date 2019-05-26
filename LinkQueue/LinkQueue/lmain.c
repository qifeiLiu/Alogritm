#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"
//#include "LinkList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) 
{
    LinkQueue* queue = LinkQueue_Create();
    
 
    
    int v1 = 1;
    int v2 = 2;
    int v3 = 3;
    int v4 = 4;
    int v5 = 5;

    LinkQueue_Append(queue, &v1);
    LinkQueue_Append(queue, &v2);
    LinkQueue_Append(queue, &v3);
    LinkQueue_Append(queue, &v4);
    LinkQueue_Append(queue, &v5);

    
	int pv = *(int *)LinkQueue_Header(queue);

	printf("%d\n", pv);
    
    while( LinkQueue_Length(queue) > 0 )
    {
		int *p = (int *)LinkQueue_Retrieve(queue);
		printf("%d\n", *p );
    }
    
    LinkQueue_Destroy(queue);
	system("pause");
    return 0;
}
//
//struct Value
//{
//	LinkListNode header;
//	int v;
//};

//int main(int argc, char *argv[])
//{
//	int i = 0;
//	LinkList* list = LinkList_Create();
//
//	struct Value v1;
//	struct Value v2;
//	struct Value v3;
//	struct Value v4;
//	struct Value v5;
//
//	v1.v = 1;
//	v2.v = 2;
//	v3.v = 3;
//	v4.v = 4;
//	v5.v = 5;
//
//	LinkList_Insert(list, (LinkListNode*)&v1, LinkList_Length(list));
//	LinkList_Insert(list, (LinkListNode*)&v2, LinkList_Length(list));
//	LinkList_Insert(list, (LinkListNode*)&v3, LinkList_Length(list));
//	LinkList_Insert(list, (LinkListNode*)&v4, LinkList_Length(list));
//	LinkList_Insert(list, (LinkListNode*)&v5, LinkList_Length(list));
//
//	for (i = 0; i<LinkList_Length(list); i++)
//	{
//		struct Value* pv = (struct Value*)LinkList_Get(list, i);
//
//		printf("%d\n", pv->v);
//	}
//
//	while (LinkList_Length(list) > 0)
//	{
//		struct Value* pv = (struct Value*)LinkList_Delete(list, 0);
//
//		printf("%d\n", pv->v);
//	}
//
//	LinkList_Destroy(list);
//	system("pause");
//
//	return 0;
//}


//int main(int argc, char *argv[])
//{
//	LinkQueue* queue = LinkQueue_Create();
//	int a[10] = { 0 };
//	int i = 0;
//
//	for (i = 0; i<10; i++)
//	{
//		a[i] = i + 1;
//
//		LinkQueue_Append(queue, a + i);
//	}
//
//	printf("Header: %d\n", *(int*)LinkQueue_Header(queue));
//	printf("Length: %d\n", LinkQueue_Length(queue));
//
//	while (LinkQueue_Length(queue) > 0)
//	{
//		printf("Retrieve: %d\n", *(int*)LinkQueue_Retrieve(queue));
//	}
//
//	LinkQueue_Destroy(queue);
//	system("pause");
//	return 0;
//}
