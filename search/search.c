#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "LinkList.h"
#define SIZE 20

void print_array(int a[],int len)
{
    int i = 0;
    for(i=0;i <len;i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n");

}

int static_search(int a[],int len, int key)
{
    int ret = -1;
    int i = 0;

    for(i=0;i < len;i++)
    {
	if(a[i] == key)
	{
	    ret = i;
	    break;
	}
    }
    return ret;
}

int main(int argc,char *argv[])
{
    int a[SIZE] = {0};
    int i = 0;
    int key = 0;
    int index = 0;

    srand((unsigned int)time(NULL));

    for(i=0;i<SIZE;i++)
    {
	a[i] = rand() % 100;
    }

    key = rand() % 100;
    printf("Key: %d\n",key);
    printf("Array: \n");
    print_array(a,SIZE);

    index = static_search(a, SIZE,key);
    if(index >= 0)
    {
	printf("Success: a[%d] = %d\n", index , a[index]);
    }
    else
    {
       printf("Failed!\n");
    }

}
