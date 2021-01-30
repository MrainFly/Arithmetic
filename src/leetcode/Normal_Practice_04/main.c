#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static double find(int* nums, int numsSize){	
	int numsize = numsSize -1;
	return (double)(nums[(int)floor((double)numsize/2)] + nums[(int)ceil((double)numsize/2)])/2;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
	int* nums = malloc(sizeof(int) * (nums1Size + nums2Size));
	int i = 0, j = 0;

	if(nums1Size == 0){
		return find(nums2, nums2Size);
	}

	if(nums2Size == 0){
		return find(nums1, nums1Size);
	}

	while(1){
		if(nums1[i] < nums2[j]){
			nums[i+j] = nums1[i];
			i++;
		}else{
			nums[i+j] = nums2[j];
			j++;
		}

		if(i >= nums1Size || j >= nums2Size){
			if(i < nums1Size){
				memcpy(&nums[i+j], &nums1[i], (nums1Size - i) * sizeof(int));
			}

			if(j < nums2Size){
				memcpy(&nums[i+j], &nums2[j], (nums2Size - j) * sizeof(int));
			}
			break;
		}
	}

	double ret;
	ret = find(nums, nums1Size + nums2Size);

	free(nums);

	return ret;
}

static int input_array_0[2] = {1, 2};
static int input_array_1[2] = {3, 4};


int
main (int argc, char *argv[])
{
	findMedianSortedArrays(input_array_0, 2, input_array_1, 2);
	
//	if (memcmp(output_return_nums, output_reference_nums, output_return_size) == 0){
//	    printf("Primary test pass\r\n");
//	}else{
//		printf("Primary test trigger error\r\n");
//	}
//
	return 0;
}
