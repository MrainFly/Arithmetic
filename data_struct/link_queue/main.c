/*
 * main.c
 *
 *  Created on: Jan 23, 2021
 *      Author: eason
 */

#include "LinkQueue.h"

#include "public.h"

static link_queue queue;

int main(){
	LinkQueue_Init(&queue);

	uint32_t count = 0;
	int rand_data;
	for(count = 0; count < 100; count++){
		rand_data = rand();
		LinkQueue_Insert(&queue, &rand_data);
	}

	count = 0;
	while(LinkQueue_Empty(&queue)){
		LinkQueue_Delete(&queue, &rand_data);
		LOG("[%d] The random data: 0x%x", count++, rand_data);
	}

	return 0;
}
