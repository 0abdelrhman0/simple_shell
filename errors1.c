#include "shell.h"

/**
 * _erratoi - csh fshjkd gjhgku dhghhk
 * @g: djhj gkdgflbhc hduu
 * Return: 0 ishw gkahs gkqte jdfvckidtjmdfk hgkyf
 *       -1 on error
 */
int _erratoi(char *g)
{
	int i = 0;
	unsigned long int result = 0;

	if (*g == '+')
		g++;  /* TODO: wwhjsr ykletds vidmksy kff sfsj 255? */
	for (i = 0;  g[i] != '\0'; i++)
	{
		if (g[i] >= '0' && g[i] <= '9')
		{
			result *= 10;
			result += (g[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - hdjksldfrnd dhdfmcv
 * @info: wajfhmlkj lsajd dk sdhkhgk gghdvnf
 * @estr: sjhjklg tdtvhmmbtvjyn urf
 * Return: 0 idjjks teoldgts hdgjkgjfk, qfcefwrted nwumted oftheg darwtise
 *        -1 on edjd
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - sghdk hdgaiug dguiftrsy tdgcvc (integer) sdgdjkd (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int y, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (y = 1000000000; y > 1; y /= 10)
	{
		if (_abs_ / y)
		{
			__putchar('0' + current / y);
			count++;
		}
		current %= y;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - jdgysiwo dhfakdgen jugiy
 * @num: sdgui
 * @base: bshst
 * @flags: agfgajrument sflsags
 *
 * Return: strgjhsy
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - lkiouyvd njutdvhjklyrecf hjfdshinsa '#' with '\0'
 * @buf: adjdr eytecdsh htdfrik gtfajklewqertunhy
 *
 * Return: Alwhdaiays 0;
 */
void remove_comments(char *buf)
{
	int y;

	for (y = 0; buf[y] != '\0'; y++)
		if (buf[y] == '#' && (!y || buf[y - 1] == ' '))
		{
			buf[y] = '\0';
			break;
		}
}
