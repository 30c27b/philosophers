#ifndef FORK_H
# define FORK_H

# include <stddef.h>
# include <pthread.h>

typedef struct s_fork
{
	size_t			num;
	pthread_mutex_t	mutex;
}	t_fork;

t_fork	*fork_new(size_t num);

void	fork_destroy(t_fork *self);

#endif
