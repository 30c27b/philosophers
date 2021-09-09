#include "philosophers.h"
#include <unistd.h>

void	utils_printnbr(uint64_t nbr, char *dest, size_t	*cursor)
{
	if (nbr > 9)
	{
		utils_printnbr(nbr / 10, dest, cursor);
		utils_printnbr(nbr % 10, dest, cursor);
	}
	else
	{
		dest[(*cursor)++] = (char)nbr + '0';
	}
}
