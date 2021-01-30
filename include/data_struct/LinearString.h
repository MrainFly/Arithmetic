/*
 * LinearString.h
 *
 *  Created on: Jan 27, 2021
 *      Author: eason
 */

#ifndef DATA_STRUCT_STRING_LINEAR_STRING_LINEARSTRING_H_
#define DATA_STRUCT_STRING_LINEAR_STRING_LINEARSTRING_H_

#include "inner.h"

#define LinearString_MaxSize            (100)

typedef struct {
	char string[LinearString_MaxSize];
	int length;
} linear_string;

int LinearString_Init(linear_string* s);

int LinearString_Empty(linear_string* s);

int LinearString_Full(linear_string* s);

int LinearString_Assign(linear_string* s, char c);

int LinearString_Copy(linear_string* s, linear_string* t);

int LinearString_Length(linear_string* s);

int LinearString_Clear(linear_string* s);

int LinearString_Concat(linear_string* s, linear_string* s1, linear_string* s2);

int LinearString_SubString(linear_string* s, linear_string* sub, int pos, int len);

int LinearString_Index(linear_string* s, linear_string* t);

int LinearString_Compare(linear_string* s, linear_string* t);

#endif /* DATA_STRUCT_STRING_LINEAR_STRING_LINEARSTRING_H_ */
