#include "philosophers.h"
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
	philo->left_fork = left_fork;
	philo->right_fork = right_fork;
	return (philo);
}
