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
		return false;
	}

	stack->top = -1;

	return true;
}

int LinearStack_Empty(linear_stack* stack){
	if (stack == NULL){
		return false;
	}
	if(stack->top == -1){
		return true;
	}

	return false;
}

int LinearStack_Full(linear_stack* stack){
	if (stack == NULL){
		return false;
	}
	if(stack->top >= LinearStack_MaxSize-1){
		return true;
	}

	return false;
}

int LinearStack_Push(linear_stack* stack, LinearStack_ElemType* data){
	if(stack ==NULL || data == NULL){
		return false;
	}

	stack->data[++stack->top] = *data;

	return true;
}

int LinearStack_Pop(linear_stack* stack, LinearStack_ElemType* data){
	if(stack ==NULL || data == NULL || stack->top == -1){
		return false;
	}

	*data = stack->data[stack->top--];

	return true;
}

int LinearStack_Depth(linear_stack* stack){
	if (stack == NULL){
		return false;
	}

	return stack->top++;
}

#else
int LinearStack_Init(linear_stack* stack){
	if (stack == NULL){
		return false;
	}

	stack->top = 0;

	return true;
}

int LinearStack_Empty(linear_stack* stack){
	if (stack == NULL){
		return false;
	}
	if(stack->top == 0){
		return true;
	}

	return false;
}

int LinearStack_Full(linear_stack* stack){
	if (stack == NULL){
		return false;
	}
	if(stack->top >= LinearStack_MaxSize){
		return true;
	}

	return false;
}

int LinearStack_Push(linear_stack* stack, LinearStack_ElemType* data){
	if(stack ==NULL || data == NULL || !LinearStack_Full(stack)){
		return false;
	}

	stack->data[stack->top++] = *data;

	return true;
}

int LinearStack_Pop(linear_stack* stack, LinearStack_ElemType* data){
	if(stack ==NULL || data == NULL || stack->top == 0){
		return false;
	}

	*data = stack->data[--stack->top];

	return true;
}

int LinearStack_Depth(linear_stack* stack){
	if (stack == NULL){
		return false;
	}

	return stack->top;
}
#endif
