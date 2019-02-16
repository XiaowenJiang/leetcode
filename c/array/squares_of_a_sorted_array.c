#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
 * Given an array of integers A sorted in non-decreasing order,
 * return an array of the squares of each number, also in sorted
 * non-decreasing order.
 *
 */

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* sortedSquares(int* A, int ASize, int* returnSize) {
    int i, j, k, zp;
    int *rst = malloc(sizeof(int) * ASize);
    memset(rst, 0, sizeof(int) *ASize);
    *returnSize = ASize;
    if (ASize == 1) {
        rst[0] = A[0] * A[0];
        return rst;
    }
    for (zp = 0; zp < ASize - 1 && A[zp] < 0; zp++);
    for (i = zp - 1, j = zp, k = 0; i >= 0 && j < ASize; k++) {
        if (abs(A[i]) < abs(A[j])) {
            rst[k] = A[i] * A[i];
            i--;
        } else {
            rst[k] = A[j] * A[j];
            j++;
        }
    }
    for (; i >= 0; i--, k++)
        rst[k] = A[i] * A[i];
    for (; j < ASize; j++, k++)
        rst[k] = A[j] * A[j];
    return rst;
}


int main()
{
    int *arr = NULL, *arr_rst = NULL;
    int count = 0, num = 0;
    int val, i;
    printf("Please input the length of input array:\n");
    scanf("%d", &num);
    if (num <= 0) {
        printf("length should be larger than 0\n");
        exit(1);
    }
    arr = calloc(num, sizeof(int));
    while (count < num) {
        scanf("%d", &val);
        arr[count++] = val;
    }
    printf("The original array is:\n");
    for (i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    arr_rst = sortedSquares(arr, num, &count);
    printf("The rst array is:\n");
    for (i = 0; i < num; i++) {
        printf("%d ", arr_rst[i]);
    }
    printf("\n");

    free(arr);
    free(arr_rst);

    return 0;
}
