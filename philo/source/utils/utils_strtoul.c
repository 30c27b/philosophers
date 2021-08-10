#include "philosophers/utils.h"
#include <stdint.h>
#include <limits.h>
#include <errno.h>

uint64_t utils_strtoul(char *str)
{
	size_t		i;
	uint64_t	num;
	int			err;

	i = 0;
	num = 0;
	err = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			break;
		if (err < 0 || num > STUL_CUTOFF ||
			(num == STUL_CUTOFF && (uint64_t)(str[i]) > STUL_CUTLIM))
			err = -1;
		else
		{
			num *= 10;
			num += (str[i] - '0');
		}
		i++;
	}
	if (err == 0)
		return (num);
	errno = ERANGE;
	return (UINT64_MAX);
}
