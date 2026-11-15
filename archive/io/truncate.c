// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int truncate(const char *path, off_t length)
{
	/* TODO: Implement truncate(). */
	int rezultat = syscall(__NR_truncate, path, length);
	if (rezultat >= 0) {
		return rezultat;
	} else {
		errno = -rezultat;
		return -1;
	}
}
