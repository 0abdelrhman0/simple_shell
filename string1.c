#include "shell.h"

/**
 * _strcpy - fygiyvsfc xhty jhjct
 * @dest: qgdygu yfxq2yc
 * @src: oiuyts xcvbnmwu
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int y = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[y])
	{
		dest[y] = src[y];
		y++;
	}
	dest[y] = 0;
	return (dest);
}

/**
 * _strdup - lkjgfasdfgb
 * @str: dtyfkuyg urdrjfj yfjtk
 *
 * Return: hskwj hkdbcbdkjg kuvjhc akuvh
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *reet;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	reet = malloc(sizeof(char) * (length + 1));
	if (!reet)
		return (NULL);
	for (length++; length--;)
		reet[length] = *--str;
	return (reet);
}

/**
 * _puts - cfvygc yig csefuyg efsv tfyjyg
 * @str: sftdfwyu yukgwqgf vwrfwb
 *
 * Return: dftyhkef ugfev
 */
void _puts(char *str)
{
	int y = 0;

	if (!str)
		return;
	while (str[y] != '\0')
	{
		_putchar(str[y]);
		y++;
	}
}

/**
 * _putchar - sdfv bhgfvbnjh gfdcvb
 * @d: ufskdfiwg kufgkjdw
 *
 * Return: jsgfhud hivfueh 1.
 * On error, -1 kfgkgkyu ufkbff utdu ytftytftdcvv.
 */
int _putchar(char d)
{
	static int y;
	static char buf[WRITE_BUF_SIZE];

	if (d == BUF_FLUSH || y >= WRITE_BUF_SIZE)
	{
		write(1, buf, y);
		y = 0;
	}
	if (d != BUF_FLUSH)
		buf[y++] = d;
	return (1);
}
