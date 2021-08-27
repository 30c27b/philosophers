#ifndef PHILO_H
# define PHILO_H

# include "philosophers/fork.h"
# include "philosophers/time.h"
# include <stddef.h>
# include <pthread.h>

typedef struct s_game	t_game;

typedef struct s_philo
{
	size_t			id;
	pthread_t		tid;
	size_t			number_of_meals;
	t_msecs			last_meal;
	size_t			number_of_sleeps;
	t_msecs			last_sleep;
	t_fork			*left_fork;
	t_fork			*right_fork;
}	t_philo;

typedef struct s_philo_args
{
	t_game	*game;
	t_philo	*self;
}	t_philo_args;

t_philo	*philo_new(size_t id, t_fork *left_fork, t_fork *right_fork);

int		philo_start(t_philo *self, t_game *game);

void	*philo_lifecycle(void *arg);

void	philo_terminate(t_philo *self);

void	philo_destroy(t_philo *self);

#endif
