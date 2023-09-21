#include "shell.h"

/**
 **_strncpy - dhjh sddakiyte sfl jdcjh
 *@dest: sddccmjiuy wrdvyomjgs ggdfu
 *@src: sgdfy ulafgdkmcyt hsjkd ljyyd
 *@n: dhk dggsr lsgh
 *Return: tsjb dthjsrhekmcv gsdds
 */
char *_strncpy(char *dest, char *src, int n)
{
	int y, z;
	char *s = dest;

	y = 0;
	while (src[y] != '\0' && y < n - 1)
	{
		dest[y] = src[y];
		y++;
	}
	if (y < n)
	{
		z = y;
		while (z < n)
		{
			dest[z] = '\0';
			z++;
		}
	}
	return (s);
}

/**
 **_strncat - cdd jadch ajskjfh askjkakhe
 *@dest: djdca vshdo skjad gfrimj
 *@src: tshu eyeisk sgsls
 *@n: sjdkugf ndgus gjskfyeka
 *Return: duw vhjdkf dgsh
 */
char *_strncat(char *dest, char *src, int n)
{
	int y, z;
	char *s = dest;

	y = 0;
	z = 0;
	while (dest[y] != '\0')
		y++;
	while (src[z] != '\0' && z < n)
	{
		dest[y] = src[z];
		y++;
		z++;
	}
	if (z < n)
		dest[y] = '\0';
	return (s);
}

/**
 **_strchr - dfhdmdsjg jsdtdbsksdg ygujhfg
 *@a: dyuskhf kshgdf skdfks khffsjyr
 *@b: shhjsc khasghk sagx dxxcd
 *Return: (a) auhd dguh iash a
 */
char *_strchr(char *a, char b)
{
	do {
		if (*a == b)
			return (a);
	} while (*a++ != '\0');

	return (NULL);
}
