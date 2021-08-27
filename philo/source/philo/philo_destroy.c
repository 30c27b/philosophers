#include "philosophers.h"
#include <stdlib.h>

void	philo_destroy(t_philo *self)
{
	free(self);
}
