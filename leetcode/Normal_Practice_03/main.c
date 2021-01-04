#include <stdio.h>
#include <stdint.h>
#include <string.h>

int lengthOfLongestSubstring(char * s){
	int start_position = 0, cur_position = 1, position_diff = 0, max_position_diff = 0;
	int i = 0;
	int flag = 0;
	if (!s[0]){
		return 0;
	}

	if(!s[1]){
		return 1;
	}

	// >= 2
	while(s[cur_position]){
		flag = 0;
		position_diff = cur_position - start_position;		
		for(i = 0; i < position_diff; i++){
			if (s[cur_position] == s[start_position + i]){
				if(position_diff > max_position_diff){
					max_position_diff = position_diff;
				}
				flag = 1;
				start_position = start_position + i + 1;
				break;
			}			
		}
		if(flag == 0){
			position_diff++;
		}	
		cur_position++;	
	}

	if(position_diff > max_position_diff){
		max_position_diff = position_diff;
	}

	return max_position_diff;
}

static char* input_string = "bbbb";

static int output_length = 1;

int main(int argc, char const *argv[])
{
    /* code */
    if (lengthOfLongestSubstring(input_string) == output_length){
        printf("Tiny test pass\n");
    }else{
        printf("Trigger error\n");
    }
    return 0;
}
