#include "shell.h"

/**
 * _myhistory - fdjhghf hvbfug hgbjfvtfb fcuvygbvf drtfuvygbg vfddbctfv
 *  ghjjjj jjbh gubhnygvjbhg.
 * @info: vgbhjk jnblycftuyi kvugbjhv vyftcyfiv
 * fvgbjnjgu jbbvyuvg.
 *  Return: ughks 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - tfvgbj hnkdcfvg hbj
 * @info: dcfgv hbjnkcfgv hbjnkm
 * @str: dfvg ybhnj
 *
 * Return: guhjnkl 0 ofgvbhj, 1 fcvgbh
 */
int unset_alias(info_t *info, char *str)
{
	char *b, s;
	int reet;

	b = _strchr(str, '=');
	if (!b)
		return (1);
	s = *b;
	*b = 0;
	reet = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*b = s;
	return (reet);
}

/**
 * set_alias - dnhgjdc cyubftcrf udtryd
 * @info: fkfkufgiu yjtygfjgh
 * @str: vbcmhcfgn uygv
 *
 * Return: jvjvll 0 hjgkvj, 1 hgjgvuy
 */
int set_alias(info_t *info, char *str)
{
	char *b;

	b = _strchr(str, '=');
	if (!b)
		return (1);
	if (!*++b)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - fckhgf fcjmhvhfuydy
 * @node: fkugku fifyghbjhgf fjgj
 *
 * Return: kfluhb 0 tdyktfkuh, 1 jfiuyf
 */
int print_alias(list_t *node)
{
	char *B = NULL, *E = NULL;

	if (node)
	{
		B = _strchr(node->str, '=');
		for (E = node->str; E <= B; E++)
		_putchar(*E);
		_putchar('\'');
		_puts(B + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - jgkfk fkyuyugg gjhfgifyy jcfjgdjf (man alias)
 * @info: jfdkfkyf ifkufiktfkh igfkyufifufu fkfiyfytdghfj
 * cjhfiuf uydfk ufdudddjd dyfu.
 * Return: fkkfcfufk ftykf 0
 */
int _myalias(info_t *info)
{
	int y = 0;
	char *b = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (y = 1; info->argv[y]; y++)
	{
		b = _strchr(info->argv[y], '=');
		if (b)
			set_alias(info, info->argv[y]);
		else
			print_alias(node_starts_with(info->alias, info->argv[y], '='));
	}

	return (0);
}
