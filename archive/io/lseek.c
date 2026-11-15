// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence)
{
	/* TODO: Implement lseek(). */
	//fd = descriptorul de fisier obtinut din open
	//offset = distanta de mutat
	// whence = de unde se calculeaza deplasarea
	int rezultat = syscall(8, fd, offset, whence);
	if (rezultat >= 0) {
		return rezultat;
	} else {
		errno = -rezultat;
		return -1;
	}
}
