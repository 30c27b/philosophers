/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 21:40:38 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/28 22:22:50 by ancoulon         ###   ########.fr       */
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

typedef size_t	t_msecs;

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
	EATING,
	THINKING,
	SLEEPING
}	t_status;

typedef enum e_action
{
	FORK = 0,
	EATING = 1,
	THINKING = 2,
	SLEEPING = 3,
	DIED = 4
}	t_action;

typedef struct s_philosopher
{
	size_t		id;
	t_status	current_status;
	size_t		number_of_meals;
	t_msecs		last_meal;
	t_msecs		last_sleep;
}	t_philosopher;

typedef struct s_game
{
	t_rules			rules;
	t_msecs			start_time;
	t_philosopher	*philosophers;
}	t_game;

t_rules	philo_parse_params(int argc, char **argv);

t_msecs	philo_time(void);

#endif
