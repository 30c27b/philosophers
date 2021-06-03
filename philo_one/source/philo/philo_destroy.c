#include "philo_one/philo.h"
#include <stdlib.h>
#include <pthread.h>

void	philo_destroy(t_philo *self)
{
	if (self != NULL)
	{
		if (self->tid > 0)
			pthread_join(self->tid, NULL);
		free(self);
	}
}
