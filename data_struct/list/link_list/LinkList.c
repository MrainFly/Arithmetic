#include "LinkList.h"

int LinkList_Init(link_list* header){
	if (header == NULL){
		return false;
	}

	header->next = NULL;

	return true;
}

int LinkList_GetElem(link_list* header,\
 uint32_t i, LL_ElemType* e){
	if(header == NULL){
		return false;
	}

	link_list* p = header;
	uint32_t j = 0;
	while(p && j < i){
		p = p->next;
		j++;
	}

	// j==i || p==NULL

	if(!p){
		return false;
	}

	*e = p->data;

	return true;
}

int LinkList_LocateElem(link_list* header, LL_ElemType* e, uint32_t* locate){
	if(header == NULL){
		return false;
	}

	uint32_t temp = 1;
	link_list *p = header->next;

	while(p && (p->data != *e)){
		p = p->next;
		temp++;
	}

	if(!p){
		return false;
	}

	*locate = temp;
	return true;
}

int LinkList_Length(link_list* header){
	if(header == NULL){
		return false;
	}

	link_list* p = header->next;
	uint32_t length = 0;

	while(p){
		p = p->next;
		length++;
	}

	return length;
}

int LinkList_InsertElem(link_list* header, int i, LL_ElemType* e){
	if (header == NULL || e == NULL){
		return false;
	}

	link_list* p = header;
	uint32_t j = 0;

	while(p && j < i-1){
		p = p->next;
		j++;
	}

	// j==i-1 || p==NULL
	if(!p){
		return false;
	}

	link_list* q = (link_list*)malloc(sizeof(link_list));
	q->data = *e;
	q->next = p->next;
	p->next = q;

	return true;
}

int LinkList_DeleteElem(link_list* header, int i, LL_ElemType* e){
	if (header == NULL || e == NULL){
		return false;
	}

	link_list* p = header;
	uint32_t j = 0;

	while(p && j < i-1){
		p = p->next;
		j++;
	}

	// j == i-1 || p == NULL
	if(!p || !p->next){
		return false;
	}

	// j == i-1

	link_list* q = p->next;
	p->next = q->next;

	free(q);

	return true;
}

// order = 1 mean ascending order
// order = -1 mean descending order
// bubble sort
int LinkList_Sort(link_list* header, int order){
	if(header == NULL){
		return false;
	}

	link_list* tail = NULL;
	link_list* head = header->next;
	link_list* p = head;
	LL_ElemType temp;

	for(tail = NULL; tail != head; ){
		for(p = head; p->next != tail ; p = p->next){
			if(p->data > p->next->data){
				if(order == 1){
					temp = p->next->data;
					p->next->data = p->data;
					p->data = temp;
				}
			}else if(p->data < p->next->data){
				if(order == -1){
					temp = p->next->data;
					p->next->data = p->data;
					p->data = temp;
				}
			}
		}
		tail = p;
	}

	return true;
}

int LinkList_Merge(link_list* L0, link_list* L1, link_list* L_Merge, int order){
	if (L0 == NULL || L1 == NULL || L_Merge == NULL){
		return false;
	}

	link_list* L0_P = L0->next;
	link_list* L1_P = L1->next;
	link_list* LM_P = L_Merge;
	int j = 1;

	while(L0_P && L1_P){
		if(L0_P->data > L1_P->data){
			if(order == 1){
				LinkList_InsertElem(LM_P, j++, &L1_P->data);
				L1_P = L1_P->next;
			}
			if(order == -1){
				LinkList_InsertElem(LM_P, j++, &L0_P->data);
				L0_P = L0_P->next;
			}
		}else{
			if(order == 1){
				LinkList_InsertElem(LM_P, j++, &L0_P->data);
				L0_P = L0_P->next;
			}
			if(order == -1){
				LinkList_InsertElem(LM_P, j++, &L1_P->data);
				L1_P = L1_P->next;
			}
		}
	}

	while(L0_P){
		LinkList_InsertElem(LM_P, j++, &L0_P->data);
		L0_P = L0_P->next;
	}

	while(L1_P){
		LinkList_InsertElem(LM_P, j++, &L1_P->data);
		L1_P = L1_P->next;
	}

	return true;
}

int LinkList_PriorInsert(link_list* p, LL_ElemType* e){
	if (p == NULL || e == NULL){
		return false;
	}

	link_list* new = (link_list*)malloc(sizeof(link_list));

	new->data = p->data;
	new->next = p->next;
	p->data = *e;
	p->next = new;

	return true;
}

