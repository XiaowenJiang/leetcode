#include<stdio.h>
#include<stdlib.h>

/* Problem: Given a positive integer, output its complement number.
 * The complement strategy is to flip the bits of its binary representation.
 * Note:
 * 1. The given integer is guaranteed to fit within the range of a 32-bit signed integer.
 * 2. You could assume no leading zero bit in the integer’s binary representation.
 *
 */

/*
 * Solution: to flip the bits, we can use ~ operator. However,
 * the leading zeros would all be turned into 1, which means
 * we would get a wrong number (and it's negative).
 * So we should calculate the mask for the original number.
 * E.g., the original number is 5, which is b101, the mask should
 * be b111, we could & the mask with the complemented number to
 * remove the leading 1s.
 */
int findComplement(int num) {
    int tmp = num, mask = 0;
    while (tmp) {
        tmp >>= 1;
        mask = (mask << 1) + 1; 
        printf("%d\n", tmp);
    }
    return (~num) & mask;
}

int main(int argc, char *argv[])
{
    int num = 0, comp = 0;

    if (argc != 2) {
        printf("Please input a src number\n");
        return 1;
    }
    num = atoi(argv[1]);
    comp = findComplement(num);
    printf("comp for %d is %d\n", num, comp);

    return 0;
}
