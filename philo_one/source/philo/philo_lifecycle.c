#include "philo_one/philo.h"
#include "philo_one/game.h"
#include "philo_one/action.h"
#include <stdio.h>

void	*philo_lifecycle(void *arg)
{
	t_game	*game;
	t_philo	*self;

	game = ((t_philo_args *)arg)->game;
	self = ((t_philo_args *)arg)->self;
	action_log(ACTION_WAITING, self, game);
	while (game->status == GS_RUNNING)
	{
	}
	printf("Philo %zu: Done\n", self->id);
	return (NULL);
}
