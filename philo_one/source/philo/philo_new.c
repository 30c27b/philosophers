#include "philo_one/philo.h"
#include "philo_one/time.h"
#include <stdlib.h>
#include <string.h>

t_philo	*philo_new(size_t id)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (philo == NULL)
		return (NULL);
	memset(philo, 0, sizeof(t_philo));
	philo->id = id;
	philo->current_status = STS_NONE;
	return (philo);
}
