#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int cmp(int** a, int** b) {
    return (*a)[1] - (*b)[1];
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervalsSize == 0) {
        return 0;
    }

    qsort(intervals, intervalsSize, sizeof(int*), cmp);

    int right = intervals[0][1];
    int ans = 1;
    for (int i = 1; i < intervalsSize; ++i) {
        if (intervals[i][0] >= right) {
            ++ans;
            right = intervals[i][1];
        }
    }
    return intervalsSize - ans;
}

static int input_intervals[4][2] = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
static int input_interval_size = 4;

static int output_erase_interval_size = 1;


int main(int argc, char const *argv[])
{
    /* code */
    if(eraseOverlapIntervals((int **)input_intervals, input_interval_size, NULL) == output_erase_interval_size){
        printf("Primary test pass\n");
    } else{
        printf("Primary test failed\n");
    }
    return 0;
}