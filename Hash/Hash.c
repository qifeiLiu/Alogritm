#include <stdio.h>
#include <malloc.h>
#include "Hash.h"
#include "BSTree.h"

typedef struct _tag_HashNode Hash_Node;
struct _tag_HashNode
{
	BSTreeNode header;
	HashValue* value;

};

void recursive_clear(BSTreeNode* node)
{
    if(node != NULL)
    {
	    recursive_clear(node->left);
	    recursive_clear(node->right);
	    free(node);
    }
}
Hash* Hash_Create()
{
    return BSTree_Create();
}

void Hash_Destory(Hash* hash)
{
  Hash_Clear(hash);
  BSTree_Destroy(hash);
}

void Hash_Clear(Hash* hash)
{
    recursive_clear(BSTree_Root(hash));
    BSTree_Clear(hash);
}

int Hash_Add(Hash* hash,HashKey* key,HashValue* value,Hash_Compare* compare)
{
    int ret = 0;
    Hash_Node* node = (Hash_Node*)malloc(sizeof(Hash_Node));
    if( ret = (node != NULL))
    {
        node->header.key = key;
	node->value = value;

	ret = BSTree_Insert(hash,(BSTreeNode*)node,compare);
	if( !ret)
	{
	    free(node);	
	}
    }
    return ret;
}

HashValue* Hash_Remove(Hash* hash,HashKey* key,Hash_Compare* compare)
{
	HashValue* ret = NULL;
	Hash_Node* node = (Hash_Node*)BSTree_Delete(hash,key,compare);
	if( node != NULL)
	{
		ret = node->value;
		free(node);
	}
	return ret;
}

HashValue* Hash_Get(Hash* hash,HashKey* key,Hash_Compare* compare)
{
	HashValue* ret = NULL;
	Hash_Node* node = (Hash_Node*)BSTree_Get(hash,key,compare);
	if( node != NULL)
	{
		ret = node->value;
		free(node);
	}
	
	return ret;
}
int Hash_Count(Hash* hash)
{

 return  BSTree_Count(hash);
}
