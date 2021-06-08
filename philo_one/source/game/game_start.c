#include "philo_one/game.h"
#include "philo_one/fork.h"
#include "philo_one/philo.h"
#include "philo_one/action.h"
#include "philo_one/time.h"
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

static int start_philos(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->n_philos)
	{
		if (philo_start(game->philos[i], game) < 0)
			return (-1);
		i++;
	}
	return (0);
}

static void terminate_philos(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->n_philos)
	{
		philo_terminate(game->philos[i]);
		i++;
	}
}

int	game_start(t_game *self)
{
	size_t	i;

	self->start_time = time_now();
	if (start_philos(self) < 0)
		return (-1);
	while (self->status == GS_RUNNING)
	{
		i = 0;
		while (i < self->n_philos)
		{
			if ((time_now() - self->philos[i]->last_meal) > self->rules.time_to_die)
			{
				action_log(ACTION_DIED, self->philos[i], self);
				self->status = GS_OVER;
				break;
			}
			i++;
		}
	}
	terminate_philos(self);
	return (0);
}
