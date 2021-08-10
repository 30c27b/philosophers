#include "philosophers/fork.h"
#include <stdlib.h>
#include <pthread.h>

void	fork_destroy(t_fork *self)
{
	if (self != NULL)
	{
		pthread_mutex_destroy(&(self->mutex));
		free(self);
	}
}
