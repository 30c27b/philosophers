#include "philosophers/action.h"
#include "philosophers/philo.h"
#include "philosophers/game.h"

void	action_run(t_action action, t_philo *target, t_game *game)
{
	static void (*actions[5])(t_game *, t_philo *) = {&action_fork,
	&action_eat, &action_sleep, NULL, NULL};

	actions[action](game, target);
}
