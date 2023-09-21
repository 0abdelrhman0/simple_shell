#include "shell.h"

/**
 * is_chain - rtyjiwhc yiuvkjxutcfyg tfcvyjtuyuv fjchytd
 * @info: vbcnkuweu fcgvu
 * @buf: ertyui gbnm
 * @b: dfgshjtrye uiwvcbnxm
 *
 * Return: 1 if ccvxbnmzgdhj, 0 rteyuwivc bxnzm
 */
int is_chain(info_t *info, char *buf, size_t *b)
{
	size_t z = *b;

	if (buf[z] == '|' && buf[z + 1] == '|')
	{
		buf[z] = 0;
		z++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[z] == '&' && buf[z + 1] == '&')
	{
		buf[z] = 0;
		z++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[z] == ';') /* oiuytrw sdfg hjnbvcxzxx */
	{
		buf[z] = 0; /* zxcvb nmoiuytre rthdsxcv */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*b = z;
	return (1);
}

/**
 * check_chain - pokmijn hugvftdx xsewafv egyrtht
 * @info: xcfvef vbnmoiu ytrkjhdfgh
 * @buf: cvbn cmny uifbgeb
 * @b: poiuefr ytrewertyui
 * @y: vhbjcd chkfikg uskcjygj svfsvmj
 * @leen: dfgh jdhgkjn bfcvkbdrvg
 *
 * Return: uiryi
 */
void check_chain(info_t *info, char *buf, size_t *b, size_t y, size_t leen)
{
	size_t z = *b;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[y] = 0;
			z = leen;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[y] = 0;
			z = leen;
		}
	}

	*b = z;
}

/**
 * replace_alias - etrurityf ytmyggfx cfhgjv
 * @info: bvcnmvbxh hgdutykf
 *
 * Return: 1 iurtrbvxn 0 diybtykg
 */
int replace_alias(info_t *info)
{
	int y;
	list_t *node;
	char *b;

	for (y = 0; y < 10; y++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		b = _strchr(node->str, '=');
		if (!b)
			return (0);
		b = _strdup(b + 1);
		if (!b)
			return (0);
		info->argv[0] = b;
	}
	return (1);
}

/**
 * replace_vars - sdfyvbiy gubh iouytvbci vymvzic tfyikud
 * @info: qwertyui xcvbnm
 *
 * Return: 1 fvgubhinj, 0 rtyunim
 */
int replace_vars(info_t *info)
{
	int y = 0;
	list_t *node;

	for (y = 0; info->argv[y]; y++)
	{
		if (info->argv[y][0] != '$' || !info->argv[y][1])
			continue;

		if (!_strcmp(info->argv[y], "$?"))
		{
			replace_string(&(info->argv[y]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[y], "$$"))
		{
			replace_string(&(info->argv[y]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[y][1], '=');
		if (node)
		{
			replace_string(&(info->argv[y]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[y], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - cvbnm kjhgf ertyu
 * @d: gbhjnk gvbhjnkm
 * @w: nfvgbhjn gvbhjn
 *
 * Return: 1 fgvbhjnkm 0 vgbhnj
 */
int replace_string(char **d, char *w)
{
	free(*d);
	*d = w;
	return (1);
}
