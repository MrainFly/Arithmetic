/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*-----------------------------------------------------------*/

int lastStoneWeight(int* stones, int stonesSize){
    int i = 0;
    int j = 0;
    int ret = 0;
    int max_position = 0;
    int max_1_position = 0;
    if(stonesSize == 1){
        return stones[0];
    } else if(stonesSize == 0){
        return 0;
    }

    for(i = 0; i < stonesSize; i++){
        if(stones[i] >= stones[max_position]){
            max_position = i;
        }
    }

	i = 0;
	if(max_position == 0){
		max_1_position = 1;
		i = 1;
	}

	for(; i < stonesSize; i++){
		if(stones[i] >= stones[max_1_position] && (i != max_position)){
			max_1_position = i;
		}
	}

    int* stones_sub = malloc(sizeof(int) * stonesSize);
    for(i = 0, j = 0; i < stonesSize; i++){
        if(i == max_position || i == max_1_position){
            continue;
        }else{
            stones_sub[j++] = stones[i];
        }
    }

    if(stones[max_position] == stones[max_1_position]){
        ret = lastStoneWeight(stones_sub, (stonesSize - 2));
    } else{
        stones_sub[j] = (stones[max_position] - stones[max_1_position]);
        ret = lastStoneWeight(stones_sub, (stonesSize - 1));
    }

    free(stones_sub);

    return ret;
}

#define INPUT_STONES_NUM_MARCO     6

static int input_stones[INPUT_STONES_NUM_MARCO] = {2, 7, 4, 1, 8, 1};
static int input_stones_size = INPUT_STONES_NUM_MARCO;

static int output_stone_weight = 1;


int
main (int argc, char *argv[])
{
	if (lastStoneWeight(input_stones, input_stones_size) == output_stone_weight){
		printf("Primary test pass\r\n");
	} else{
		printf("Primary test trigger error\r\n");
	}
	return 0;
}
/*-----------------------------------------------------------*/

