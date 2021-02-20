/*
 * LinkBiTree.c
 *
 *  Created on: Feb 19, 2021
 *      Author: eason
 */

#include "LinkBiTree.h"

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

static int static_search_func(link_bi_tree* object, link_bi_tree* target){

}

int LinkBiTree_Parent(link_bi_tree_header* header, link_bi_tree* e){
	if (!header && !e){
		return false;
	}

}

int LinkBiTree_LeftChild(link_bi_tree_header* header, link_bi_tree* e){
	if (!e){
		return false;
	}

	return e->l_tree;
}

int LinkBiTree_RightChild(link_bi_tree_header* header, link_bi_tree* e){
	if (!e){
		return false;
	}

	return e->r_tree;
}

int LinkBiTree_PreOrderTraverse(link_bi_tree* root, traverse_func func){

	func(root);
	LinkBiTree_PreOrderTraverse(root->l_tree, func);
	LinkBiTree_PreOrderTraverse(root->r_tree, func);

	return true;
}

int LinkBiTree_InOrderTraverse(link_bi_tree_header* header, traverse_func func){

}

int LinkBiTree_PostOrderTraverse(link_bi_tree_header* header, traverse_func func){

}

// use queue
// in the first, push the root element into the queue, when
// element pop from queue, push it's children into the queue
// until the queue is empty

int LinkBiTree_LevelOrderTraverse(link_bi_tree_header* header, traverse_func func){

}

