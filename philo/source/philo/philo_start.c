#include "philosophers/philo.h"
#include "philosophers/time.h"
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <stdio.h>

int		philo_start(t_philo *self, t_game *game)
{
	t_msecs			now;
	t_philo_args	*arg;

	arg = malloc(sizeof(t_philo_args));
	if (arg == NULL)
		return (-1);
	arg->game = game;
	arg->self = self;
	now = time_now();
	self->last_meal = now;
	self->last_sleep = now;
	if (pthread_create(&(self->tid), NULL, &philo_lifecycle, arg) != 0)
		return (-1);
	return (0);
}
