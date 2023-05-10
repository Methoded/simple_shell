#include "shell.h"

/**
 * b_free -  this will freerly a pointer and NUlL the address
 * @ptr: the address of a pointer to free
 * alx
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}

	return (0);
}
