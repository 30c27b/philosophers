/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 13:00:02 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/31 15:54:04 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include <pthread.h>
#include <unistd.h>

int	philo_action_eat(t_philo *philo, t_game *game)
{
	t_fork	*forks[2];

	forks[0] = game->forks[philo->id - 1];
	if (philo->id == game->n_philos)
		forks[1] = game->forks[0];
	else
		forks[1] = game->forks[philo->id];
	pthread_mutex_lock(&((forks[0])->mutex));
	pthread_mutex_lock(&((forks[1])->mutex));
	philo->last_meal = time_now();
	philo->current_status = STS_EATING;
	log_action(game, philo, ACT_EATING);
	philo->number_of_meals++;
	usleep(game->rules.time_to_eat * 1000);
	pthread_mutex_unlock(&((forks[0])->mutex));
	pthread_mutex_unlock(&((forks[1])->mutex));
	return (0);
}

int	philo_action_sleep(t_philo *philo, t_game *game)
{
	philo->current_status = STS_SLEEPING;
	philo->last_sleep = time_now();
	log_action(game, philo, ACT_SLEEPING);
	usleep(game->rules.time_to_sleep * 1000);
	return (0);
}

int	philo_action_think(t_philo *philo, t_game *game)
{
	philo->current_status = STS_THINKING;
	log_action(game, philo, ACT_THINKING);
	return (0);
}
