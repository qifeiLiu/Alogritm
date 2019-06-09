#include <stdio.h>
#include "BTree.h"
#include "seqlist.h"

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


void thread_via_left(BTreeNode* root,BTreeNode** pp)
{
	if ((root != NULL) && (pp != NULL))
	{
		if (*pp != NULL)
		{
			(*pp)->left = root;
			(*pp) = NULL;
		}
		if (root->left == NULL)
		{
			*pp = root;
		}
		thread_via_left(root->left,pp);
		thread_via_left(root->right,pp);
	}
}

void thread_via_list(BTreeNode* root, SeqList* list)
{
	if ((root != NULL) && (list != NULL))
	{
		Seqlist_Insert(list, (SeqListNode*)root, Seqlist_Length(list));

		thread_via_list(root->left,list);
		thread_via_list(root->right, list);
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

int main(int argc,char *argv[])
{
	BTreeNode* p = NULL;
	BTree* tree = BTree_Create();
	BTreeNode* current = NULL;
	int i = 0;
	SeqList* list = NULL;

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


	list = Seqlist_Create(BTree_Count(tree));

	thread_via_list(BTree_Root(tree), list);
	for (i = 0; i < Seqlist_Length(list); i++)
	{
		printf("%c, ", ((struct Node*)Seqlist_Get(list,i))->v);
	}
	
	/*current = BTree_Root(tree);
	thread_via_left(current,&p);
	while (current != NULL)
	{
		printf("%c, ",((struct Node*)current)->v);
		current = current->left;
	}
	printf("\n");*/


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