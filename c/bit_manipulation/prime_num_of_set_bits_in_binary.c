#include<stdio.h>
#include<stdlib.h>

/* Problem: Given two integers L and R, find the count of numbers in the range [L, R] (inclusive)
 * having a prime number of set bits in their binary representation.
 *
 * Recall that the number of set bits an integer has is the number of 1s present when written
 * in binary. For example, 21 written in binary is 10101 which has 3 set bits. Also, 1 is not a prime.)
 */

int OneCnt(int val)
{
    int cnt = 0;
    while (val) {
        if (val & 0x1)
            cnt++;
        val >>= 1;
    }
    return cnt;
}

int countPrimeSetBits_original(int L, int R) {
    int cnt = 0, i, j;
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    for (i = L; i <= R; i++) {
        int set = OneCnt(i);
        for (j = 0; j < sizeof(primes)/sizeof(int); j++) {
            if (set == primes[j]) {
                cnt++;
                break;
            }
        }
    }
    return cnt;
}

int main(int argc, char *argv[])
{
    int L = 0, R = 0, cnt = 0;

    if (argc < 3) {
        printf("Please input the range L to R, splitted by space\n");
        return 1;
    }

    L = atoi(argv[1]);
    R = atoi(argv[2]);

    if (L > R) {
        printf("R should be larger or equal to L\n");
        return 1;
    }

    cnt = countPrimeSetBits_original(L, R);
    printf("The count of prime number of set bits in binary between %d and %d is %d\n", L, R, cnt);

    return 0;
}
