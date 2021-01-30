/*
 * public.h
 *
 *  Created on: Jan 14, 2021
 *      Author: eason
 */

#ifndef DATA_STRUCT_PUBLIC_H_
#define DATA_STRUCT_PUBLIC_H_

#include <stdio.h>
#include <assert.h>

#ifndef LOG
#define LOG(string, ...)     do{ \
		printf(string"\n", ##__VA_ARGS__); \
		fflush(stdout); \
}while(0)
#endif

#endif /* DATA_STRUCT_PUBLIC_H_ */
