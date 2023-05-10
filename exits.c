#include "shell.h"
#include<stdio.h>

/**
 ** Strncpy -  this will copies a string
 *@dest: Destination string to be copied then
 *@src: Source string
 *@n: Amount of chars to be copied
 *Return: Concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
    char *s = dest;
    int i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    for (; i < n; i++) {
        dest[i] = '\0';
    }
    return s;
}

/**
 ** Strncat - this will concatenate two strings
 *@dest: First string
 *@src: Second string
 *@n: Amount of bytes to be used
 *Return: Concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
    char *s = dest;
    while (*dest) {
        dest++;
    }
    while (n-- > 0 && *src) {
        *dest++ = *src++;
    }
    *dest = '\0';
    return s;
}

char *_strchr(char *s, char c)
{
    while (*s != '\0') {
        if (*s == c) {
            return s;
        }
        s++;
    }
    return NULL;
}
