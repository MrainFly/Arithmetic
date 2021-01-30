/*
 * main.c
 *
 *  Created on: Jan 25, 2021
 *      Author: eason
 */

#include "LinearStack.h"
#include "public.h"

static linear_stack stack;

int main(){
	char match_string[] = "{}{()[[]()]";
	uint32_t num = 0;
	int c_pop;

	LinearStack_Init(&stack);

	while(match_string[num]){
		char c = match_string[num];
		if(c == '{' || c == '(' || c == '['){
			// push the character to stack
			assert(LinearStack_Push(&stack, (LinearStack_ElemType*)&c));
		}

		if(c == '}' || c == ')' || c == ']'){
			assert(LinearStack_Pop(&stack, (LinearStack_ElemType*)&c_pop));
			c_pop = (char)c_pop;

			if((c_pop == '{' && c == '}') || (c_pop == '[' && c == ']') || (c_pop == '(' && c == ')')){
				LOG("In locate: %d, %c character compare success", num, c);
			}else{
				LOG("In locate: %d, %c character compare failed", num, c);
				assert(0);
			}
		}
		num++;
	}

	while(!LinearStack_Empty(&stack)){
		LinearStack_Pop(&stack, (LinearStack_ElemType*)&c_pop);
		LOG("[Error] residue character: %c", c_pop);
	}

	return 0;
}
