/*
 * LoopQueue.c
 *
 *  Created on: Jan 22, 2021
 *      Author: eason
 */

#include "LoopQueue.h"

int LoopQueue_Init(loop_queue* queue){
	if (queue == NULL){
		return false;
	}

	queue->head = queue->rear = 0;

	return true;
}

int LoopQueue_Empty(loop_queue* queue){
	if (queue == NULL){
		return false;
	}
	if(queue->head == queue->rear){
		return true;
	}

	return false;
}

int LoopQueue_Full(loop_queue* queue){
	if (queue == NULL){
		return false;
	}
	if((queue->rear + 1)%LoopQueue_MaxSize == queue->head){
		return true;
	}

	return false;
}

int LoopQueue_Insert(loop_queue* queue, LoopQueue_ElemType* elem){
	if (queue == NULL || elem == NULL || !LoopQueue_Full(queue)){
		return false;
	}

	queue->data[queue->rear] = *elem;
	queue->rear = (queue->rear + 1)%LoopQueue_MaxSize;

	return true;
}

int LoopQueue_Delete(loop_queue* queue, LoopQueue_ElemType* elem){
	if (queue == NULL || elem == NULL || !LoopQueue_Empty(queue)){
		return false;
	}

	*elem = queue->data[queue->head];
	queue->head = (queue->head + 1)%LoopQueue_MaxSize;

	return true;
}

int LoopQueue_Length(loop_queue* queue){
	if (queue == NULL){
		return false;
	}

	return (queue->rear + LoopQueue_MaxSize - queue->head)%LoopQueue_MaxSize;
}

// other function which eliminate the last block mean the full is not lock free
