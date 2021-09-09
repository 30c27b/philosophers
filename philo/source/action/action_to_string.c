#include "philosophers.h"
#include <unistd.h>

char	*action_to_string(t_action action)
{
	static char		*strings[5] = {" has taken a fork\n", " is eating\n",
		" is sleeping\n", " is thinking \n", " died\n"};

	return (strings[action]);
}
