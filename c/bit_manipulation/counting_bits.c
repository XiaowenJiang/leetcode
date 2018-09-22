#include <stdio.h>
#include <stdlib.h>

typedef int bool;

/*
 * Explanation:
 * 
 * Let's get the rule of this series
 *
 * As we all know for each value that is a power of 2, it only has one 1 in binary
 * expression. Then we can group the numbers in to [2^n, 2^(n + 1) - 1]
 *
 * 0 -> 0
 * 1 -> 1
 * ======
 * 2 -> 1 rst[2]
 * 3 -> 2 = 1 + rst[3 - 2] = 1 + rst[1]
 * ======
 * 4 -> 1 rst[4]
 * 5 -> 2 1 + rst[5 - 4] = 1 + rst[1]
 * 6 -> 2 1 + rst[6 - 4] = 1 + rst[2]
 * 7 -> 3 1 + rst[7 - 4] = 1 + rst[3]
 * ======
 * 8 ->  1 rst[8]
 * 9 ->  2 1 + rst[9 - 8] = 1 + rst[1]
 * 10 -> 2 1 + rst[10 - 8] = 1 + rst[2]
 * 11 -> 3 1 + rst[11 - 8] = 1 + rst[3]
 * 12 -> 2 1 + rst[12 - 8] = 1 + rst[4]
 * 13 -> 3 1 + rst[13 - 8] = 1 + rst[5]
 * 14 -> 3 1 + rst[14 - 8] = 1 + rst[6]
 * 15 -> 4 1 + rst[15 - 8] = 1 + rst[7]
 */

/*
 * When a number is a power of 2, its binary expression is 10000...0, and (number - 1) is 01111...1
 * so when we & them, the result should be zero
 */
bool isPowerofTwo(int val)
{
    return ((val & (val - 1)) == 0) ? 1 : 0;
}

int* countBits(int num, int* returnSize) {
    int nearest, curr;
    int *rst = NULL;

    *returnSize = 0;

    printf("num : %d\n", num);

    if (num < 0)
        return NULL;

    *returnSize = num + 1;
    rst = malloc((num + 1) * sizeof(int));
    rst[0] = 0;
    
    if(num == 0)
        return (int *)rst;

    rst[1] = 1;
    curr = nearest = 2;

    while (curr <= num) {
        if (isPowerofTwo(curr)) {
            rst[curr] = 1;
            nearest = curr;
        } else {
            rst[curr] = 1 + rst[curr - nearest];
        }
        curr++;
    }
    
    return (int *)rst;
}

int main(int argc, char *argv[])
{
    int *rst = NULL;
    int i, num;
    int *returnSize = malloc(sizeof(int));

    if (argc != 2) {
        printf("Please input number\n");
        goto out;
    }

    num = atoi(argv[1]);
    rst = countBits(num, returnSize);
    for (i = 0; i < *returnSize; i++) {
        printf("%d --> %d\n", i, rst[i]);
    }

out:
    if (rst)
        free(rst);
    free(returnSize);
    return 0;
}
