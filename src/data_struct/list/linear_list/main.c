#include "public.h"

#include "LinearList.h"

#define L0_SIZE     (15)
#define L1_SIZE     (12)

static linear_list L0;
static linear_list L1;
static linear_list L_Merge;

static int self_compare(ElemType* a, ElemType* b){
	if (*a == *b){
		return 0;
	}

	return -1;
}

int main(int argc, char const *argv[])
{
	/*LinearList_Init(&L);
	LinearList_Append(&L, 9);
	LOG("Current list length: %d", LinearList_ListLength(&L));
	LinearList_Append(&L, 10);
	LOG("Current list length: %d", LinearList_ListLength(&L));
	LinearList_Append(&L, 11);
	LOG("Current list length: %d", LinearList_ListLength(&L));
	LinearList_Append(&L, 12);
	LOG("Current list length: %d", LinearList_ListLength(&L));
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
	LinearList_Sort(&L, -1);
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

	LinearList_Destroy(&L);*/
	srand(time(NULL));

	int i = 0;
	LinearList_Init(&L0);
	for(; i < L0_SIZE; i++){
		LinearList_Append(&L0, rand());
	}
	LinearList_Init(&L1);
	for(i = 0; i < L1_SIZE; i++){
		LinearList_Append(&L1, rand());
	}

	LinearList_Merge(&L0, &L1, &L_Merge, 1);

	return 0;
}
