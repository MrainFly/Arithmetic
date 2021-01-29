/*
 * LinearString.c
 *
 *  Created on: Jan 27, 2021
 *      Author: eason
 */

#include "LinearString.h"

int LinearString_Init(linear_string* s){
	if (s == NULL){
		return false;
	}

	s->length = 0;

	return true;
}

int LinearString_Empty(linear_string* s){
	if (s == NULL){
		return false;
	}

	if (s->length == 0){
		return true;
	}

	return false;
}

int LinearString_Full(linear_string* s){
	if (s == NULL){
		return false;
	}

	if (s->length == LinearString_MaxSize){
		return true;
	}

	return false;
}

int LinearString_Assign(linear_string* s, char c){
	if (s == NULL || LinearString_Full(s)){
		return false;
	}

	s->string[s->length++] = c;

	return true;
}

int LinearString_Copy(linear_string* s, linear_string* t){
	if (s == NULL || t == NULL){
		return false;
	}

	int i = 0;
	for(i = 0; i < t->length; i++){
		s->string[i] = t->string[i];
	}

	s->length = t->length;

	return true;
}

int LinearString_Length(linear_string* s){
	if (s == NULL){
		return false;
	}

	return s->length;
}

int LinearString_Clear(linear_string* s){
	if (s == NULL){
		return false;
	}

	s->length = 0;

	return true;
}

int LinearString_Concat(linear_string* s, linear_string* s1, linear_string* s2){
	if (s == NULL || s1 == NULL || s2 == NULL){
		return false;
	}

	int i = 0;
	for(i = 0; i < s1->length; i++){
		s->string[i] = s1->string[i];
	}

	s->length = s1->length;

	for(; i < s1->length + s2->length; i++){
		s->string[i] = s2->string[i];
	}

	s->length += s2->length;

	return true;
}

int LinearString_SubString(linear_string* s, linear_string* sub, int pos, int len){
	if (s == NULL || sub == NULL || (pos + len) > s->length){
		return false;
	}

	int i = 0;
	for(i = 0; i < len; i++){
		sub->string[i] = s->string[pos - 1 + i];
	}
	sub->length = len;

	return true;
}
/*
int LinearString_Index(linear_string* s, linear_string* t){
	if (s == NULL || t == NULL){
		return false;
	}

	int i, j;
	int flag = 0;
	for(i = 0; i < s->length; i++){
		for(j = 0; j < t->length; j++){
			if(s->string[i+j] == t->string[j]){
				flag = 1;
			}else{
				flag = -1;
				break;
			}
		}
		if(flag == 1){
			return i+1;
		}
	}

	return false;
}*/

int LinearString_Index(linear_string* s, linear_string* t){
	if (s == NULL || t == NULL){
		return false;
	}

	int i = 0,j = 0;
	while(i < s->length && j < t->length){
		if(s->string[i+j] == t->string[j]){
			j++;
		} else{
			i++;
			j = 0;
		}
	}

	if (j >= t->length){
		return i + 1;
	}

	return false;
}

int LinearString_Compare(linear_string* s, linear_string* t){
	if (s == NULL || t == NULL){
		return false;
	}

	int i = 0,j = 0;
	while(i < s->length && j < t->length){
		if(s->string[i] == t->string[j]){
			j++;
			i++;
		}else{
			return s->string[i] - t->string[j];
		}
	}

	return s->length - t->length;
}
