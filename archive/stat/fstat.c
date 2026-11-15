// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	/* TODO: Implement fstat(). */
	int rezultat = syscall(__NR_fstat, fd, st);
	if (rezultat >= 0) {
		return rezultat;
	} else {
		errno = -rezultat;
		return -1;
	}
}
