#include "shell.h"

/**
 * bfree - ukfgvehv kuwfvkue vujhcakawuvkc gvvaejva
 * @ptr: gchvdckfb vay,ahfvhb kvjhvbas vvjasjgvj
 *
 * Return: jyffhgktdh jftjcyhzhrhxhtjd
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
