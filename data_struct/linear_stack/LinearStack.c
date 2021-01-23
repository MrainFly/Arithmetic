/*
 * LinearStack.c
 *
 *  Created on: Jan 22, 2021
 *      Author: eason
 */

#include "LinearStack.h"

// top init = -1
#if LinearStack_TopInit == -1
int LinearStack_Init(linear_stack* stack){
	if (stack == NULL){
		return PARAMETER_ERROR;
	}

	stack->top = -1;

	return PASS;
}

int LinearStack_Empty(linear_stack* stack){
	if (stack == NULL){
		return PARAMETER_ERROR;
	}
	if(stack->top == -1){
		return PASS;
	}

	return FAILED;
}

int LinearStack_Full(linear_stack* stack){
	if (stack == NULL){
		return PARAMETER_ERROR;
	}
	if(stack->top >= LinearStack_MaxSize-1){
		return PASS;
	}

	return FAILED;
}

int LinearStack_Push(linear_stack* stack, LinearStack_ElemType* data){
	if(stack ==NULL || data == NULL){
		return PARAMETER_ERROR;
	}

	stack->data[++stack->top] = *data;

	return PASS;
}

int LinearStack_Pop(linear_stack* stack, LinearStack_ElemType* data){
	if(stack ==NULL || data == NULL || stack->top == -1){
		return PARAMETER_ERROR;
	}

	*data = stack->data[stack->top--];

	return PASS;
}

int LinearStack_Depth(linear_stack* stack){
	if (stack == NULL){
		return PARAMETER_ERROR;
	}

	return stack->top++;
}

#else
int LinearStack_Init(linear_stack* stack){
	if (stack == NULL){
		return PARAMETER_ERROR;
	}

	stack->top = 0;

	return PASS;
}

int LinearStack_Empty(linear_stack* stack){
	if (stack == NULL){
		return PARAMETER_ERROR;
	}
	if(stack->top == 0){
		return PASS;
	}

	return FAILED;
}

int LinearStack_Full(linear_stack* stack){
	if (stack == NULL){
		return PARAMETER_ERROR;
	}
	if(stack->top >= LinearStack_MaxSize){
		return PASS;
	}

	return FAILED;
}

int LinearStack_Push(linear_stack* stack, LinearStack_ElemType* data){
	if(stack ==NULL || data == NULL){
		return PARAMETER_ERROR;
	}

	stack->data[stack->top++] = *data;

	return PASS;
}

int LinearStack_Pop(linear_stack* stack, LinearStack_ElemType* data){
	if(stack ==NULL || data == NULL || stack->top == 0){
		return PARAMETER_ERROR;
	}

	*data = stack->data[--stack->top];

	return PASS;
}

int LinearStack_Depth(linear_stack* stack){
	if (stack == NULL){
		return PARAMETER_ERROR;
	}

	return stack->top;
}
#endif
