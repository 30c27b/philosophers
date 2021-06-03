#ifndef PHILO_H
# define PHILO_H

# include "philo_one/time.h"
# include <stddef.h>
# include <pthread.h>

typedef struct s_game t_game;

typedef enum e_philo_status
{
	STS_NONE=0,
	STS_EATING=1,
	STS_THINKING=2,
	STS_SLEEPING=3
}	t_philo_status;

typedef enum e_philo_action
{
	ACT_FORK = 0,
	ACT_EATING = 1,
	ACT_THINKING = 2,
	ACT_SLEEPING = 3,
	ACT_DIED = 4
}	t_philo_action;

typedef struct s_philo
{
	size_t			id;
	pthread_t		tid;
	t_philo_status	current_status;
	size_t			number_of_meals;
	t_msecs			last_meal;
	size_t			number_of_sleeps;
	t_msecs			last_sleep;
}	t_philo;

typedef struct s_philo_args
{
	t_game	*game;
	t_philo	*self;
}	t_philo_args;

t_philo	*philo_new(size_t id);

int		philo_start(t_philo *self, t_game *game);

void	*philo_lifecycle(void *arg);

void	philo_destroy(t_philo *self);

#endif
