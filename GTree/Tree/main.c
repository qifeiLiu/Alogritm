#include <stdio.h>
#include <stdlib.h>
#include "Gtree.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void printf_data(GTreeData* data)
{
	printf("%c", (int)data);
}

int main(int argc, char *argv[]) {
	int i = 0;
	GTree* tree = GTree_Create();
	GTree_Insert(tree, (GTreeData*)'A', -1);
	GTree_Insert(tree, (GTreeData*)'B', 0);
	GTree_Insert(tree, (GTreeData*)'C', 0);
	GTree_Insert(tree, (GTreeData*)'D', 0);
	GTree_Insert(tree, (GTreeData*)'X', 0);
	GTree_Insert(tree, (GTreeData*)'E', 1);
	GTree_Insert(tree, (GTreeData*)'F', 1);
	GTree_Insert(tree, (GTreeData*)'H', 3);
	GTree_Insert(tree, (GTreeData*)'I', 3);
	GTree_Insert(tree, (GTreeData*)'J', 3);

	printf("Height:\n");
	printf("%d\n", GTree_Height(tree));

	printf("Degree:\n");
	printf("%d\n", GTree_Degree(tree));

	printf("Full Tree:\n");
	GTree_Display(tree, printf_data, 1, '*');
	printf("Get Tree Data:\n");
	for (i = 0; i<GTree_Count(tree); i++)
	{
		printf_data(GTree_Get(tree, i));
		printf("\n");
	}
	GTree_Delete(tree, 3);
	printf("After Deleting 3:\n");
	GTree_Display(tree, printf_data, 1, '-');
	printf("Get Root Data:\n");
	printf_data(GTree_Root(tree));


	//GTree_Destory(tree);
	//system("pause");
	return 0;
}