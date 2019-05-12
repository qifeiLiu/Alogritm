#include "LinkStack.h"
#include <stdio.h>
#include <stdlib.h>



int main()
{

	int a[2] = { 1,2 };
	LinkStack* stack = LinkStack_Create();
	printf("Length:%d\n", LinkStack_Size(stack));
	LinkStack_Push(stack, &a[0]);
	printf("Length:%d\n", LinkStack_Size(stack));
	LinkStack_Push(stack, &a[1]);
	printf("Length:%d\n", LinkStack_Size(stack));
	printf("Pop:%d\n", *(int*)LinkStack_Pop(stack));
	printf("Length:%d\n", LinkStack_Size(stack));
	printf("Pop:%d\n", *(int*)LinkStack_Pop(stack));
	printf("Length:%d\n", LinkStack_Size(stack));

	system("pause");
	return 0;
}