#include "shell.h"

/**
 * _eputs - dfsgh hybjn tvybunik
 * @str: poijhg wefghjij
 *
 * Return: yujnkm
 */
void _eputs(char *str)
{
	int y = 0;

	if (!str)
		return;
	while (str[y] != '\0')
	{
		_eputchar(str[y]);
		y++;
	}
}

/**
 * _eputchar - rtvybun rctvybu
 * @s: cvgbhjnk tybun
 *
 * Return: dfvgbhnjyv vghbj 1
 * On error, -1 rftgyhujik sedrftgyu
 */
int _eputchar(char s)
{
	static int y;
	static char buf[WRITE_BUF_SIZE];

	if (s == BUF_FLUSH || y >= WRITE_BUF_SIZE)
	{
		write(2, buf, y);
		y = 0;
	}
	if (s != BUF_FLUSH)
		buf[y++] = s;
	return (1);
}

/**
 * _putfd - rtyuilkmnvc fgvhbjn vghbjn
 * @s: mjnhbg bvfbgmjn
 * @fd: tgyhujik fyvgbj
 *
 * Return: dtfcyvgbhn 1
 * On error, ftgyhujk fcyvgbjc fcgvhb.
 */
int _putfd(char s, int fd)
{
	static int y;
	static char buf[WRITE_BUF_SIZE];

	if (s == BUF_FLUSH || y >= WRITE_BUF_SIZE)
	{
		write(fd, buf, y);
		y = 0;
	}
	if (s != BUF_FLUSH)
		buf[y++] = s;
	return (1);
}

/**
 * _putsfd - wertyu ikjfsdfg
 * @str: dfvgbhjnkfg hbnj
 * @fd: ihgnn fghbn fgvhbn
 *
 * Return: thsdc ghjmkoj
 */
int _putsfd(char *str, int fd)
{
	int y = 0;

	if (!str)
		return (0);
	while (*str)
	{
		y += _putfd(*str++, fd);
	}
	return (y);
}
