#include "shell.h"

/**
 * strtow - splits string into words
 * @str: input string
 * @d: delimeter string
 * Return: pointer to array of string, NULL on failure
 */
char **strtow(char *str, char *d)
{
	int i, j, k, l, num_words = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
			num_words++;
	if (num_words == 0)
		return (NULL);
	s = malloc((1 + num_words) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < num_words; j++)
	{
		while (is_delim(str[i], d))
			i++;
		k = 0;
		while (!is_delim(str[i + k], d) && str[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (l = 0; l < k; l++)
			s[j][l] = str[i++];
		s[j][l] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * strtow2 - splits string into words
 * @str: input string
 * @d: delimeter string
 * Return: pointer to array of string, NULL on failure
 */
char **strtow2(char *str, char d)
{
	int i, j, k, l, num_words = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
				    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			num_words++;
	if (num_words == 0)
		return (NULL);
	s = malloc((1 + num_words) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < num_words; j++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (l = 0; l < k; l++)
			s[j][l] = str[i++];
		s[j][l] = 0;
	}
	s[j] = NULL;
	return (s);
}
