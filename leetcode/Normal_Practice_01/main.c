#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* returnNums = malloc(sizeof(int) * numsSize);
    int position = 0;
    *returnSize = 0;

    if (numsSize == 2){
        if(nums[0] + nums[1] == target){
            *returnSize = 2;

            returnNums[0] = 0;
            returnNums[1] = 1;
        }
        return returnNums;
    }

    int left_position = 0;
    int right_position = 0;

    for(left_position = 0; left_position < (numsSize - 1); left_position++){
        for(right_position = left_position + 1; right_position < numsSize; right_position++){
            if (nums[left_position] + nums[right_position] == target){
                *returnSize += 2;
                returnNums[position++] = left_position;
                returnNums[position++] = right_position;
                break;
            }
        }
    }

    return returnNums;
}

#define INPUT_NUM_SIZE_MARCO     4
#define INPUT_ADD_TARGET         9

static int input_nums[INPUT_NUM_SIZE_MARCO] = {2, 7, 11, 15};
static int input_nums_size = INPUT_NUM_SIZE_MARCO;

static int output_return_size;
static int* output_return_nums = NULL;

static int output_reference_nums[2] = {0, 1};


int
main (int argc, char *argv[])
{
	output_return_nums = twoSum(input_nums, input_nums_size, INPUT_ADD_TARGET, &output_return_size);
	
	if (memcmp(output_return_nums, output_reference_nums, output_return_size) == 0){
	    printf("Primary test pass\r\n");
	}else{
		printf("Primary test trigger error\r\n");
	}	
	
	return 0;
}

