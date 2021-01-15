#ifndef LINK_LIST_LINKLIST_H_
#define LINK_LIST_LINKLIST_H_

#include "inner.h"

typedef int LL_ElemType;

typedef struct __link_list {
	LL_ElemType         data;
	struct __link_list* next;
}link_list;

typedef struct __header_link_list {
	uint32_t            length;
	struct __link_list* next;
}header_link_list;

#endif