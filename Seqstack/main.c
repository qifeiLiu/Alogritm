#include <stdio.h>
#include "Seqstack.h"

int main(int argc,char *argv[])
{
	//SeqList* SeqList =  SeqList_Create(8);
	//SeqList_Insert(SeqList, 1, 0);
	//SeqList_Insert(SeqList, 2, 7);
	//SeqList_Insert(SeqList, 3, 7);
	//SeqList_Insert(SeqList, 4, 7);
	//SeqList_Insert(SeqList, 5, 7);
	//SeqList_Display(SeqList);
	//printf("Seq_Capacity:%d\n", SeqList_Capacity(SeqList));
	//printf("Seq_Length:%d\n", SeqList_Length(SeqList));
	//printf("Position:%d,Value:%d\n",2,SeqList_Get(SeqList, 2));
	//SeqList_Delete(SeqList, 2);
	//SeqList_Display(SeqList);
	//SeqList_Clear(SeqList);
	//SeqList_Display(SeqList);
	//printf("Seq_Capacity:%d\n", SeqList_Capacity(SeqList));
	//printf("Seq_Length:%d\n", SeqList_Length(SeqList));
	//SeqList_Destory(SeqList);
	SeqStack* stack = SeqStack_Create(8);
	SeqStack_Push(stack, 1);
	SeqStack_Push(stack, 2);
	SeqStack_Display(stack);
	SeqStack_Pop(stack);
	//SeqStack_Display(stack);
	printf("Top:%d\n",SeqStack_Top(stack));
	SeqStack_Clear(stack);// This is a bug ,when Stack has been cleared
	printf("Top:%d\n", SeqStack_Top(stack));//This still been shown when stack been cleared.
	system("pause");
	return 0;
}