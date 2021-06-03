/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 21:40:38 by ancoulon          #+#    #+#             */
/*   Updated: 2021/06/03 13:22:16 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <sys/types.h>
# include <stdint.h>

// memset()
# include <string.h>

// printf()
# include <stdio.h>

// malloc(), free()
# include <stdlib.h>

// write(), usleep()
# include <unistd.h>

// gettimeofday()
# include <sys/time.h>

// pthread_create(), pthread_detach(), pthread_join(), pthread_mutex_init(),
// pthread_mutex_destroy(), pthread_mutex_lock(), pthread_mutex_unlock()
# include <pthread.h>

typedef uint64_t	t_msecs;

typedef struct s_rules
{
	size_t	number_of_philosophers;
	t_msecs	time_to_die;
	t_msecs	time_to_eat;
	t_msecs	time_to_sleep;
	ssize_t	number_of_times_each_philosopher_must_eat;
}	t_rules;

typedef enum e_status
{
	STS_NONE=0,
	STS_EATING=1,
	STS_THINKING=2,
	STS_SLEEPING=3
}	t_status;

typedef enum e_action
{
	ACT_FORK = 0,
	ACT_EATING = 1,
	ACT_THINKING = 2,
	ACT_SLEEPING = 3,
	ACT_DIED = 4
}	t_action;

typedef struct s_philo
{
	size_t		id;
	pthread_t	tid;
	t_status	current_status;
	size_t		number_of_meals;
	t_msecs		last_meal;
	size_t		number_of_sleeps;
	t_msecs		last_sleep;
}	t_philo;

typedef struct s_fork
{
	size_t			num;
	pthread_mutex_t	mutex;
}	t_fork;

typedef enum e_game_status
{
	GS_WAITING=0,
	GS_STARTED=1,
	GS_ENDED=2
}	t_game_status;

typedef struct s_game
{
	t_rules			rules;
	t_msecs			start_time;
	t_game_status	status;
	pthread_mutex_t	logging;
	pthread_mutex_t	philo_died;
	size_t			n_philos;
	t_philo			**philos;
	size_t			n_forks;
	t_fork			**forks;
}	t_game;

typedef struct s_philo_args
{
	t_game	*game;
	t_philo	*me;
}	t_philo_args;

int		params_parse(t_rules *rules, int argc, char **argv);

t_msecs	time_now(void);

void	log_action(t_game *game, t_philo *philo, t_action action);

t_game	*game_new(t_rules rules);
int		game_start(t_game *game);
void	game_end(t_game *game);
void	game_wait_until_over(t_game *game);

t_philo	*philo_new(size_t id);
int		philo_start(t_philo *philo, t_game *game);

t_fork	*fork_new(size_t num);
int		fork_start(t_fork *fork);

int	philo_action_eat(t_philo *philo, t_game *game);
int	philo_action_think(t_philo *philo, t_game *game);
int	philo_action_sleep(t_philo *philo, t_game *game);

#endif
