#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define SIZE 20

void print_array(int a[],int begin,int end)
{
    int i = 0;
    for(i=begin;i <end;i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n");

}


int another_search(int a[],int len, int key)
{
    int ret = len;
    /*
    for(i=begin;i < end;i++)
    {
	if(a[i] == key)
	{
	    ret = i;
	    break;
	}
    }*/
    a[0] = key;

    while(a[ret] != key)
    {
         ret--;
    }
    return ret;
}


int main(int argc,char *argv[])
{
    int a[SIZE + 1] = {0};
    int i = 0;
    int key = 0;
    int index = 0;

    srand((unsigned int)time(NULL));

    for(i=1;i<SIZE;i++)
    {
	a[i] = rand() % 100;
    }

    key = rand() % 100;

    printf("Another Search Demo");
    printf("Key: %d\n",key);
    printf("Array: \n");
    print_array(a,0,SIZE);

    index = another_search(a,SIZE,key);
    if(index > 0)
    {
	printf("Success: a[%d] = %d\n", index , a[index]);
    }
    else
    {
       printf("Failed!\n");
    }
    
}
