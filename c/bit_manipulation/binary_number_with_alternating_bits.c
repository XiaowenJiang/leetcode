#include<stdio.h>
#include<stdlib.h>

/*
 * Problem: Given a positive integer, check whether it has alternating bits:
 * namely, if two adjacent bits will always have different values.
 *
 * Example:
 *    Input: 5
 *    Output: True
 *    Explanation:
 *    The binary representation of 5 is: 101
 */

typedef int bool;
enum {
    false = 0,
    true = 1
};

/*
 * Brute Force.
 * TODO: cannot understand the one-liner on leetcode.
 */
bool hasAlternatingBits(int n) {
    bool rightmost = n % 2;
    while (n) {
        n >>= 1;
        if ((n % 2) == rightmost)
            return false;
        rightmost = (n % 2);
    }
    return true;
}

int main(int argc, char *argv[])
{
    int num;
    bool ret;

    if (argc < 2) {
        printf("Please input a positive number\n");
        return 1;
    }
    num = atoi(argv[1]);
    if (num <= 1) {
        printf("Please input a number that at least have 2 bits\n");
        return 1;
    }
    
    ret = hasAlternatingBits(num);
    printf("The number has %s alternating bits.\n", ret ? "" : "no");
    return 0;
}
