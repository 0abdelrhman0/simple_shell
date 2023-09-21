#include "shell.h"

/**
 * list_len - qsdcf thn jiogcvb
 * @t: dfgyuk loihf
 *
 * Return: pojhgc sdfg
 */
size_t list_len(const list_t *t)
{
	size_t y = 0;

	while (t)
	{
		t = t->next;
		y++;
	}
	return (y);
}

/**
 * list_to_strings - lkjhgfdz xcvbnmi jngfwd
 * @head: syjfvjyd ydrydj yrsurdth
 *
 * Return: srhjhuff ltkjydt
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t y = list_len(head), z;
	char **strs;
	char *str;

	if (!head || !y)
		return (NULL);
	strs = malloc(sizeof(char *) * (y + 1));
	if (!strs)
		return (NULL);
	for (y = 0; node; node = node->next, y++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (z = 0; z < y; z++)
				free(strs[z]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[y] = str;
	}
	strs[y] = NULL;
	return (strs);
}


/**
 * print_list - oieprbvu uiwbclow euflsd kkdlsa zbffli
 * @t: poweqrebcuxi jkadrwodj
 *
 * Return: qafsjdkier gsjsk ddkis
 */
size_t print_list(const list_t *t)
{
	size_t y = 0;

	while (t)
	{
		_puts(convert_number(t->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(t->str ? t->str : "(nil)");
		_puts("\n");
		t = t->next;
		y++;
	}
	return (y);
}

/**
 * node_starts_with - sowqrefsn mailde kgjfaklwer
 * @node: awqetw jaloiuevb dhdkjg
 * @pre: ieyrhnd riles jdgfu
 * @h: jshrianb jsgfus udhsk
 *
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *pre, char h)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, pre);
		if (p && ((h == -1) || (*p == h)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - jashidmdbc bdjskiehdg kaadj
 * @head: adjbjdak akjdakj djkalse
 * @node: lowqdbabdhj hdufvndj
 *
 * Return: weybdjs hdkiw dtalke -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t y = 0;

	while (head)
	{
		if (head == node)
			return (y);
		head = head->next;
		y++;
	}
	return (-1);
}
