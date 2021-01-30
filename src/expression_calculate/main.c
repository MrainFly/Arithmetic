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

static char expression[] = "(5+32)*(100*10)/(100+20*20)-13*2";

void component_push_char(char c){
	LinearStack_Push(&component, (int*)&c);
}

void component_fetch_data(int* data){
	uint32_t coefficient = 1;
	uint32_t data_t = 0;
	int t_pop;
	while(!LinearStack_Empty(&component)){
		LinearStack_Pop(&component, (int *)&t_pop);
		data_t += ((t_pop & 0xff) - 48) * coefficient;
		coefficient *= 10;
	}

	*data = data_t;
}

int main(){
	LinearStack_Init(&operator);
	LinearStack_Init(&object);
	LinearStack_Init(&component);

	uint32_t i = 0;
	char character;
	int data;

	while(expression[i]){
		character = expression[i++];
		if(48<=character && character <= 57){
			component_push_char(character);
			continue;
		}

		if(!LinearStack_Empty(&component)){
			component_fetch_data(&data);
			// push the data into stack
			LinearStack_Push(&object, &data);
		}

		if(LinearStack_Empty(&operator)){
			LinearStack_Push(&operator, (int*)&character);
			continue;
		}

		switch (character){
		case '+':
		case '-':
		{
			char t_c;
			int left;
			int right;
			int result;
			while(!LinearStack_Empty(&operator)){
				LinearStack_Pop(&operator, (int*)&t_c);
				if(t_c == '('){
					LinearStack_Push(&operator, (int*)&t_c);
					break;
				}

				// + - * /
				LinearStack_Pop(&object, &right);
				LinearStack_Pop(&object, &left);
				switch (t_c){
				case '+':
					result = left + right;
					break;
				case '-':
					result = left - right;
					break;
				case '*':
					result = left * right;
					break;
				case '/':
					result = left / right;
					break;
				}

				LinearStack_Push(&object, &result);
			}

			// empty or encounter '('
			LinearStack_Push(&operator, (int*)&character);
		}
		break;

		case '*':
		case '/':
		{
			char t_c;
			int left;
			int right;
			int result;

			while(!LinearStack_Empty(&operator)){
				LinearStack_Pop(&operator, (int*)&t_c);
				if(t_c == '(' || t_c == '+' || t_c == '-'){
					LinearStack_Push(&operator, (int*)&t_c);
					break;
				}

				// * /
				LinearStack_Pop(&object, &right);
				LinearStack_Pop(&object, &left);
				switch (t_c){
				case '*':
					result = left * right;
					break;
				case '/':
					result = left / right;
					break;
				}

				LinearStack_Push(&object, &result);
			}

			// empty or encounter '(' '-' '+'
			LinearStack_Push(&operator, (int*)&character);
		}
			break;

		case '(':
			LinearStack_Push(&operator, (int*)&character);
			break;

		case ')':
		{
			char t_c;
			int left;
			int right;
			int result;

			while(!LinearStack_Empty(&operator)){
				LinearStack_Pop(&operator, (int*)&t_c);
				if(t_c == '('){
					break;
				}

				// + - * /
				LinearStack_Pop(&object, &right);
				LinearStack_Pop(&object, &left);
				switch (t_c){
				case '+':
					result = left + right;
					break;
				case '-':
					result = left - right;
					break;
				case '*':
					result = left * right;
					break;
				case '/':
					result = left / right;
					break;
				}

				LinearStack_Push(&object, &result);
			}
		}
			break;
		}
	}

	{
		char t_c;
		int left;
		int right;
		int result;
		if(!LinearStack_Empty(&component)){
			component_fetch_data(&data);
			// push the data into stack
			LinearStack_Push(&object, &data);
		}

		while(!LinearStack_Empty(&operator)){
			LinearStack_Pop(&operator, (int*)&t_c);

			// + - * /
			LinearStack_Pop(&object, &right);
			LinearStack_Pop(&object, &left);
			switch (t_c){
			case '+':
				result = left + right;
				break;
			case '-':
				result = left - right;
				break;
			case '*':
				result = left * right;
				break;
			case '/':
				result = left / right;
				break;
			}

			LinearStack_Push(&object, &result);
		}
	}

	LinearStack_Pop(&object, &data);
	LOG("The result = %d", data);

	return 0;
}
