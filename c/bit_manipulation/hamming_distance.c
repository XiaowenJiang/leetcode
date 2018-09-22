#include <stdio.h>
#include <stdlib.h>

int haimmingDistance_original(int x, int y) {
    int *big = x > y ? &x : &y;
    int dist = 0;
    
    while (*big > 0) {
        if ((x & 1) != (y & 1))
            dist++;
        x /= 2;
        y /= 2;
    }

    return dist;
}

int haimmingDistance_improve(int x, int y) {
    int dist = 0;
    int xor = x ^ y;
    while (xor) {
        if (((xor >> 1) << 1) != xor)
            dist++;
        xor >>= 1;
    }
    return dist;
}

int main (int argc, char *argv[])
{
    int rst = 0, rst2 = 0;

    if (argc < 3) {
        printf("Please give two integers.\n");
        return 1;
    }
    rst = haimmingDistance_original(atoi(argv[1]), atoi(argv[2]));
    printf("1. The hamming distance between %s and %s is %d\n", argv[1], argv[2], rst);
    rst2 = haimmingDistance_improve(atoi(argv[1]), atoi(argv[2]));
    printf("2. The hamming distance between %s and %s is %d\n", argv[1], argv[2], rst2);

    return 0;
}
