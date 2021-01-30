#include "LinearList.h"
// Note: because the specific of linear list, the first
// element insert into the list item must be start with
// 0
// [1, 2, 3, 4, 5]  -> length = 5

int LinearList_Init(linear_list* L){
	L->base = (ElemType *)\
	malloc(LINEAR_LIST_INIT_SIZE * sizeof(ElemType));

	if(L->base == NULL){
		return false;
	}

	L->length = 0;
	L->listsize = LINEAR_LIST_INIT_SIZE;

	return true;
}

int LinearList_Destroy(linear_list* L){
	if(L == NULL){
		return false;
	}

	free(L->base);
	L->base = NULL;
	L->length = 0;
	L->listsize = 0;

	return true;
}

int LinearList_Full(linear_list* L){
	if(L->length == L->listsize){
		return true;
	}

	return false;
}

int LinearList_Empty(linear_list* L){
	if(L->length == 0){
		return true;
	}

	return false;
}

int LinearList_Append(linear_list* L, ElemType e){
	if (L == NULL){
		return false;
	}

		// list full
	if (LinearList_Full(L)){
		// realloc new list buffer
		ElemType* newbase = (ElemType *)\
		realloc(L->base, (LINEAR_LIST_INIT_SIZE + LINEAR_LIST_INCREMENT)\
	 	* sizeof(ElemType));

		if (newbase == NULL){
			return false;
		}

		L->base = newbase;
		L->listsize += LINEAR_LIST_INCREMENT;
	}

	L->base[L->length++] = e;

	return true;
}

int LinearList_GetElem(linear_list* L, uint32_t i, ElemType* e){
	if (L == NULL || e == NULL || i < 1 || i > L->length || LinearList_Empty(L)){
		return false;
	}

	*e = L->base[i-1];

	return true;
}

int LinearList_ListLength(linear_list* L){
	if (L == NULL){
		return false;
	}

	return L->length;
}

// Insert a new element before the number i
int LinearList_Insert(linear_list* L, uint32_t i,\
ElemType e){
	if (i < 1 || i > (L->length + 1) || L == NULL){
		return false;
	}

	// list full
	if (LinearList_Full(L)){
		// realloc new list buffer
		ElemType* newbase = (ElemType *)\
		realloc(L->base, (LINEAR_LIST_INIT_SIZE + LINEAR_LIST_INCREMENT)\
	 	* sizeof(ElemType));

		if (newbase == NULL){
			return false;
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

	return true;
}

int LinearList_Delete(linear_list* L, uint32_t i, ElemType* e){
	if(L == NULL || i < 1 || i > L->length){
		return false;
	}

	ElemType* pointer = &L->base[i - 1];
	if (e != NULL){
		*e = *pointer;
	}

	for(; pointer < &L->base[L->length - 1]; pointer++){
		*pointer = *(pointer + 1);
	}

	L->length--;

	return true;
}

int LinearList_LocateElem(linear_list* L, ElemType* e, int(*b_f)(ElemType* a, ElemType* b)){
	if(L == NULL || b_f == NULL){
		return false;
	}

	uint32_t i = 0;
	for(i = 0; i < L->length; i++){
		if (b_f(e, &L->base[i]) == 0){
			return i+1;
		}
	}

	return false;
}

// order = 1 mean ascending order
// order = -1 mean descending order
// bubble sort
int LinearList_Sort(linear_list* L, int order){
	ElemType temp;
	uint32_t i = 0;
	uint32_t j = 0;
	if (L == NULL){
		return false;
	}

	for(i = L->length - 1; i > 0; i--){
		for(j = 0; j < i; j++){

			if (order == 1){
				if (L->base[j] > L->base[j+1]){
					temp = L->base[j];
					L->base[j] = L->base[j+1];
					L->base[j+1] = temp;
				}
			}

			if (order == -1){
				if (L->base[j] < L->base[j+1]){
					temp = L->base[j];
					L->base[j] = L->base[j+1];
					L->base[j+1] = temp;
				}
			}
		}
	}

	return true;
}

int LinearList_Merge(linear_list* L0, linear_list* L1, linear_list* L_Merge, int order){
	if (L0 == NULL || L1 == NULL || L_Merge == NULL){
		return false;
	}
	LinearList_Sort(L0, order);
	LinearList_Sort(L1, order);

	if (LinearList_Init(L_Merge) != true){
		return false;
	}
	uint32_t p_l0 = 0;
	uint32_t p_l1 = 0;

	while ((p_l0 < L0->length) && (p_l1 < L1->length)){
		if (L0->base[p_l0] > L1->base[p_l1]){
			if (order == 1){
				LinearList_Append (L_Merge, L1->base[p_l1++]);
			}
			if (order == -1){
				LinearList_Append (L_Merge, L0->base[p_l0++]);
			}
		}else{
			if (order == 1){
				LinearList_Append (L_Merge, L0->base[p_l0++]);
			}
			if (order == -1){
				LinearList_Append (L_Merge, L1->base[p_l1++]);
			}
		}
	}

	while (p_l0 < L0->length){
		LinearList_Append (L_Merge, L0->base[p_l0++]);
	}

	while (p_l1 < L1->length){
		LinearList_Append (L_Merge, L1->base[p_l1++]);
	}

	return true;
}










