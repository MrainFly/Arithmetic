/*
 * LinkQueue.h
 *
 *  Created on: Jan 23, 2021
 *      Author: eason
 */

#ifndef DATA_STRUCT_LINK_QUEUE_LINKQUEUE_H_
#define DATA_STRUCT_LINK_QUEUE_LINKQUEUE_H_

#include "inner.h"

typedef int LinkQueue_Elem;

typedef struct __link_queue_elem{
	LinkQueue_Elem data;
	struct __link_queue_elem* next;
} link_queue_elem;

typedef struct {
	link_queue_elem* head;
	link_queue_elem* rear;
} link_queue;

int LinkQueue_Init(link_queue* queue);

int LinkQueue_Empty(link_queue* queue);

int LinkQueue_Insert(link_queue* queue, LinkQueue_Elem* e);

int LinkQueue_Delete(link_queue* queue, LinkQueue_Elem* e);

#endif /* DATA_STRUCT_LINK_QUEUE_LINKQUEUE_H_ */
