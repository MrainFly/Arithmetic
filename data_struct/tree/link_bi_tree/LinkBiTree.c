/*
 * LinkBiTree.c
 *
 *  Created on: Feb 19, 2021
 *      Author: eason
 */

#include "LinkBiTree.h"

uint32_t LinkBiTree_MallocSize = 0;

int LinkBiTree_Init(link_bi_tree_header* header){
	if (header == NULL){
		return false;
	}

	header->depth = 0;
	header->node = 0;
	header->root = NULL;

	return true;
}

/*
int LinkBiTree_Create(link_bi_tree_header* header, LinkBiTree_ElemType data){
	if (header == NULL){
		return false;
	}

	if (!header->root){
		header->root = malloc(sizeof(link_bi_tree));
		if (!header->root){
			// malloc failture
			return false;
		}
		header->root
	}
}*/

int LinkBiTree_Destroy(link_bi_tree_header* header){
	if (header == NULL){
		return false;
	}

	header->depth = 0;
	header->node = 0;
	header->root = NULL;

	return true;
}

static link_bi_tree* LocateTreeItem = NULL;
int LinkBiTree_CompareFunc(link_bi_tree* object){
	return (object == LocateTreeItem) ? true : false;
}


int LinkBiTree_InTree(link_bi_tree_header* header, link_bi_tree* e){
	LocateTreeItem = e;
	return LinkBiTree_PreOrderTraverse(header->root, LinkBiTree_CompareFunc);
}

int LinkBiTree_PreCompareFunc(link_bi_tree* object){

	if (object->l_tree == LocateTreeItem || object->r_tree == LocateTreeItem){
		return object;
	}

	return
}
link_bi_tree* LinkBiTree_Parent(link_bi_tree_header* header, link_bi_tree* e){
	if (!header && !e){
		return false;
	}

	return true;
}

link_bi_tree* LinkBiTree_LeftChild(link_bi_tree* e){
	if (!e){
		return false;
	}

	return e->l_tree;
}

link_bi_tree* LinkBiTree_RightChild(link_bi_tree* e){
	if (!e){
		return false;
	}

	return e->r_tree;
}

void* LinkBiTree_GetValue(link_bi_tree* e){
	if (!e){
		return false;
	}

	return e->data;
}

int LinkBiTree_PreOrderTraverse(link_bi_tree* root, traverse_func func){

	if(!root){
		// root NULL
		return true;
	}
	func(root);

	LinkBiTree_PreOrderTraverse(root->l_tree, func);
	LinkBiTree_PreOrderTraverse(root->r_tree, func);

	return true;
}

int LinkBiTree_InOrderTraverse(link_bi_tree* root, traverse_func func){
	if(!root){
		// root NULL
		return true;
	}

	LinkBiTree_PreOrderTraverse(root->l_tree, func);
	func(root);
	LinkBiTree_PreOrderTraverse(root->r_tree, func);

	return true;
}

int LinkBiTree_PostOrderTraverse(link_bi_tree* root, traverse_func func){
	if(!root){
		// root NULL
		return true;
	}

	LinkBiTree_PreOrderTraverse(root->l_tree, func);
	LinkBiTree_PreOrderTraverse(root->r_tree, func);
	func(root);

	return true;
}

// use queue
// in the first, push the root element into the queue, when
// element pop from queue, push it's children into the queue
// until the queue is empty

int LinkBiTree_LevelOrderTraverse(link_bi_tree_header* header, traverse_func func){

}

