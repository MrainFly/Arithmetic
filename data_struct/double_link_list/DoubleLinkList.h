/*
 * DoubleLinkList.h
 *
 *  Created on: Jan 17, 2021
 *      Author: eason
 */

#ifndef DATA_STRUCT_DOUBLE_LINK_LIST_DOUBLELINKLIST_H_
#define DATA_STRUCT_DOUBLE_LINK_LIST_DOUBLELINKLIST_H_

#include "inner.h"

typedef int D_ElemType;

typedef struct __double_link_list {
	D_ElemType data;
	struct __double_link_list* prior, *next;
}double_link_list;

#endif /* DATA_STRUCT_DOUBLE_LINK_LIST_DOUBLELINKLIST_H_ */
