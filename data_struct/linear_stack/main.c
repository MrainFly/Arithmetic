/*
 * main.c
 *
 *  Created on: Jan 22, 2021
 *      Author: eason
 */
#include "public.h"
#include "LinearStack.h"

static linear_stack stack;

int main(){
	LinearStack_Init(&stack);

	int rand_data = 0;
	int number = 0;

	while(LinearStack_Full(&stack)){
		rand_data = rand();
		LinearStack_Push(&stack, &rand_data);
	}

	while(LinearStack_Empty(&stack)){
		LinearStack_Pop(&stack, &rand_data);
		LOG("[%d]Stack data: 0x%x", number++, rand_data);
	}

	return 0;
}
