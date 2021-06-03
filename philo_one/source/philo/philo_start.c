#include "philo_one/philo.h"
#include "philo_one/time.h"
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

int		philo_start(t_philo *self, t_game *game)
{
	t_msecs	now;

	now = time_now();
	self->last_meal = now;
	self->last_sleep = now;
	if (pthread_create(&(self->tid), NULL, &philo_lifecycle, &(t_philo_args){game, self}) != 0)
		return (-1);
	return (0);
}
