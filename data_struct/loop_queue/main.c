/*
 * main.c
 *
 *  Created on: Jan 22, 2021
 *      Author: eason
 */


#include "LoopQueue.h"
#include "public.h"

static loop_queue queue;

int main(){
	LoopQueue_Init(&queue);

	int rand_data;

	while(LoopQueue_Full(&queue)){
		rand_data = rand();
		LoopQueue_Insert(&queue, &rand_data);
	}

	LoopQueue_Delete(&queue, &rand_data);
	LOG("The random data: 0x%x", rand_data);

	LoopQueue_Delete(&queue, &rand_data);
	LOG("The random data: 0x%x", rand_data);

	LoopQueue_Delete(&queue, &rand_data);
	LOG("The random data: 0x%x", rand_data);

	LOG("The length: %d", LoopQueue_Length(&queue));

	while(LoopQueue_Empty(&queue)){
		LoopQueue_Delete(&queue, &rand_data);
		LOG("The random data: 0x%x", rand_data);
	}

	return 0;
}
