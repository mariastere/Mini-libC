// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	/* TODO: Implement close(). */
	long rezultat = syscall(__NR_close, fd);
    if (rezultat >= 0) {
        return 0;
    } else {
		errno = -rezultat;
		return -1;
	}
}
