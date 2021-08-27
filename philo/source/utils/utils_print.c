#include "philosophers.h"
#include <unistd.h>

static size_t	str_len(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	utils_print(char *str)
{
	write(1, str, str_len(str));
}
