#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

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


void ShellSort(int array[],int len)
{
	int i = 0;
	int j = 0;
	int k = -1;
	int temp = -1;
	int gap = len;
	
	do
	{
		gap = gap /3 + 1;
		for(i=gap;i<len;i+=gap)
		{
			k = i;
			temp = array[k];
			for(j=i-gap;(j>=0)&&(array[j]>temp);j-=gap)
			{
				array[j+gap] = array[j];
				k = j;
			}
			array[k] = temp;
		}
		
	}while(gap > 1);
}

int partition(int array[],int low, int high)
{
	int pv = array[low];
	while(low < high)
	{
		while((low < high) && (array[high] >= pv))
		{
			high --;
		}
		swap(array,low,high);
		while((low < high) && (array[low] <= pv))
		{
			low ++; 
		}
		swap(array,low,high);
	}
	return low;
}
void QSort(int array[],int low,int high) //O(n*logn)
{
	if( low < high)
	{
		int pivot = partition(array,low,high);
		QSort(array,low,pivot-1);
		QSort(array,pivot+1,high);
	}

}
void QuickSort(int array[],int len)
{
	QSort( array,0,len-1);
}

void Merge( int src[],int des[],int low,int mid,int high)
{
	int i = low;
	int j = mid + 1;
	int k = low;
	
	while((i <= mid) && (j <= high))
	{
		if(src[i] < src[j])
		{
			des[k++] = src[i++];
		}
		else
		{
			des[k++] = src[j++];
		}
	}
	while(i <= mid)
	{
		des[k++] = src[i++];
	}
	while(j <= high)
	{
		des[k++] = src[j++];
	}
}
void MSort(int src[],int des[],int low, int high,int max)
{
	if( low == high)
	{
		des[low] = src[low];
	}
	else
	{
		int mid = (low+high)/2;
		int* space = (int*)malloc(sizeof(int)*max);
		if(space != NULL)
		{
			MSort(src,space,low,mid,max);
			MSort(src,space,mid+1,high,max);
			Merge(space,des,low,mid,high);
		}
		free(space);
	}
}
void MergeSort(int array[],int len)
{
	MSort(array,array,0,len-1,len);
	
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int array[] = {10,3,21,25,49,25,16,8,3};
	int len = sizeof(array)/sizeof(*array);
	printf("len:%d\n",len);
	println(array,len);
	//swap(array,0,3);
	//println(array,len);
	//InsertationSort(array,len);
	//BubbleSort(array,len);
	//ShellSort(array,len);
	QuickSort(array,len);
	//MergeSort(array,len);
	println(array,len);
	return 0;
}
