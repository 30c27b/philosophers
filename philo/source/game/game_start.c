#include "philosophers.h"
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

static int	start_philos(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < (game->n_philos))
	{
		if (philo_start(game->philos[i], game) < 0)
			return (-1);
		i++;
		usleep(20);
	}
	return (0);
}

static void	terminate_philos(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->n_philos)
	{
		philo_terminate(game->philos[i]);
		i++;
	}
}

static int	game_should_end(t_game *self)
{
	size_t	i;

	i = 0;
	while (i < self->n_philos)
	{
		if ((time_now() - self->philos[i]->last_meal)
			> self->rules.time_to_die)
		{
			action_log(ACTION_DIED, self->philos[i], self);
			return (1);
		}
		if (self->rules.number_of_times_each_philosopher_must_eat
			>= 0 && self->philos[i]->number_of_meals >= (size_t)
			self->rules.number_of_times_each_philosopher_must_eat)
		{
			self->status = GS_OVER;
			return (1);
		}
		i++;
	}
	return (0);
}

int	game_start(t_game *self)
{
	self->start_time = time_now();
	if (start_philos(self) < 0)
		return (-1);
	self->status = GS_RUNNING;
	while (self->status == GS_RUNNING)
	{
		if (game_should_end(self))
			break ;
		usleep(500);
	}
	terminate_philos(self);
	return (0);
}
