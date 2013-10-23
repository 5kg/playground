#pragma once

#include <assert.h>
#include "macro.h"

#define DUFFS_CASE(id, action) case id: action;

/*
 * UNROLL(num, size, action):
 * Use duff's device to unroll 'num' actions with loop size equals 'size'.
 *
 * Example:
 *      int len = 1024;
 *      UNROLL(len, 8, *to++ = *from++);
 */
#define UNROLL(num, size, action) \
    do { \
        assert(num > 0); \
        int c = (num + DEC(size)) / size; \
        switch (num % size) { \
        case 0: do { action; \
        REPEAT_FROM_DOWNTO(DEC(size), 1, DUFFS_CASE, action) \
                } while (--c); \
        } \
    } while (0)
