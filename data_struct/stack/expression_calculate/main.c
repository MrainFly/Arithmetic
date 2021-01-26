/*
 * main.c
 *
 *  Created on: Jan 25, 2021
 *      Author: eason
 */

#include "LinearStack.h"
#include "public.h"

static linear_stack operator;
static linear_stack object;
static linear_stack component;

static char expression = "5+5*6/3-7";
/*
static void suffix_push_data(char c){
	switch (c){
	case '+':
	{
		char prefix;
		char suffix;
		char result;

		LinearStack_Pop(&object, &suffix);
		LinearStack_Pop(&object, &prefix);

		prefix -= 48;
		suffix -= 48;

		result = prefix + suffix;

		LinearStack_Push
		break;
	}
	case '-':
		char prefix;
		char suffix;
		char result;

		LinearStack_Pop(&object, &suffix);
		LinearStack_Pop(&object, &prefix);

		prefix -= 48;
		suffix -= 48;

		result =
		break;
	case '*':
		char prefix;
		char suffix;
		char result;

		LinearStack_Pop(&object, &suffix);
		LinearStack_Pop(&object, &prefix);

		prefix -= 48;
		suffix -= 48;

		result =
		break;
	case '/':
		char prefix;
		char suffix;
		char result;

		LinearStack_Pop(&object, &suffix);
		LinearStack_Pop(&object, &prefix);

		prefix -= 48;
		suffix -= 48;

		result =
		break;
	default:
		break;
	}

	if(c == '+' || c == '-' || c == '*' || c == '/'){

	}
}*/

int main(){
	LinearStack_Init(&operator);
	LinearStack_Init(&object);
	LinearStack_Init(&component);

	uint32_t i = 0;
	char character;
	while(expression[i]){
		character = expression[i];
		if(48<=character && character <= 57){
			LinearStack_Push(&component, &character);
			continue;
		} else if(character == '+' || character == '-' || character == '*' || character == '/' || character == ')'){
			uint32_t value = 0;

			// pop component stack generate a number
			{
				uint32_t coefficient = 1;
				uint32_t data;
				while(LinearStack_Empty(&component)){
					LinearStack_Pop(&component, &data);
					value += (data - 48)*coefficient;
					coefficient *= 10;
				}
			}
			// push the data into stack
			LinearStack_Push(&object, &value);

			if(!LinearStack_Empty(&operator)){
				// empty
				LinearStack_Push(&operator, &character);
			}
		} else{

		}
	}
}
