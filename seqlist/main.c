#include <stdio.h>
#include "seqlist.h"

int main(int argc,char *argv[])
{
	int index = 0;
	SeqList* List = Seqlist_Create(5);
	Seqlist_Insert(List, 0, 0);
	Seqlist_Insert(List, 1, 0);
	Seqlist_Insert(List, 2, 0);
	Seqlist_Insert(List, 3, 0);
	Seqlist_Insert(List, 4, 0);
	Seqlist_Insert(List, 5, 0);
	for (index = 0; index < Seqlist_Length(List); index++)
	{
		printf("%d\n", Seqlist_Get(List, index));
	}

	printf("delete:%d\n", Seqlist_Delete(List, 0));
	printf("delete:%d\n", Seqlist_Delete(List, 0));

	for (index = 0; index < Seqlist_Length(List); index++)
	{
		printf("%d\n", Seqlist_Get(List, index));
	}
	system("pause");
	return 0;
}