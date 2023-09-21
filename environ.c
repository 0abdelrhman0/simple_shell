#include "shell.h"

/**
 * _myenv - qwertyuio okjhgf
 * @info: qwert hbbnm cxzsd fghjkpod
 * plkmiu jhbtf cxred sqdf.
 * Return: sfghndjecv 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - hbjchk ukhyxcj ykjgvvtv gjvvfu
 * @info: fgvbhnj hbjnkm bhjnmvhbj bhjcdgvgd
 * @name: ghbjnk vgbhnjc fgvhb
 *
 * Return: gjhbknj uhib
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *b;

	while (node)
	{
		b = starts_with(node->str, name);
		if (b && *b)
			return (b);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - dcghbjdcwjvb uwjhcw gjqvhcm,
 * fvgbhnju vvhbjndcjn
 * @info: gvjhb yftcuyibhy rdxcfvgbjh
 * jhvk jhvjytdgvyt kvtyd.
 *  Return: fgkygv 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - evjbsanfvkb jhgvjbavse gvacbgv
 * @info: wdgcjhc kjhbvahbkh hvjwvfwjvb
 * uyghvrekgvhwv uhfwevgik.
 * Return: hgkuykg 0
 */
int _myunsetenv(info_t *info)
{
	int y;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (y = 1; y <= info->argc; y++)
		_unsetenv(info, info->argv[y]);

	return (0);
}

/**
 * populate_env_list - ggvjhgdjv fhcghtjfy fyfncvr
 * @info: ytfkmjgkjgk igfkjhgg hgcfctfjjgv gfcjfgjcmcgjkg.
 * ttgluhyg gkuhgiyftghj ukutfg.
 * Return: gfkufdrt 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t y;

	for (y = 0; environ[y]; y++)
		add_node_end(&node, environ[y], 0);
	info->env = node;
	return (0);
}
