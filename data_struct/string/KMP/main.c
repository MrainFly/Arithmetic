/*
 * main.c
 *
 *  Created on: Jan 28, 2021
 *      Author: eason
 */
#include "public.h"
#include "LinearString.h"

static linear_string s1;
static linear_string s2;

void KMP_NextGenerate(linear_string* s, int* next){
	linear_string prefix;
	linear_string suffix;

	LinearString_Init(&prefix);
	LinearString_Init(&suffix);

	next[0] = -1;
	next[1] = 0;
	if(s->string[1] == s->string[0]){
		next[1] = -1;
	}

	int i, j;
	int flag = 0;
	for(i = 2; i < s->length; i++){
		for(j = 1; j < i; j++){
			LinearString_SubString(s, &prefix, 0+1, (i-j));
			LinearString_SubString(s, &suffix, j+1, (i-j));

			if(LinearString_Compare(&prefix, &suffix) == 0){
				// equal
				next[i] = j;
				flag = 1;
			} else{
				flag = -1;
			}
		}

		if(flag == -1){
			next[i] = 0;
		}

		if(s->string[i] == s->string[next[i]]){
			next[i] = next[next[i]];
		}
	}
}

int KMP_Arithmetic(linear_string* s1, linear_string* s2){
	int* next = NULL;
	next = malloc(sizeof(int) * (s2->length));

	int i = 0, j = 0;

	KMP_NextGenerate(s2, next);

	while(i < s1->length && j < s2->length){
		if(j == -1){
			i++;
			j++;
		}

		LOG("Compare index %d and index %d:", i, j);

		if(s1->string[i] == s2->string[j]){
			LOG("[PASS] %c == %c", s1->string[i], s2->string[j]);
			i++;
			j++;
		}else{
			LOG("[FAILED] %c != %c", s1->string[i], s2->string[j]);
			j = next[j];
		}
	}

	if (j >= s2->length){
		return i - s2->length + 1;
	}

	return false;
}

int main(){
	LinearString_Init(&s1);
	LinearString_Init(&s2);

	LinearString_Assign(&s1, 'H');
	LinearString_Assign(&s1, 'e');
	LinearString_Assign(&s1, 'l');
	LinearString_Assign(&s1, 'l');
	LinearString_Assign(&s1, 'l');
	LinearString_Assign(&s1, 'w');
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

	LOG("String index: %d", KMP_Arithmetic(&s1, &s2));

	return 0;
}

