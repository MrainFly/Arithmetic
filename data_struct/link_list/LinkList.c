#include "LinkList.h"

int LinkList_Init(header_link_list* header){
	if (header == NULL){
		return PARAMETER_ERROR;
	}

	header->length = 0;
	header->next = NULL;

	return PASS;
}

int LinkList_GetElem(header_link_list* header,\
 uint32_t i, LL_ElemType* e){
	if(header->next == NULL || i > header->length){
		return PARAMETER_ERROR;
	}

	link_list* p = header->next;
	uint32_t j = 1;
	while(j < i){
		p = p->next;
		j++
	}
	*e = p->data;

	return PASS;
}