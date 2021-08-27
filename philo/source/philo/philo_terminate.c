#include "philosophers.h"
#include <stdlib.h>
#include <pthread.h>

void	philo_terminate(t_philo *self)
{
	if (self != NULL)
	{
		if (self->tid > 0)
			pthread_join(self->tid, NULL);
	}
}
