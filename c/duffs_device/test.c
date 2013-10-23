#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "duffs_device.h"

#define MAXLEN 32767

int test_cases[] = { 1, 10, 13, 29, 2048, 32767 };
int s[MAXLEN], t[MAXLEN];

int main()
{
    int i, j;

    for (i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); ++i) {
        int len = test_cases[i];
        int *from = s, *to = t;

        for (j = 0; j < len; ++j)
            s[j] = rand();

        UNROLL(len, 8, *to++ = *from++);

        for (j = 0; j < len; ++j) 
            assert(s[j] == t[j]);
    }

    return 0;
}
