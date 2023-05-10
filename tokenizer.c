#include "shell.h"
#include <stdio.h>
/**
 * **strtow -- this will split a str into words and repeat delimiters that was previously ignored
 * @str: the input string
 * @d: the delimeter string.
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int g, i, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, g = 0; g < numwords; g++)
	{
		while (is_delim(str[i], d))
			i++;
		k = 0;
		while (!is_delim(str[i + k], d) && str[i + k])
			k++;
		s[g] = malloc((k + 1) * sizeof(char));
		if (!s[g])
		{
			for (k = 0; k < g; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[g][m] = str[i++];
		s[g][m] = 0;
	}
	s[g] = NULL;
	return (s);
}

/* alx project */
/**
 * **str_tow -- this will split a string into words
 * @str: the input str.
 * @d: the del
 * Return: the pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int i, g, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
		    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, g = 0; g < numwords; g++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
			k++;
		s[g] = malloc((k + 1) * sizeof(char));
		if (!s[g])
		{
			for (k = 0; k < g; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[g][m] = str[i++];
		s[g][m] = 0;
	}
	s[g] = NULL;
	return (s);
}
