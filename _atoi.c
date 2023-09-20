#include "main.h"

/**
 * interactive - returning to true if the shell is in interactive mood
 * @info: Means the struct address
 *
 * Return: to 1 if the sell in interactive mood, 0 other thing
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checking if char a delimeter
 * @l: the charctar check
 * @del: Means a delimeter strings
 * Return: to 1 if it true, 0 if it false
 */
int is_delim(char l, char *del)
{
	while (*del)
		if (*del++ == l)
			return (1);
	return (0);
}

/**
 * _isalpha - checking  alphabet char
 * @p: The char input
 * Return: to 1 if p is alphabetic, 0 other thing
 */

int _isalpha(int p)
{
	if ((p >= 'a' && p <= 'z') || (p >= 'A' && p <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converting the str to integer
 * @g: the str to convert
 * Return: to 0 if there is no number of strings, convert num other thing
 */

int _atoi(char *g)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; g[i] != '\0' && flag != 2; i++)
	{
		if (g[i] == '-')
			sign *= -1;

		if (g[i] >= '0' && g[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (g[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
