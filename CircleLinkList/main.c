#include <stdio.h>
#include <stdlib.h>
#include "circlelist.h"


struct Value
{
	CircleListNode header;
	int v;
};


int main(int argc, char *argv[])
{
	int i = 0;
	CircleList* list = CircleList_Create();

	struct Value v1;
	struct Value v2;
	struct Value v3;
	struct Value v4;
	struct Value v5;
	struct Value v6;
	struct Value v7;
	struct Value v8;

	v1.v = 1;
	v2.v = 2;
	v3.v = 3;
	v4.v = 4;
	v5.v = 5;
	v6.v = 6;
	v7.v = 7;
	v8.v = 8;

	CircleList_Insert(list, (CircleListNode*)&v1, CircleList_Length(list));
	CircleList_Insert(list, (CircleListNode*)&v2, CircleList_Length(list));
	CircleList_Insert(list, (CircleListNode*)&v3, CircleList_Length(list));
	CircleList_Insert(list, (CircleListNode*)&v4, CircleList_Length(list));
	
	/*for (i = 0; i<CircleList_Length(list); i++)
	{
		struct Value* pv = (struct Value*)CircleList_Next(list);
		//struct Value* pv1 = (struct Value*)CircleList_Current(list);
		//printf("current: %d\n", pv1->v);
		printf("%d\n", pv->v);
	}
	for (i = 0; i<2*CircleList_Length(list); i++)
	{
		struct Value* pv1 = (struct Value*)CircleList_Next(list);
		printf("%d\n", pv1->v);
	}*/


	//CircleList_Insert(list, (CircleListNode*)&v1, CircleList_Length(list));
	//CircleList_Insert(list, (CircleListNode*)&v2, CircleList_Length(list));
	//CircleList_Insert(list, (CircleListNode*)&v3, CircleList_Length(list));
	//CircleList_Insert(list, (CircleListNode*)&v4, CircleList_Length(list));
	CircleList_Insert(list, (CircleListNode*)&v5, CircleList_Length(list));
	CircleList_Insert(list, (CircleListNode*)&v6, CircleList_Length(list));
	CircleList_Insert(list, (CircleListNode*)&v7, CircleList_Length(list));
	CircleList_Insert(list, (CircleListNode*)&v8, CircleList_Length(list));

	for (i = 0; i<CircleList_Length(list); i++)
	{
		struct Value* pv1 = (struct Value*)CircleList_Get(list,i);
		printf("get: %d\n", pv1->v);
	}
    
	for (i = 0; i<CircleList_Length(list); i++)
	{
		struct Value* pv2 = (struct Value*)CircleList_Next(list);
		printf("%d\n", pv2->v);
	}

	CircleList_Destroy(list);
	system("pause");
	return 0;
}