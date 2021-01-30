#include "public.h"

#include "LinkList.h"

//static int self_compare(ElemType* a, ElemType* b){
//	if (*a == *b){
//		return 0;
//	}
//
//	return -1;
//}

static link_list header;
static link_list header1;
static link_list header_merge;

int main(int argc, char const *argv[])
{
	LinkList_Init(&header);
	LinkList_Init(&header1);

	LL_ElemType temp = 0x55555555;
	LinkList_InsertElem(&header, 1, &temp);
	temp = 0x66666666;
	LinkList_InsertElem(&header, 1, &temp);
	temp = 0x77777777;
	LinkList_InsertElem(&header, 1, &temp);
	temp = 0x88888888;
	LinkList_InsertElem(&header, 1, &temp);
	temp = 0x11111111;
	LinkList_InsertElem(&header, 4, &temp);
	temp = 0x22222222;
	LinkList_InsertElem(&header, 6, &temp);
	uint32_t i = 1;
	while(LinkList_GetElem(&header, i, &temp) == 0){
		LOG("Number %d: 0x%x", i++, temp);
	}

	temp = 0x44444444;
	LinkList_InsertElem(&header1, 1, &temp);
	temp = 0xaaaaaaaa;
	LinkList_InsertElem(&header1, 1, &temp);
	temp = 0x77777777;
	LinkList_InsertElem(&header1, 1, &temp);
	temp = 0x35353535;
	LinkList_InsertElem(&header1, 1, &temp);
	temp = 0x55555555;
	LinkList_InsertElem(&header1, 4, &temp);
	i = 1;
	while(LinkList_GetElem(&header1, i, &temp) == 0){
		LOG("Number %d: 0x%x", i++, temp);
	}


	LinkList_Sort(&header, 1);
	LinkList_Sort(&header1, 1);
	LinkList_Merge(&header, &header1, &header_merge, 1);

	i = 1;
	while(LinkList_GetElem(&header_merge, i, &temp) == 0){
		LOG("Merge Number %d: 0x%x", i++, temp);
	}

	while(1);
}
