// SPDX-License-Identifier: BSD-3-Clause

#include <time.h>
#include <errno.h>
#include <unistd.h>

unsigned int sleep(unsigned int seconds)
{
    struct timespec req, rem;
    req.tv_sec = seconds;
    req.tv_nsec = 0;
    /* Apelează nanosleep(); dacă este întrerupt, rem conține timpul rămas */
    if (nanosleep(&req, &rem) == 0)
        return 0;

    /* Dacă a fost întrerupt de semnal */
    if (errno == EINTR)
        return rem.tv_sec;

    /* Alte erori (rare) – considerăm că nu a mai rămas timp */
    return 0;
}
