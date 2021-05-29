/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:22:24 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/29 15:41:27 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

t_game	*game_new(t_rules rules)
{
	t_game	*game;
	ssize_t	i;

	game = malloc(sizeof(t_game));
	if (game == NULL)
		return (NULL);
	game->rules = rules;
	game->n_philos = rules.number_of_philosophers;
	game->philos = malloc(sizeof(t_philo *) * game->n_philos);
	if (game->philos == NULL)
		return (NULL);
	i = -1;
	while (++i < (ssize_t)game->n_philos)
	{
		game->philos[i] = philo_new(i + 1);
		if (game->philos[i] == NULL)
			return (NULL);
	}
	game->n_forks = rules.number_of_philosophers;
	game->forks = malloc(sizeof(t_fork *) * game->n_forks);
	if (game->forks == NULL)
		return (NULL);
	i = -1;
	while (++i < (ssize_t)game->n_forks)
	{
		game->forks[i] = fork_new(i);
		if (game->forks[i] == NULL)
			return (NULL);
	}
	return (game);
}

int	game_start(t_game *game)
{
	size_t	i;
	int		err;

	game->start_time = time_now();
	i = 0;
	while (i < game->n_forks)
	{
		err = fork_start(game->forks[i]);
		if (err)
			return (1);
		i++;
	}
	i = 0;
	while (i < game->n_philos)
	{
		err = philo_start(game->philos[i], game);
		if (err)
			return (1);
		i++;
	}
	return (0);
}
