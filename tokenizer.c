#include "shell.h"

/**
 * **strtow - hhsgfe kjhdasjhv kvgscvkwej vjksjhk
 * @str: jdygdk ffxfgjc gfcf ffgjtf
 * @d: cjgvg jchgkvhi jhcgcc jhjc
 * Return: jyjytf fcnbvkbc fgxjghcj cgfxjhcj fjcfc
 */

char **strtow(char *str, char *d)
{
	int y, z, c, n, numwords = 0;
	char **l;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (y = 0; str[y] != '\0'; y++)
		if (!is_delim(str[y], d) && (is_delim(str[y + 1], d) || !str[y + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	l = malloc((1 + numwords) * sizeof(char *));
	if (!l)
		return (NULL);
	for (y = 0, z = 0; z < numwords; z++)
	{
		while (is_delim(str[y], d))
			y++;
		c = 0;
		while (!is_delim(str[y + c], d) && str[y + c])
			c++;
		l[z] = malloc((c + 1) * sizeof(char));
		if (!l[z])
		{
			for (c = 0; c < z; c++)
				free(l[c]);
			free(l);
			return (NULL);
		}
		for (n = 0; n < c; n++)
			l[z][n] = str[y++];
		l[z][n] = 0;
	}
	l[z] = NULL;
	return (l);
}

/**
 * **strtow2 - cnbvjfuug udfujfi
 * @str: fhvygvu fctutfv vygigy
 * @d: dtfig uydtfy ftxytfct ftcu
 * Return: dtifd udytfo tfurmncfdtyd rdurfui
 */
char **strtow2(char *str, char d)
{
	int y, z, c, n, numwords = 0;
	char **l;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (y = 0; str[y] != '\0'; y++)
		if ((str[y] != d && str[y + 1] == d) ||
				    (str[y] != d && !str[y + 1]) || str[y + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	l = malloc((1 + numwords) * sizeof(char *));
	if (!l)
		return (NULL);
	for (y = 0, z = 0; z < numwords; z++)
	{
		while (str[y] == d && str[y] != d)
			y++;
		c = 0;
		while (str[y + c] != d && str[y + c] && str[y + c] != d)
			c++;
		l[z] = malloc((c + 1) * sizeof(char));
		if (!l[z])
		{
			for (c = 0; c < z; c++)
				free(l[c]);
			free(l);
			return (NULL);
		}
		for (n = 0; n < c; n++)
			l[z][n] = str[y++];
		l[z][n] = 0;
	}
	l[z] = NULL;
	return (l);
}
