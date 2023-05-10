#include "shell.h"
/* string.c */

/**
 * _str_len - this will return the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string.
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _str_cmp --  this will perform lexicogarphic comparison of two strangs.
 * @s1: the First str
 * @s2: the Second str
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * startsWith - this will check if needle starts with haystack
 * @haystack: the string to search
 * @needle: Substring to find
 *
 * Return: the address of next charact of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _str_cat --  this will concatenates two strings
 * @dest: the dest buffer
 * @src: a source buffer
 *
 * Return: the pointer to dest buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
