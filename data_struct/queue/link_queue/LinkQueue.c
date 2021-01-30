/*
 * LinkQueue.c
 *
 *  Created on: Jan 23, 2021
 *      Author: eason
 */

#include "LinkQueue.h"

int LinkQueue_Init(link_queue* queue){
	if (queue == NULL){
		return false;
	}

	queue->head = queue->rear = (link_queue_elem*)malloc(sizeof(link_queue_elem));
	queue->head->next = NULL;

	return true;
}

int LinkQueue_Empty(link_queue* queue){
	if (queue == NULL){
		return false;
	}

	if(queue->head == queue->rear){
		return true;
	}

	return false;
}

int LinkQueue_Insert(link_queue* queue, LinkQueue_Elem* e){
	if(queue == NULL || e == NULL){
		return false;
	}

	link_queue_elem* pointer = (link_queue_elem*)malloc(sizeof(link_queue_elem));
	pointer->data = *e;
	pointer->next = NULL;

	queue->rear->next = pointer;
	queue->rear = pointer;

	return true;
}

int LinkQueue_Delete(link_queue* queue, LinkQueue_Elem* e){
	if(queue == NULL || e == NULL || !LinkQueue_Empty(queue)){
		return false;
	}

	link_queue_elem* pointer = queue->head->next;
	*e = pointer->data;

	queue->head->next = pointer->next;

	// delete the last data
	if(pointer == queue->rear){
		queue->rear = queue->head;
	}

	free(pointer);

	return true;
}

