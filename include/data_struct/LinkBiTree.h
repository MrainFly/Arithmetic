/*
 * LinearTree.h
 *
 *  Created on: Feb 19, 2021
 *      Author: eason
 */

#ifndef INCLUDE_DATA_STRUCT_LINKBITREE_H_
#define INCLUDE_DATA_STRUCT_LINKBITREE_H_

#include "inner.h"

typedef int LinkBiTree_ElemType;

typedef struct __link_bi_tree{
	LinkBiTree_ElemType data;
	struct __link_bi_tree* l_tree, r_tree;
} link_bi_tree;

typedef struct __link_bi_tree_header{
	uint32_t node;
	uint32_t depth;
	link_bi_tree* root;
} link_bi_tree_header;

typedef int traverse_func(link_bi_tree* object);

#endif /* INCLUDE_DATA_STRUCT_LINKBITREE_H_ */
