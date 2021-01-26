/*
 * LinearStack.h
 *
 *  Created on: Jan 22, 2021
 *      Author: eason
 */

#ifndef DATA_STRUCT_LINEAR_STACK_LINEARSTACK_H_
#define DATA_STRUCT_LINEAR_STACK_LINEARSTACK_H_

#include "inner.h"

#define LinearStack_TopInit     (0)

#define LinearStack_MaxSize            (100)
typedef char LinearStack_ElemType;

typedef struct {
	LinearStack_ElemType data[LinearStack_MaxSize];
	int top;
} linear_stack;

int LinearStack_Init(linear_stack* stack);

int LinearStack_Empty(linear_stack* stack);

int LinearStack_Full(linear_stack* stack);

int LinearStack_Push(linear_stack* stack, LinearStack_ElemType* data);

int LinearStack_Pop(linear_stack* stack, LinearStack_ElemType* data);

int LinearStack_Depth(linear_stack* stack);

#endif /* DATA_STRUCT_LINEAR_STACK_LINEARSTACK_H_ */
