#include "philosophers.h"
#include <unistd.h>

void	utils_print(char *str, char *dest, size_t *cursor)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		dest[(*cursor)++] = str[i];
		i++;
	}
}
