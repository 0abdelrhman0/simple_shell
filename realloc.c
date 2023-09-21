#include "shell.h"

/**
 * _memset - akdjhkdgyd weudwu gqgcw
 * @a: dsgcsagc khjgf kgfcvnxfjg
 * @e: dsagflas kfkas gcgfkyf
 * @c: sdvck ufksfvs jvkgv
 * Return: (a) khhss kugjhcl hghj
 */
char *_memset(char *a, char e, unsigned int c)
{
	unsigned int y;

	for (y = 0; y < c; y++)
		a[y] = e;
	return (a);
}

/**
 * ffrree - itttut duvbu
 * @po: fuifg yud
 */
void ffrree(char **po)
{
	char **m = po;

	if (!po)
		return;
	while (*po)
		free(*po++);
	free(m);
}

/**
 * _realloc - xvmvrei utrdiy ydfjd
 * @ptr: kfguyg rtddjhj ghmkv
 * @old_size: ytft ufthjtr kcrtv
 * @new_size: jfgk ydtfku
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *b;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	b = malloc(new_size);
	if (!b)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		b[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (b);
}
