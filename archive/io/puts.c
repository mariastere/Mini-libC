#include <string.h>
#include <internal/io.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>

int puts(const char *str) {
    size_t lung = strlen(str);
    ssize_t result;
    result = write(1, str, lung);
    if (result < 0) //daca nu a reusit scrierea sirului
        return -1;
    result = write(1, "\n", 1);
    if (result < 0) //daca nu a reusit scrierea new line-ului
        return -1;
    return 0;
}
