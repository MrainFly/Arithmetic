#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char * convert(char * s, int numRows){
    int s_size = sizeof(s);
    int z_items = 0;
    int z_rows = 0;
    int z_buf_pointer = 0;
    char* z_buf_start;
    char* z_buf = malloc(s_size);
    z_buf_start = z_buf;

    for(z_rows = 0; z_rows < numRows; z_rows++){
        for(z_items = 0, z_buf_pointer = 0; ; z_items++){
            // even
            if(z_items % 2 == 0){
                z_buf_pointer = 2*(numRows - 1) * z_items + z_rows;
            }
            // odd
            else{
                z_buf_pointer = 2*(numRows - 1) * z_items - z_rows;
            }
            if (z_buf_pointer >= s_size){
                break;
            }
            
            *z_buf_start = *(s + z_buf_pointer);
            z_buf_start++;
        }
    }

    return z_buf;
}

