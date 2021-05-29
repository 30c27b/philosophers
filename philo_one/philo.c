/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:23:44 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/29 17:54:54 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

t_philo	*philo_new(size_t id)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	memset(philo, 0, sizeof(t_philo));
	philo->id = id;
	return (philo);
}

void	*philo_lifecycle(void *arg)
{
	t_game	*game;
	t_philo	*philo;

	game = ((t_philo_args *)arg)->game;
	philo = ((t_philo_args *)arg)->me;
	// log_action(game, philo, ACT_THINKING);
	philo_action_eat(philo, game);
	return (NULL);
}

int	philo_start(t_philo *philo, t_game *game)
{
	int	err;

	err = pthread_create(&(philo->tid), NULL, &philo_lifecycle,
		&(t_philo_args){game, philo});
	if (err)
		return (1);
	pthread_detach(philo->tid);
	usleep(100);
	return (0);
}
