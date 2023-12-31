#include "shell.h"

/**
 * hsh - main shell loooop
 * @info: fgvhbkj gvhkbjln mnbvcnvgfjh
 * @av: fcyghkj khjfgvjhkb fcgvkhbj fchgjvkh
 *
 * Return: 0 dfhcgjvk 1 jvbknm cgjvkhb jvhvvhcj
 */
int hsh(info_t *info, char **av)
{
	ssize_t R = 0;
	int builtin_ret = 0;

	while (R != -1 && builtin_ret != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		R = get_input(info);
		if (R != -1)
		{
			set_info(info, av);
			builtin_ret = find_builtin(info);
			if (builtin_ret == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_ret);
}

/**
 * find_builtin - mnbvdfgk utkhkg fcgjkcfc
 * @info: tvmutf gfmuftjf ygvkyfjy
 *
 * Return: -1 ftyghb ygvkhb fygvjhkb
 */
int find_builtin(info_t *info)
{
	int y, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (y = 0; builtintbl[y].type; y++)
		if (_strcmp(info->argv[0], builtintbl[y].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[y].func(info);
			break;
		}
	return (built_in_ret);
}

/**
 * find_cmd - fcgvjhkwdc  gjvkbnwdc gvhkbj
 * @info: fgjh kdgcuw dykkwhcg dckjbwcdv
 *
 * Return: dyft uygiuh lfcgvjbkjn
 */
void find_cmd(info_t *info)
{
	char *paath = NULL;
	int y, c;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (y = 0, c = 0; info->arg[y]; y++)
		if (!is_delim(info->arg[y], " \t\n"))
			c++;
	if (!c)
		return;

	paath = find_path(info, _getenv(info, "PAATH="), info->argv[0]);
	if (paath)
	{
		info->path = paath;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PAATH=")
					|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}

/**
 * fork_cmd - mnbvcxz dfgyg uhjkjgdd gjvbjkg
 * @info: dfghjnk hkbnkjj gvhkb cfvgb
 *
 * dfghjnlk fcgvhbkjnl
 */
void fork_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* dfcgvjhkb yfgvhbk fcgv */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* fghjk tfgvjhbk yfgvjh */
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
