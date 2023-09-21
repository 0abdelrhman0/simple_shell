#include "shell.h"

/**
 * get_environ - qwer tyulkjhg fdssxcvbnml kjhgfds werty
 * @info: yguhj vhbj gjvbmhk gjvbgvj
 * fghbjnkj cygvjhb
 * Return: tvhbj 0
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - jdewc khwjijh gjwvcb
 * @info: fvgbhjn fcvgjbh yghbn zsdxfcgjv
 *  Return: ghbejcn vhbyjcenk cyhbdjs
 * @var: okhbcg vkhb gvjbngv
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t y = 0;
	char *b;

	if (!node || !var)
		return (0);

	while (node)
	{
		b = starts_with(node->str, var);
		if (b && *b == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), y);
			y = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		y++;
	}
	return (info->env_changed);
}

/**
 * _setenv - dxfc vghbiuk jtfgsd,
 * yhujhjn bnjmkhbjn hbjn
 * @info: gvhbjn gvhbjnx hbjnex ybjnkmgbhn.
 * fghnmyjn dcvbhj
 * @var: cfvgbhjn xsvhb jnxsghjn
 * @value: dcfvgbh njkmjhgf dxdcvbj
 * Return: fcvgbhnj 0
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *b;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		b = starts_with(node->str, var);
		if (b && *b == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
