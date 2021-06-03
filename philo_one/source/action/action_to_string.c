#include "philo_one/action.h"

char	*action_to_string(t_action action)
{
	static char	*strings[5] = {"has taken a fork", "is eating",
		"is sleeping", "is thinking", "died"};

	return (strings[action]);
}
