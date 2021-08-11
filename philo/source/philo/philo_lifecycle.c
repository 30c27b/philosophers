#include "philosophers/philo.h"
#include "philosophers/game.h"
#include "philosophers/action.h"
#include <stdio.h>
#include <stdlib.h>

void	*philo_lifecycle(void *arg)
{
	t_game	*game;
	t_philo	*self;

	game = ((t_philo_args *)arg)->game;
	self = ((t_philo_args *)arg)->self;
	free(arg);
	while (game->status == GS_RUNNING)
	{
		pthread_mutex_lock(&(self->left_fork->mutex));
		action_run(ACTION_EATING, self, game);
		pthread_mutex_unlock(&(self->left_fork->mutex));
		time_sleep(2000);
	}
	return (NULL);
}
