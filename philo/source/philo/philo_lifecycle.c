#include "philosophers.h"
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
		pthread_mutex_lock(&(self->right_fork->mutex));
		action_log(ACTION_FORK, self, game);
		action_log(ACTION_EATING, self, game);
		self->last_meal = time_now();
		self->number_of_meals++;
		if (game->status == GS_RUNNING)
			time_sleep(game->rules.time_to_eat);
		pthread_mutex_unlock(&(self->left_fork->mutex));
		pthread_mutex_unlock(&(self->right_fork->mutex));
		action_log(ACTION_SLEEPING, self, game);
		if (game->status == GS_RUNNING)
			time_sleep(game->rules.time_to_sleep);
		action_log(ACTION_THINKING, self, game);
	}
	return (NULL);
}
