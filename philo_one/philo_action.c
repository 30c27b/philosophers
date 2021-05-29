/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 13:00:02 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/29 17:55:08 by ancoulon         ###   ########.fr       */
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
	// printf("forks for %zu: %zu - %zu\n", philo->id, forks[0]->num, forks[1]->num);
	pthread_mutex_lock(&((forks[0])->mutex));
	pthread_mutex_lock(&((forks[1])->mutex));
	philo->current_status = STS_EATING;
	log_action(game, philo, ACT_EATING);
	usleep(game->rules.time_to_eat);
	philo->last_meal = time_now();
	philo->number_of_meals++;
	pthread_mutex_unlock(&((forks[0])->mutex));
	pthread_mutex_unlock(&((forks[1])->mutex));
	return (0);
}
