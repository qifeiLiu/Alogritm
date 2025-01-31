#include <stdio.h>
#include "BTree.h"
#include "LinkQueue.h"

struct Node
{
	BTreeNode header;
	char v;
};
void printf_data(BTreeNode* node)
{
	if (node != NULL)
	{
		printf("%c",((struct Node*)node)->v);
	}
}

void pre_order_traversal(BTreeNode* root)
{
	if (root != NULL)
	{
		struct Node* node = (struct Node*)root;
		printf("%c, ", node->v);

		pre_order_traversal(root->left);
		pre_order_traversal(root->right);
	}
}

void middle_order_traversal(BTreeNode* root)
{
	if (root != NULL)
	{
		struct Node* node = (struct Node*)root;
		middle_order_traversal(root->left);
		printf("%c, ", node->v);
		middle_order_traversal(root->right);
	}
}

void post_order_traversal(BTreeNode* root)
{
	if (root != NULL)
	{
		struct Node* node = (struct Node*)root;
		post_order_traversal(root->left);
		post_order_traversal(root->right);
		printf("%c, ", node->v);
	}
}

void level_order_traversal(BTreeNode* root)
{
	if (root != NULL)
	{
		LinkQueue* queue = LinkQueue_Create();
		if (queue != NULL)
		{
			LinkQueue_Append(queue, root);
			while (LinkQueue_Length(queue) > 0)
			{
				struct Node* node = (struct Node*)LinkQueue_Retrieve(queue);
				printf("%c, ", node->v);
				LinkQueue_Append(queue, node->header.left);
				LinkQueue_Append(queue, node->header.right);
			}
		}
		LinkQueue_Destroy(queue);
	}
}

int main(int argc,char *argv[])
{
	BTree* tree = BTree_Create();

	struct Node n1 = { {NULL,NULL},'A' };
	struct Node n2 = { { NULL, NULL }, 'B' };
	struct Node n3 = { { NULL, NULL }, 'C' };
	struct Node n4 = { { NULL, NULL }, 'D' };
	struct Node n5 = { { NULL, NULL }, 'E' };
	struct Node n6 = { { NULL, NULL }, 'F' };

	BTree_Insert(tree,(BTreeNode*)&n1,0,0,0);
	BTree_Insert(tree, (BTreeNode*)&n2, 0x00, 1, 0);
	BTree_Insert(tree, (BTreeNode*)&n3, 0x01, 1, 0);
	BTree_Insert(tree, (BTreeNode*)&n4, 0x00, 2, 0);
	BTree_Insert(tree, (BTreeNode*)&n5, 0x02, 2, 0);
	BTree_Insert(tree, (BTreeNode*)&n6, 0x02, 3, 0);

	printf("Pre Order Traversal:\n");
	pre_order_traversal(BTree_Root(tree));
	printf("\n");
	printf("Middle Order Traversal:\n");
	middle_order_traversal(BTree_Root(tree));
	printf("\n");
	printf("Post Order Traversal:\n");
	post_order_traversal(BTree_Root(tree));
	printf("\n");

	printf("Level Order Traversal:\n");
	level_order_traversal(BTree_Root(tree));
	printf("\n");
	//BTree_Display(tree, printf_data, 2, '-');

	//printf("Count:%d\n", BTree_Count(tree));
	//printf("Height:%d\n", BTree_Height(tree));
	//printf("Degree:%d\n", BTree_Degree(tree));
	//BTree_Delete(tree,0x00,1);
	//printf("After Delete B:\n");
	//printf("Count:%d\n", BTree_Count(tree));
	//printf("Height:%d\n", BTree_Height(tree));
	//printf("Degree:%d\n", BTree_Degree(tree));
	//BTree_Display(tree, printf_data, 2, '-');
	//printf("After Clear:\n");
	//BTree_Clear(tree);
	//printf("Count:%d\n", BTree_Count(tree));
	//printf("Height:%d\n", BTree_Height(tree));
	//printf("Degree:%d\n", BTree_Degree(tree));
	//BTree_Display(tree, printf_data, 2, '-');
	BTree_Destroy(tree);
	system("pause");
	return 0;
}