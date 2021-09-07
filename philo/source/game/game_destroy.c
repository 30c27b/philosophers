#include "philosophers.h"
#include <stdlib.h>

void	game_destroy(t_game *self)
{
	size_t	i;

	i = 0;
	while (i < self->n_forks)
	{
		fork_destroy(self->forks[i]);
		i++;
	}
	free(self->forks);
	i = 0;
	while (i < self->n_philos)
	{
		philo_destroy(self->philos[i]);
		i++;
	}
	free(self->philos);
	free(self->buffer);
	free(self);
}
