/*
 * LoopQueue.h
 *
 *  Created on: Jan 22, 2021
 *      Author: eason
 */

#ifndef DATA_STRUCT_LOOP_QUEUE_LOOPQUEUE_H_
#define DATA_STRUCT_LOOP_QUEUE_LOOPQUEUE_H_

#include "inner.h"

#define LoopQueue_MaxSize            (100)
typedef int LoopQueue_ElemType;

typedef struct {
	LoopQueue_ElemType data[LoopQueue_MaxSize];
	uint32_t head,rear;
} loop_queue;

int LoopQueue_Init(loop_queue* queue);
int LoopQueue_Empty(loop_queue* queue);
int LoopQueue_Full(loop_queue* queue);
int LoopQueue_Insert(loop_queue* queue, LoopQueue_ElemType* elem);
int LoopQueue_Delete(loop_queue* queue, LoopQueue_ElemType* elem);
int LoopQueue_Length(loop_queue* queue);

#endif /* DATA_STRUCT_LOOP_QUEUE_LOOPQUEUE_H_ */
