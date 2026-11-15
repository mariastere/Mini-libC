#ifndef _TIME_H
#define _TIME_H

#include <stddef.h>

struct timespec {
    long tv_sec; //secundele
    long tv_nsec; //nanosecundele
};

int nanosleep(const struct timespec *req, struct timespec *rem);
unsigned int sleep(unsigned int seconds);

#endif
