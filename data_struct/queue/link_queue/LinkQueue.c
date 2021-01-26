/*
 * LinkQueue.c
 *
 *  Created on: Jan 23, 2021
 *      Author: eason
 */

#include "LinkQueue.h"

int LinkQueue_Init(link_queue* queue){
	if (queue == NULL){
		return PARAMETER_ERROR;
	}

	queue->head = queue->rear = (link_queue_elem*)malloc(sizeof(link_queue_elem));
	queue->head->next = NULL;

	return PASS;
}

int LinkQueue_Empty(link_queue* queue){
	if (queue == NULL){
		return PARAMETER_ERROR;
	}

	if(queue->head == queue->rear){
		return PASS;
	}

	return FAILED;
}

int LinkQueue_Insert(link_queue* queue, LinkQueue_Elem* e){
	if(queue == NULL || e == NULL){
		return PARAMETER_ERROR;
	}

	link_queue_elem* pointer = (link_queue_elem*)malloc(sizeof(link_queue_elem));
	pointer->data = *e;
	pointer->next = NULL;

	queue->rear->next = pointer;
	queue->rear = pointer;

	return PASS;
}

int LinkQueue_Delete(link_queue* queue, LinkQueue_Elem* e){
	if(queue == NULL || e == NULL || !LinkQueue_Empty(queue)){
		return PARAMETER_ERROR;
	}

	link_queue_elem* pointer = queue->head->next;
	*e = pointer->data;

	queue->head->next = pointer->next;

	// delete the last data
	if(pointer == queue->rear){
		queue->rear = queue->head;
	}

	free(pointer);

	return PASS;
}

