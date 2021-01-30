#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// if i != 0 and i != (numRows-1)
// 2*(numRows-1)*k+i        k = 0, 2, 4, 6...... even
// 2*(numRows-1)*(k+1)-i    k = 1, 3, 5, 7...... odd
char * convert(char * s, int numRows){
    int s_size = strlen(s);
    printf("input string len: %d\n\n\n", s_size);
    int z_items = 0;
    int z_rows = 0;
    int z_buf_pointer = 0;
    char* z_buf_start;
    char* z_buf = malloc(s_size + 1);
    z_buf_start = z_buf;

    if (s_size == 1 || numRows == 1){
    	memcpy(z_buf, s, s_size+1);
    	return z_buf;
    }

    for(z_rows = 0; z_rows < numRows; z_rows++){
        for(z_items = 0, z_buf_pointer = z_rows; ; z_items++){
        	printf("buffer pointer: %d\n", z_buf_pointer);
			if (z_buf_pointer >= s_size){
				printf("pointer over limit\n");
				break;
			}
			printf("Append character: %c\n\n\n", *(s + z_buf_pointer));
			*z_buf_start = *(s + z_buf_pointer);
			z_buf_start++;

        	if (z_rows == 0 || z_rows == numRows-1){
        		z_buf_pointer += 2*(numRows-1);
        	}

        	else if(z_items%2 == 0){
        		z_buf_pointer += 2*(numRows-1) - 2*z_rows;
        	}

        	else if(z_items%2 == 1){
        		z_buf_pointer += 2*z_rows;
        	}

        	else{
        		printf("Trigger error");
        		while(1);
        	}
        }
        printf("break rows: %d loop\n\n\n", z_rows);
    }
    *z_buf_start = '\0';

    return z_buf;
}

char* input_string = /*"PAYPALISHIRING";*/"A";
int input_numRows = 1;

char* output_string = /*"PINALSIGYAHRPI";*/"A";
int
main (int argc, char *argv[])
{
	printf("output string:      %s\n", convert(input_string, input_numRows));
	printf("reference string:   %s\n", output_string);
	
	return 0;
}

