#include "philosophers/utils.h"
#include <unistd.h>

void	utils_printnbr(uint64_t nbr)
{
	char	c;
	if (nbr > 9)
	{
		utils_printnbr(nbr / 10);
		utils_printnbr(nbr % 10);
	}
	else
	{
		c = (char)nbr + '0';
		write(1, &c, 1);
	}
}
