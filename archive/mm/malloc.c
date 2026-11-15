// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <internal/arch/x86_64/syscall_list.h>


#define MMAP_PROT (PROT_READ | PROT_WRITE) //drepturile
#define MMAP_FLAGS (MAP_PRIVATE | MAP_ANONYMOUS) //tipul maparii

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	if (size == 0) {
        return NULL;
    }
    void *inceput = mmap(NULL, size, MMAP_PROT, MMAP_FLAGS, -1, 0);
    if (inceput == MAP_FAILED) {
        errno = ENOMEM; //nu este destula memorie
        return NULL;
    }
    mem_list_add(inceput, size);
    return inceput;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	if (nmemb == 0 || size == 0) {
        return NULL;
    }
    size_t total = nmemb * size;
    if (nmemb != 0 && total / nmemb != size)
        return NULL;
    void *inceput = malloc(total);
    if (!inceput)
        return NULL;
    memset(inceput, 0, total); //umplem cu 0
    return inceput;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	if (!ptr) {
        return;
    }
    struct mem_list *celula = mem_list_find(ptr);
    if (!celula)
        return;
    int sistem = syscall(__NR_munmap, ptr, celula->len);
    mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
    if (size == 0) {
        free(ptr);
        return NULL;
    }
    struct mem_list *celula = mem_list_find(ptr);
    void *inceput = malloc(size);
    if (!inceput) {
        errno = ENOMEM;
        return NULL;
    }
    size_t size_copy;
    if (celula->len < size) {
        size_copy = celula->len;
    } else {
        size_copy = size;
    }
    memcpy(inceput, ptr, size_copy);
    free(ptr);
    return inceput;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	if (nmemb == 0 || size == 0) {
        return NULL;
    }
    size_t total = nmemb * size;
    if (nmemb != 0 && total / nmemb != size)
        return NULL;
    return realloc(ptr, total);
}
