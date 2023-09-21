#include "shell.h"

/**
 * interactive - saj kasjc kagf fjsu dusagf
 * @info: dgsjsf ydhjstekd gdsl fsaigf
 * Return: 1 fsjfk gsjyacshkiub gsf, 0 tdhjs fs odhn
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - hssj hsjkdlisb hayja ppou
 * @l: afsyk gaisf agyqio
 * @del: aaa aaaasss ssyudk
 * Return: wtqd 1 dgiu 0 dqugd
 */
int is_delim(char l, char *del)
{
	while (*del)
		if (*del++ == l)
			return (1);
	return (0);
}

/**
 * _isalpha - skdgy ysyg
 * @p: hdgsj
 * Return: 1 if p hdgsl wd, 0 oqdcb
 */

int _isalpha(int p)
{
	if ((p >= 'a' && p <= 'z') || (p >= 'A' && p <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - csh sfshy ysrmjs lds
 * @g: shsg tau lsyloe ysfr siv
 * Return: 0 if no shq hqfhdfgsk gdtts lgdyjsg
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
