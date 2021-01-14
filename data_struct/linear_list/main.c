#include "public.h"

#include "LinearList.h"

static linear_list L;

static int self_compare(ElemType* a, ElemType* b){
	if (*a == *b){
		return 0;
	}

	return -1;
}

int main(int argc, char const *argv[])
{
	LinearList_Init(&L);
	LinearList_Append(&L, 8);
	LOG("Current list length: %d", LinearList_ListLength(&L));
	LinearList_Append(&L, 9);
	LOG("Current list length: %d", LinearList_ListLength(&L));
	LinearList_Append(&L, 10);
	LOG("Current list length: %d", LinearList_ListLength(&L));
	LinearList_Append(&L, 11);
	LOG("Current list length: %d", LinearList_ListLength(&L));
	LinearList_Append(&L, 12);
	LOG("Current list length: %d", LinearList_ListLength(&L));
	ElemType _cur;
	LinearList_GetElem(&L, 2, &_cur);
	LOG("The item 2 : %d", _cur);
	LinearList_Insert(&L, 3, 0x55555555);
	LinearList_Insert(&L, L.length + 1, 0x66666666);
	int locate = 0;
	ElemType target = 10;
	// find
	locate = LinearList_LocateElem(&L, &target, self_compare);
	LOG("The locate: %d", locate);

	// break
	LinearList_Insert(&L, L.length + 2, 0x66666666);

	LinearList_Delete(&L, 5, NULL);

	LinearList_Destroy(&L);
	return 0;
}
