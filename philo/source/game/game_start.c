#include "philosophers/game.h"
#include "philosophers/fork.h"
#include "philosophers/philo.h"
#include "philosophers/action.h"
#include "philosophers/time.h"
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

static int start_philos(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < (game->n_philos))
	{
		if (philo_start(game->philos[i], game) < 0)
			return (-1);
		i += 2;
	}
	time_sleep(1);
	i = 1;
	while (i < (game->n_philos))
	{
		if (philo_start(game->philos[i], game) < 0)
			return (-1);
		i += 2;
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
			if (self->rules.number_of_times_each_philosopher_must_eat >= 0 && self->philos[i]->number_of_meals >= (size_t)self->rules.number_of_times_each_philosopher_must_eat)
			{
				self->status = GS_OVER;
				break;
			}
			i++;
		}
	}
	terminate_philos(self);
	return (0);
}
