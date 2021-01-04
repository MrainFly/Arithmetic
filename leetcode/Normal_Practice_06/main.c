#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// 2(n - rows -1) * i + rows   i = 0, 1, 2, 3 ......
char * convert(char * s, int numRows){
    int s_size = strlen(s);
    printf("input string len: %d\n\n\n", s_size);
    int z_items = 0;
    int z_rows = 0;
    int z_buf_pointer = 0;
    char* z_buf_start;
    char* z_buf = malloc(s_size + 1);
    z_buf_start = z_buf;
    int jump_gap = 0;

    for(z_rows = 0; z_rows < numRows; z_rows++){
        jump_gap = 2*(numRows - z_rows - 1);
        
        if (jump_gap == 0){
        	jump_gap = 2*(numRows - 1);
        }
    
        for(z_items = 0, z_buf_pointer = 0; ; z_items++){

            z_buf_pointer = jump_gap * z_items + z_rows;
            printf("buffer pointer: %d\n", z_buf_pointer);
            if (z_buf_pointer > s_size){
            	printf("pointer over limit\n");
                break;
            }
            printf("Append character: %c\n\n\n", *(s + z_buf_pointer));
            *z_buf_start = *(s + z_buf_pointer);
            z_buf_start++;
        }
        printf("break rows: %d loop\n\n\n", z_rows);
    }
    *z_buf_start = '\0';

    return z_buf;
}

char* input_string = "PAYPALISHIRING";
int input_numRows = 4;

char* output_string = "PINALSIGYAHRPI";
int
main (int argc, char *argv[])
{
	printf("output string:      %s\n", convert(input_string, input_numRows));
	printf("reference string:   %s\n", output_string);
	
	return 0;
}

