/*
 * DoubleLinkList.c
 *
 *  Created on: Jan 17, 2021
 *      Author: eason
 */

#include "DoubleLinkList.h"

int DoubleLinkList_Init(double_link_list* header){
	if (header == NULL){
		return PARAMETER_ERROR;
	}

	header->data = 0;
	header->next = NULL;
	header->prior = NULL;
}

int DoubleLinkList_GetElem(double_link_list* header, uint32_t i, D_ElemType* e){
	if (header == NULL || e == NULL){
		return PARAMETER_ERROR;
	}

	double_link_list* p = header;
	uint32_t j = 0;

	while(p && j < i){
		p = p->next;
		j++;
	}

	// p == NULL || j == i
	if(!p){
		return FAILED;
	}

	*e = p->data;

	return PASS;
}

int DoubleLinkList_LocateElem(double_link_list* header, D_ElemType* e, uint32_t* locate){
	if (header == NULL || e == NULL || locate == NULL){
		return PARAMETER_ERROR;
	}

	double_link_list* p = header->next;
	uint32_t j = 1;

	while(p && (p->data != *e)){
		p = p->next;
		j++;
	}

	if(!p){
		return FAILED;
	}

	*locate = j;

	return PASS;
}

int DoubleLinkList_PriorInsert(double_link_list* p, D_ElemType* e){
	if (p == NULL || e == NULL){
		return PARAMETER_ERROR;
	}

	double_link_list* pointer = (double_link_list*)malloc(sizeof(double_link_list));
	if(!pointer){
		return MALLOC_ERROR;
	}

	pointer->data = *e;
	pointer->next = p;
	pointer->prior = p->prior;

	p->prior->next = pointer;
	p->prior = pointer;

	return PASS;
}

int DoubleLinkList_NextInsert(double_link_list* p, D_ElemType* e){
	if (p == NULL || e == NULL){
		return PARAMETER_ERROR;
	}

	double_link_list* pointer = (double_link_list*)malloc(sizeof(double_link_list));
	if(!pointer){
		return MALLOC_ERROR;
	}

	pointer->data = *e;
	pointer->next = p->next;
	pointer->prior = p;

	if(p->next){
		// p next != NULL
		p->next->prior = pointer;
	}

	p->next = pointer;

	return PASS;
}

int DoubleLinkList_NextDelete(double_link_list* p, D_ElemType* e){
	if (p == NULL || e == NULL || p->next == NULL){
		return PARAMETER_ERROR;
	}
	*e = p->next->data;
	// pointer to the delete item
	double_link_list* pointer = p->next;

	if(pointer->next){
		// not NULL
		pointer->next->prior = p;
	}

	p->next = pointer->next;

	free(pointer);

	return PASS;
}

int DoubleLinkList_Delete(double_link_list* p, D_ElemType* e){
	if (p == NULL || e == NULL){
		return PARAMETER_ERROR;
	}

	*e = p->data;
//	double_link_list* pointer = p->next;

	if(p->next){
		p->next->prior = p->prior;
	}

	p->prior->next = p->next;

	free(p);

	return PASS;
}


// direction = 1  backward search
// direction = -1 forward search
int DoubleLinkList_Search(double_link_list* header, D_ElemType* e, int direction){
	if(header == NULL || e == NULL){
		return PARAMETER_ERROR;
	}

	double_link_list* p = header;

	while(p && p->data != *e){
		if(direction == 1){
			p = p->next;
		}

		if(direction == -1){
			p = p->prior;
		}
	}

	return PASS;
}

