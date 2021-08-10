#include "philosophers/fork.h"
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

t_fork	*fork_new(size_t num)
{
	t_fork	*fork;

	fork = malloc(sizeof(t_fork));
	if (fork == NULL)
		return (NULL);
	memset(fork, 0, sizeof(t_fork));
	fork->num = num;
	if (pthread_mutex_init(&(fork->mutex), NULL) != 0)
		return (NULL);
	return (fork);
}
