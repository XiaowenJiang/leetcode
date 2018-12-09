#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNUM 2048
/* Given an array A of non-negative integers, return an array consisting of all the even elements of A,
 * followed by all the odd elements of A.
 */

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize) {
    int start = 0, end = ASize - 1, i = 0;
    int *returnArray = NULL;
    
    if (ASize == 0)
        return NULL;
    *returnSize = ASize;
    returnArray = malloc(ASize * sizeof(int));
    memset(returnArray, 0 , ASize * sizeof(int));
    
    for (i = 0; (i < ASize) && (start <= end); i++) {
        if (A[i] % 2)
            returnArray[end--] = A[i];
        else
            returnArray[start++] = A[i];
    }
    
    return returnArray;
}

int main()
{
	int input[MAXNUM];
    int *output = NULL;
    int returnSize = 0;
	int num = -1, i = 0;
	printf("Please input the numbers divided by newline\n");
    //FIXME: if a '\n' is input, the program will hang, I don't know why.
	while ((scanf("%d", &num) > 0) && (num > 0) && (i < MAXNUM)) {
        input[i] = num;
        i++;
        num = -1;
	}

    if (i == 0)
        goto out;

    output = sortArrayByParity(input, i, &returnSize);
    printf("The output array is :\n");
    for (i = 0; i < returnSize; i++) {
        printf("%d ", output[i]);
    }
    printf("\n");
out:
    return 0;
}
