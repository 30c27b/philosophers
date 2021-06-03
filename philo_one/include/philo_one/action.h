#ifndef ACTION_H
# define ACTION_H

# include "philo_one/philo.h"
# include "philo_one/game.h"

typedef enum e_action
{
	ACTION_WAITING = 0,
	ACTION_EATING = 1,
	ACTION_THINKING = 2,
	ACTION_SLEEPING = 3,
	ACTION_DIED = 4
}	t_action;

char	*action_to_string(t_action action);

void	action_log(t_action action, t_philo *target, t_game *game);

#endif
