#include "philo_one/philo.h"
#include "philo_one/fork.h"
#include "philo_one/time.h"
#include <stdlib.h>
#include <string.h>

t_philo	*philo_new(size_t id, t_fork *left_fork, t_fork *right_fork)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (philo == NULL)
		return (NULL);
	memset(philo, 0, sizeof(t_philo));
	philo->id = id;
	philo->current_status = STS_NONE;
	philo->left_fork = left_fork;
	philo->right_fork = right_fork;
	return (philo);
}
