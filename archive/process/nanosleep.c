#include <time.h>
#include <errno.h>
#include <internal/arch/x86_64/syscall_list.h>

int nanosleep(const struct timespec *req, struct timespec *rem)
{
    //vedem daca parametrii sunt valizi si setam variabila errno corespunzator
    if (req == NULL || req->tv_nsec < 0 || req->tv_nsec >= 1000000000L) {
        errno = EINVAL;
        return -1;
    }
    //facem apel de sistem
    long rezultat = syscall(__NR_nanosleep, req, rem);
    if (rezultat < 0) {
        errno = -rezultat;
        return -1;
    }
    return 0;
}
