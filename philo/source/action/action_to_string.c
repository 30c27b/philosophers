#include "philosophers.h"
#include <unistd.h>

void	action_to_string(t_action action)
{
	static char	*strings[5] = {" has taken a fork\n", " is eating\n",
		" is sleeping\n", " is thinking \n", " died\n"};
	static size_t	lens[5] = {18, 11, 13, 14, 6};

	write(1, strings[action], lens[action]);
}
