#include <stdio.h>
#include "SeqQueue\SeqQueue.h"

int main(int argc,char *argv[])
{
	SeqQueue* queue;
	queue = SeqQueue_Create(5);
	int a[5] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		a[i] = i+2 ;
		SeqQueue_Append(queue, a + i);
	}
	printf("Header: %d\n", *(int*)SeqQueue_Header(queue));
	printf("Length: %d\n", SeqQueue_Length(queue));
	printf("Capacity: %d\n", SeqQueue_Capacity(queue));
	while (SeqQueue_Length(queue) > 0)
	{
		printf("Retrieve: %d\n", *(int*)SeqQueue_Retrieve(queue));
	}
	SeqQueue_Destroy(queue);
	system("pause");
	return 0;
}