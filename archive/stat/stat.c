// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	/* TODO: Implement stat(). */
	int rezultat = syscall(__NR_stat, path, buf);
	if (rezultat >= 0) {
		return rezultat;
	} else {
		errno = -rezultat;
		return -1;
	}
}
