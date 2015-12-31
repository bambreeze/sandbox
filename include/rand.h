#ifndef MY_RAND_H
#define MY_RAND_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

inline int myrand (int limit)
{
    time_t t;
    srand((unsigned) time(&t));
    return rand() % limit;
}

#endif
