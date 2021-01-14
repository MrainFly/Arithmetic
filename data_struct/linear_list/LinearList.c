#include "LinearList.h"
// Note: because the specific of linear list, the first
// element insert into the list item must be start with
// 0
// [1, 2, 3, 4, 5]  -> length = 5

int LinearList_Init(linear_list* L){
	L->base = (ElemType *)\
	malloc(LINEAR_LIST_INIT_SIZE * sizeof(ElemType));

	if(L->base == NULL){
		return MALLOC_ERROR;
	}

	L->length = 0;
	L->listsize = LINEAR_LIST_INIT_SIZE;

	return PASS;
}

int LinearList_Destroy(linear_list* L){
	if(L == NULL){
		return PARAMETER_ERROR;		
	}

	free(L->base);
	L->base = NULL;
	L->length = 0;
	L->listsize = 0;

	return PASS;
}

int LinearList_Append(linear_list* L, ElemType e){
	if (L == NULL){
		return PARAMETER_ERROR;
	}

		// list full
	if (L->length == L->listsize){
		// realloc new list buffer
		ElemType* newbase = (ElemType *)\
		realloc(L->base, (LINEAR_LIST_INIT_SIZE + LINEAR_LIST_INCREMENT)\
	 	* sizeof(ElemType));

		if (newbase == NULL){
			return MALLOC_ERROR;
		}

		L->base = newbase;
		L->listsize += LINEAR_LIST_INCREMENT;
	}

	L->base[L->length++] = e;

	return PASS;
}

int LinearList_GetElem(linear_list* L, uint32_t i, ElemType* e){
	if (L == NULL || e == NULL || i < 1 || i > L->length){
		return PARAMETER_ERROR;
	}

	*e = L->base[i-1];

	return PASS;
}

int LinearList_ListLength(linear_list* L){
	if (L == NULL){
		return PARAMETER_ERROR;
	}

	return L->length;
}

// Insert a new element before the number i
int LinearList_Insert(linear_list* L, uint32_t i,\
ElemType e){
	if (i < 1 || i > (L->length + 1) || L == NULL){
		return PARAMETER_ERROR;
	}

	// list full
	if (L->length == L->listsize){
		// realloc new list buffer
		ElemType* newbase = (ElemType *)\
		realloc(L->base, (LINEAR_LIST_INIT_SIZE + LINEAR_LIST_INCREMENT)\
	 	* sizeof(ElemType));

		if (newbase == NULL){
			return MALLOC_ERROR;
		}

		L->base = newbase;
		L->listsize += LINEAR_LIST_INCREMENT;
	}

	// point the last element
	ElemType* pointer = &L->base[L->length - 1];
	int j = 0;
	for(; (j < L->length - i + 1); j++){
		*(pointer + 1) = *pointer;		
		pointer--;
	}
	L->base[i-1] = e;

	L->length++;

	return PASS;
}

int LinearList_Delete(linear_list* L, uint32_t i, ElemType* e){
	if(L == NULL || i < 1 || i > L->length){
		return PARAMETER_ERROR;
	}

	ElemType* pointer = &L->base[i - 1];
	if (e != NULL){
		*e = *pointer;
	}

	for(; pointer < &L->base[L->length - 1]; pointer++){
		*pointer = *(pointer + 1);
	}

	L->length--;

	return PASS;
}

int LinearList_LocateElem(linear_list* L, ElemType* e, int(*b_f)(ElemType* a, ElemType* b)){
	if(L == NULL || b_f == NULL){
		return PARAMETER_ERROR;
	}

	uint32_t i = 0;
	for(i = 0; i < L->length; i++){
		if (b_f(e, &L->base[i]) == 0){
			return i+1;
		}
	}

	return FAILED;
}














