#ifndef LINK_LIST_LINKLIST_H_
#define LINK_LIST_LINKLIST_H_

#include "inner.h"

typedef uint32_t LL_ElemType;

typedef struct __link_list {
	LL_ElemType         data;
	struct __link_list* next;
}link_list;

int LinkList_Init(link_list* header);

int LinkList_GetElem(link_list* header, uint32_t i, LL_ElemType* e);

int LinkList_LocateElem(link_list* header, LL_ElemType* e, uint32_t* locate);

int LinkList_Length(link_list* header);

int LinkList_InsertElem(link_list* header, int i, LL_ElemType* e);

int LinkList_DeleteElem(link_list* header, int i, LL_ElemType* e);

int LinkList_Sort(link_list* header, int order);

int LinkList_Merge(link_list* L0, link_list* L1, link_list* L_Merge, int order);

int LinkList_PriorInsert(link_list* p, LL_ElemType* e);

#endif
