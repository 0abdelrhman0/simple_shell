#include "shell.h"

/**
 * _strlen - fckvuit yvgyjvd uyyyyrdjufyjy.
 * @c: tjyfkfutug ygvjhk ffhfxytrcj
 *
 * Return: mbnvhxh tygjgi
 */
int _strlen(char *c)
{
	int y = 0;

	if (!c)
		return (0);

	while (*c++)
		y++;
	return (y);
}

/**
 * _strcmp - tryt uyiuhgcvb bnjdhjkmn szxdcfvgj
 * @s6: fgvbhnj rftgyhuj
 * @s7: cfvgbhnj vghbjnkm
 *
 * Return: negative if s6 < s7, positive if s6 > s7, zero if s6 == s7
 */
int _strcmp(char *s6, char *s7)
{
	while (*s6 && *s7)
	{
		if (*s6 != *s7)
			return (*s6 - *s7);
		s6++;
		s7++;
	}
	if (*s6 == *s7)
		return (0);
	else
		return (*s6 < *s7 ? -1 : 1);
}

/**
 * starts_with - vgjvsjv jhgvjh fhcvmsdhhv
 * @ck: poiuye rtyu xcvbn
 * @le: xcvbnm mosiutft ghkhjlfcgv
 *
 * Return: lkjas dfghjkty euigvbc
 */
char *starts_with(const char *ck, const char *le)
{
	while (*le)
		if (*le++ != *ck++)
			return (NULL);
	return ((char *)ck);
}

/**
 * _strcat - zxcv bnpoi uyrfdxcvkm
 * @destt: fgvjhkjv jlkcbvnbm nuyigghmv
 * @srrc: poihbnj gfsfvkhblj
 *
 * Return: sdfghjs fcgkbn vnmb
 */
char *_strcat(char *destt, char *srrc)
{
	char *reet = destt;

	while (*destt)
		destt++;
	while (*srrc)
		*destt++ = *srrc++;
	*destt = *srrc;
	return (reet);
}
