/*
 * main.c
 *
 *  Created on: Jan 27, 2021
 *      Author: eason
 */
#include "public.h"
#include "LinearString.h"

static linear_string s1;
static linear_string s2;

int main(){
	LinearString_Init(&s1);
	LinearString_Init(&s2);

	LinearString_Assign(&s1, 'H');
	LinearString_Assign(&s1, 'e');
	LinearString_Assign(&s1, 'l');
	LinearString_Assign(&s1, 'l');
	LinearString_Assign(&s1, 'w');
	LinearString_Assign(&s1, 'o');
	LinearString_Assign(&s1, 'r');
	LinearString_Assign(&s1, 'l');
	LinearString_Assign(&s1, 'd');

	LinearString_Assign(&s2, 'l');
	LinearString_Assign(&s2, 'l');
	LinearString_Assign(&s2, 'w');
	LinearString_Assign(&s2, 'o');

	LOG("String compare: %d", LinearString_Compare(&s1, &s2));
	LOG("String index: %d", LinearString_Index(&s1, &s2));

	return 0;
}
