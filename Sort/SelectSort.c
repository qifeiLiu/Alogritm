#include <stdio.h>
#include <stdlib.h>

void println(int array[],int len)
{
	int i = 0;
	for(i=0;i<len;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
}
void swap(int array[],int i,int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

void SelectSort(int array[],int len)
{
	int i = 0;
	int j = 0;
	int k = -1;
	for(i=0;i<len;i++)
	{
		k = i;
		for(j=i+1;j<len;j++)
		{
			if(array[j]<array[k])
			{
				k = j;
			}
		}
		swap(array,i,k);
	}
}
void InsertationSort(int array[],int len)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int temp = -1;
	for(i=1;i<len;i++)
	{  
		k =  i;
		temp = array[k];
		for(j=i-1;(j>=0) && (array[j] > temp);j--)
		{
			array[j+1] = array[j];
			k = j;
		}
		array[k] = temp;
	}
}

void BubbleSort(int array[],int len)
{
	int i = 0;
	int j = 0;
	int exchange = 1;
	int times = 0;
	for( i= 0; i<len && exchange; i++)
	{
		exchange = 0;
	    for( j = len-1; j>i;j--)
	    {
		    if(array[j]<array[j-1])
		    {
			    swap(array,j,j-1);
			    exchange = 1;
		    }
	    }
	    times ++;
    }
    printf("times:%d\n",times);
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int array[] = {2,3,21,25,49,25,16,8,3};
	int len = sizeof(array)/sizeof(*array);
	println(array,len);
	//swap(array,0,3);
	//println(array,len);
	//InsertationSort(array,len);
	BubbleSort(array,len);
	println(array,len);
	return 0;
}
