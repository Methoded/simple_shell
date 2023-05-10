#include "shell.h"

/**
 *
 ** _mem_set - this will fill memory with a constant byte
 *@s: Pointer to memory area
 *@b: Byte to be filled with
 *@n: Amount of bytes to be filled with
 *Return: {s} a pointer to a memory area s

 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * f_free -  this will make freerly a String of string s of s 
 * @pp: string of strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _real_loc -  real_locates the block of memory
 * @ptr: the pointer to previous malloc located block.
 * @old_size: byte size of the previous block.
 * @new_size: byte size of the new block.
 *
 * Return: the pointer to de o'block nameen
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
