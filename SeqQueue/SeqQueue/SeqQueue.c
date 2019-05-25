#include "../Seqlist.h"
#include "SeqQueue.h"

SeqQueue* SeqQueue_Create(int capacity) // O(1)
{
	return Seqlist_Create(capacity);
}

void SeqQueue_Destroy(SeqQueue* queue) // O(1)
{
	Seqlist_Destory(queue);
}

void SeqQueue_Clear(SeqQueue* queue) // O(1)
{
	Seqlist_Clear(queue);
}

int SeqQueue_Append(SeqQueue* queue, void* item) // O(1)
{
	return Seqlist_Insert(queue, item, Seqlist_Length(queue));
}

void* SeqQueue_Retrieve(SeqQueue* queue) // O(n)
{
	return Seqlist_Delete(queue, 0);
}

void* SeqQueue_Header(SeqQueue* queue) // O(1) 
{
	return Seqlist_Get(queue, 0);
}

int SeqQueue_Length(SeqQueue* queue) // O(1)
{
	return Seqlist_Length(queue);
}

int SeqQueue_Capacity(SeqQueue* queue) // O(1)
{
	return Seqlist_Capacity(queue);
}
