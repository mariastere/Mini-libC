// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */
	int rezultat = syscall(__NR_open, filename, flags);
    if (rezultat >= 0) {
        return rezultat;
    } else {
		errno = -rezultat;
		return -1;
	}
}
