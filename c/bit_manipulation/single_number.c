#include<stdio.h>
#include<stdlib.h>

/* Problem: Given a non-empty array of integers, every element appears twice except for one. Find that single one.
 * Note:
 * Your algorithm should have a linear runtime complexity. 
 * Could you implement it without using extra memory? 
 */

/*
 * Because A ^ A = 0, 0 ^ A = A, and xor is commutive, we can xor all the
 * elements in the array until we get the single one.
 */
int singleNumber(int* nums, int numsSize) {
    int rst = 0, i = 0;
    for (i = 0; i < numsSize; i++) {
        rst ^= nums[i];
    }
    return rst;
}

int main(int argc, char *argv[])
{
    int i, size, ret;
    int *arr;

    if (argc < 2) {
        printf("Please input the int array splitted by space\n");
        return 1;
    }
    size = argc - 1;

    arr = malloc(size * sizeof(int));
    for (i = 1; i < argc; i++) {
        arr[i - 1] = atoi(argv[i]);
    }
    ret = singleNumber(arr, size);
    printf("The single number in the input array is %d\n", ret);
    return 0;
}
