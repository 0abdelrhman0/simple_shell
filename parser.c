#include "shell.h"

/**
 * is_cmd - ogjysr utsrdfyf ydjfy
 * @info: fdsjgkcsk
 * @path: dytkcrt fjkfdd
 *
 * Return: 1 dhjgh, 0 jfxfjg
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - duplicates characters
 * @pathe: gfghgyt fghu
 * @start: gfukuylh ruf
 * @stop: kuyfuyg ufukgy
 *
 * Return: fhjyd utrdftv utyf
 */
char *dup_chars(char *pathe, int start, int stop)
{
	static char buf[1024];
	int y = 0, c = 0;

	for (c = 0, y = start; y < stop; y++)
		if (pathe[y] != ':')
			buf[c++] = pathe[y];
	buf[c] = 0;
	return (buf);
}

/**
 * find_path - fjhhk yfvyt ydubfg yfvjyg
 * @info: rfghj tdfvkn fhxt
 * @pathe: jdtfg iytdfgb fft
 * @cmd: kjhes cvbwrty jnbv
 *
 * Return: dcvjkk dhrcdrf tffdfb
 */
char *find_path(info_t *info, char *pathe, char *cmd)
{
	int y = 0, curr_pos = 0;
	char *path;

	if (!pathe)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathe[y] || pathe[y] == ':')
		{
			path = dup_chars(pathe, curr_pos, y);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathe[y])
				break;
			curr_pos = y;
		}
		y++;
	}
	return (NULL);
}
