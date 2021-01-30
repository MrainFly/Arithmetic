/*
 * main.c
 *
 *  Created on: Jan 30, 2021
 *      Author: ycwang
 */
#include "public.h"
#include "inner.h"

#define TOKEN_BASE_SIZE     100

typedef enum {
	start = 0,
	ininteger,
	infloat,
	inoperate,
	end,
} tokenstage;

typedef union{
	int*   integer;
	float* infloat;
	char*  inoperate;
} tokenunion;

typedef struct{
	tokenstage stage;
	tokenunion data;
} token;

typedef struct{
	token* token;
	int    length;
	char*  base;
} tokenparse;

int TokenParse_Init(tokenparse* parse, char* base){
	parse->token = (token*)malloc(sizeof(token) * TOKEN_BASE_SIZE);
	parse->length = 0;

	if(parse->token == NULL){
		return false;
	}

	parse->base = base;

	return true;
}

int FloatParse(tokenparse* parse){
	float* floatd = (float*)malloc(sizeof(float));
	char character;
	float coefficient = 0.1;

	if(floatd == NULL){
		return false;
	}

	*floatd = (float)*parse->token[parse->length].data.integer;
	parse->token[parse->length].stage = infloat;
	parse->token[parse->length].data.infloat = floatd;

	while(*parse->base){
		character = *parse->base;
		if(character >= '0' && character <= '9'){
			*floatd += (character - '0') * coefficient;
			coefficient *= 0.1;
		} else{
			// return
			parse->length++;
			return true;
		}
		parse->base++;
	}

	parse->length++;
	return true;
}

int IntegerParse(tokenparse* parse){
	int* integer = (int*)malloc(sizeof(int));
	char character;
	int  coefficient = 1;
	if(integer == NULL){
		return false;
	}

	*integer = 0;
	parse->token[parse->length].stage = ininteger;
	parse->token[parse->length].data.integer = integer;

	while(*parse->base){
		character = *parse->base;
		if(character >= '0' && character <= '9'){
			*integer = *integer * coefficient + (character - '0');
			coefficient = 10;
		} else if (character == '.'){
			parse->base++;
			return FloatParse(parse);
		} else{
			// return
			parse->length++;
			return true;
		}
		parse->base++;
	}

	parse->length++;
	return true;
}

int OperateParse(tokenparse* parse){
	char* operate = (char*)malloc(sizeof(char));
	parse->token[parse->length].stage = inoperate;
	parse->token[parse->length].data.inoperate = operate;

	*operate = *parse->base;

	parse->base++;
	parse->length++;
	return true;
}

int NopParse(tokenparse* parse){
	parse->base++;
	return true;
}

int GetParse_Item(tokenparse* parse){
	int count = parse->length;
	int i = 0;
	while(i < count){
		switch(parse->token[i].stage){
		case ininteger:
			LOG("Integer token, value = %d", *parse->token[i].data.integer);
			break;
		case infloat:
			LOG("Float token, value = %f", *parse->token[i].data.infloat);
			break;
		case inoperate:
			LOG("Operate token, value = %c", *parse->token[i].data.inoperate);
			break;
		default:
			LOG("Unknown token");
			return false;
		}
		i++;
	}

	return true;
}

static char* string = "59 + 18 * 7775648 + 62 * (57 + 2155-58)*8.88 + 0.999356";
static tokenparse parse;

int main(){
//	LOG("Size of integer: %d bytes", sizeof(tokenstage));
//	LOG("Size of integer pointer: %d bytes", sizeof(int*));

	char c;
	TokenParse_Init(&parse, string);

	while(*parse.base){
		c = *parse.base;

		if(c >= '0' && c <= '9'){
			IntegerParse(&parse);
		} else if (c == ' '){
			NopParse(&parse);
		} else{
			OperateParse(&parse);
		}
	}

	GetParse_Item(&parse);

	return 0;
}
