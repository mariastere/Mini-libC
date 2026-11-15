// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	while(*source) {
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	while(*source && len) {
		*destination = *source;
		destination++;
		source++;
		len--;
	}
	while (len) {
        *destination = '\0';
		destination++;
        len--;
    }
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	char *rdest = destination;
    while (*destination)
      destination++;

	while (*source) {
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	destination = rdest;
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	char *rdest = destination;
    while (*rdest)
      rdest++;

	while (*source && len) {
		*rdest = *source;
		rdest++;
		source++;
		len--;
	}
	*rdest = '\0';
	destination = rdest;
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	int ok = 0;
	while(*str1 && *str2) {
		if (*str1 == *str2){
			str1++;
			str2++;
			} else if (*str1 > *str2) {
			ok = 1;
			break;
		} else {
			ok = -1;
			break;
		}
	}
	//daca primul e mai scurt decat al 2-lea, dar au avut toate caracterele egale -> -1
	if (*str1 == '\0' && *str2 != '\0' && ok == 0)
		return -1;
	//daca al doilea e mai scurt decat primul si au avut toate caracterele egale -> 1
	else if (*str1 != '\0' && *str2 == '\0' && ok == 0)
		return 1;
	//daca au aceeasi lungime si toate caracterele egale -> 0
	else if (*str1 == '\0' && *str2 == '\0' && ok == 0)
		return 0;
	//daca am gasit in primul sir un caracter mai mare decat unul din al 2-lea sir -> 1
	else if (ok == 1)
		return 1;
	return -1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	int ok = 0;
	while(*str1 && *str2 && len) {
		if (*str1 == *str2){
			str1++;
			str2++;
			len--;
			} else if (*str1 > *str2) {
			ok = 1;
			break;
		} else {
			ok = -1;
			break;
			}
	}
	//daca nu am terminat sirurile, dar am comparat primele len caractere si au fost egale -> 0
	if (*str1 != '\0' && *str2 != '\0' && ok == 0 && len == 0)
		return 0;
	//daca am terminat primul sir si am comparat primele len caractere si au fost egale -> 0
	else if (*str1 == '\0' && *str2 != '\0' && ok == 0 && len == 0)
		return 0;
	//daca am terminat al 2-lea sir si am comparat primele len caractere si au fost egale -> 0
	else if (*str1 != '\0' && *str2 == '\0' && ok == 0 && len == 0)
		return 0;
	//daca am terminat sirurile si am comparat cele len caractere si au foat toate egale
	else if (*str1 == '\0' && *str2 == '\0' && ok == 0 && len == 0)
		return 0;
	//daca am terminat primul sir, dar pe al 2-lea nu, inseamna ca mai am de comparat (len nu e 0)
	else if (*str1 == '\0' && *str2 != '\0' && ok == 0)
		return -1;
	//daca am terminat primul sir, dar pe al 2-lea nu, inseamna ca mai am de comparat teoretic
	else if (*str1 != '\0' && *str2 == '\0' && ok == 0)
		return 1;
	//daca am terminat sirurile si au fost egale dar eu nu am terminat cele len caractere
	else if (*str1 == '\0' && *str2 == '\0' && ok == 0)
		return 0;
	else if (ok == 1)
		return 1;
	return -1;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	//prima aparitie din sir
	while (*str &&*str != c) {
		str++;
	}
	if (*str) {
		return str;
	} else {
		return NULL;
	}
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	//ultima aparitie din sir
	char *result = NULL;
	while (*str) {
		if (*str == c) {
			result = str;
		}
		str++;
	}
	if (c == '\0') {
		return str;
	} else {
		return result;
	}
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	//prima aparitie a subsirului in sir
	if (!*needle) {
		return haystack;
	}
    for (char *h = haystack; *h; h++) {
        char *h_copy = h;
        char *needle_copy = needle;
        while (*h_copy && *needle_copy && (*h_copy == *needle_copy)) {
            h_copy++;
            needle_copy++;
        }

        if (*needle_copy == '\0')  // daca am ajuns la finalul lui needle, intoarcem aparitia
            return h;
    }
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	if (!*needle) return haystack;
	char *result = NULL;
    for (char *h = haystack; *h; h++) {
        char *h_copy = h;
        char *needle_copy = needle;
        while (*h_copy && *needle_copy && (*h_copy == *needle_copy)) {
            h_copy++;
            needle_copy++;
        }

        if (*needle_copy == '\0')
            result = h;
    }
	return result;
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	size_t i;
	char *dest = destination;
	const char *src = source;
	for (i = 0; i < num; i++){
		*dest = *src;
		dest++;
		src++;
	}
	destination = dest;
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *dest = destination;
	const char *src = source;
	//daca destinatia e egala cu sursa sau trebuie sa copiem 0 octeti, returnam direct destination
	if (dest == src || num == 0)
        return destination;
	//copiem invers in caz ca avem suprapunere
    if (dest > src && dest < src + num) {
        for (size_t index = num; index > 0; index--)
            dest[index - 1] = src[index - 1];
    } else {
	//altfel, copiem normal
        for (size_t index = 0; index < num; index++)
            dest[index] = src[index];
    }
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	char *dest = ptr1;
	char *src = ptr2;
	int ok = 0;
	while(*dest && *src && num) {
		if (*dest == *src){
			dest++;
			src++;
			num--;
			} else if (*dest > *src) {
			ok = 1;
			break;
		} else {
			ok = -1;
			break;
			}
	}
	if (*dest != '\0' && *src != '\0' && ok == 0 && num == 0)
		return 0;
	else if (*dest == '\0' && *src != '\0' && ok == 0 && num == 0)
		return 0;
	else if (*dest == '\0' && *src != '\0' && ok == 0)
		return -1;
	else if (*dest != '\0' && *src == '\0' && ok == 0)
		return 1;
	else if (*dest == '\0' && *src == '\0' && ok == 0)
		return 0;
	else if (ok == 1)
		return 1;
	return -1;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	char *src = source;
	size_t index = num;
	while (index > 0) {
		*src = value;
		src++;
		index--;
	}
	source = src;
	return source;
}
