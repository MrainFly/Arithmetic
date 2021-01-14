#ifndef LINEAR_LIST_LINEARLIST_H_
#define LINEAR_LIST_LINEARLIST_H_

#include "inner.h"

typedef int ElemType;

#define LINEAR_LIST_INIT_SIZE           (100)
#define LINEAR_LIST_INCREMENT           (10)

typedef struct __linear_list {
	ElemType * base;
	int        length;    // store size
	int        listsize;  // list total size
}linear_list;

int LinearList_Init(linear_list* L);
int LinearList_Destroy(linear_list* L);
int LinearList_Append(linear_list* L, ElemType e);
int LinearList_GetElem(linear_list* L, uint32_t i, ElemType* e);
int LinearList_ListLength(linear_list* L);
int LinearList_Insert(linear_list* L, uint32_t i, ElemType e);
int LinearList_Delete(linear_list* L, uint32_t i, ElemType* e);
int LinearList_LocateElem(linear_list* L, ElemType* e, int(*b_f)(ElemType* a, ElemType* b));

#endif
