#include "shell.h"

/**
 * input_buf - qwerty zxcvbn
 * @info: zxcvbnsdfgh hkuhkud
 * @buf: tyfgkyu fygvuiyc iufy
 * @len: vghbh jvhvjjgj ghuygjv fycfgv
 *
 * Return: bytes read
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t R = 0;
	size_t len_p = 0;

	if (!*len) /* if nothing left in the buffer, fill it */
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		R = getline(buf, &len_p, stdin);
#else
		R = _getline(info, buf, &len_p);
#endif
		if (R > 0)
		{
			if ((*buf)[R - 1] == '\n')
			{
				(*buf)[R - 1] = '\0'; /* remove trailing newline */
				R--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			/* if (_strchr(*buf, ';')) is this a command chain? */
			{
				*len = R;
				info->cmd_buf = buf;
			}
		}
	}
	return (R);
}

/**
 * get_input - hibcifw ijwciywg ccdw
 * @info: ydcgwui uvdwc
 *
 * Return: fvgbhxs yghe xssce
 */
ssize_t get_input(info_t *info)
{
	static char *buf; /* the ';' command chain buffer */
	static size_t y, z, len;
	ssize_t R = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	R = input_buf(info, &buf, &len);
	if (R == -1) /* EOF */
		return (-1);
	if (len) /* we have commands left in the chain buffer */
	{
		z = y; /* init new iterator to current buf position */
		p = buf + y; /* get pointer for return */

		check_chain(info, buf, &z, y, len);
		while (z < len) /* iterate to semicolon or end */
		{
			if (is_chain(info, buf, &z))
				break;
			z++;
		}

		y = z + 1; /* increment past nulled ';'' */
		if (y >= len) /* reached end of buffer? */
		{
			y = len = 0; /* reset position and length */
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p; /* pass back pointer to current command position */
		return (_strlen(p)); /* return length of current command */
	}

	*buf_p = buf; /* else not a chain, pass back buffer from _getline() */
	return (R); /* return length of buffer from _getline() */
}

/**
 * read_buf - wdcgvhbwkd
 * @info: cvhgwvcj
 * @buf: vcwdjhc
 * @y: shwgvc
 *
 * Return: hbhdcw
 */
ssize_t read_buf(info_t *info, char *buf, size_t *y)
{
	ssize_t R = 0;

	if (*y)
		return (0);
	R = read(info->readfd, buf, READ_BUF_SIZE);
	if (R >= 0)
		*y = R;
	return (R);
}

/**
 * _getline - uhwekfhh khefwliu hwaefugk
 * @info: gvhbq kqje lqenfh
 * @ptr: hdksqdck ikhqec khbd
 * @length: dfghj fghj yghb uhj
 *
 * Return: dcfgv
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t y, len;
	size_t x;
	ssize_t R = 0, S = 0;
	char *b = NULL, *new_p = NULL, *c;

	b = *ptr;
	if (b && length)
		S = *length;
	if (y == len)
		y = len = 0;

	R = read_buf(info, buf, &len);
	if (R == -1 || (R == 0 && len == 0))
		return (-1);

	c = _strchr(buf + y, '\n');
	x = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(b, S, S ? S + x : x + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (b ? free(b), -1 : -1);

	if (S)
		_strncat(new_p, buf + y, x - y);
	else
		_strncpy(new_p, buf + y, x - y + 1);

	S += x - y;
	y = x;
	b = new_p;

	if (length)
		*length = S;
	*ptr = b;
	return (S);
}

/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
