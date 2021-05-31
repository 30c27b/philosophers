/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:22:24 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/31 16:13:24 by ancoulon         ###   ########.fr       */
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

void	game_wait_until_over(t_game *game)
{
	size_t	i;
	size_t	sated_philos;

	while (!game->is_over)
	{
		i = 0;
		sated_philos = 0;
		while (i < game->n_philos)
		{
			if ((game->philos[i]->last_meal - time_now()) >= game->rules.time_to_die)
			{
				log_action(game, game->philos[i], ACT_DIED);
				game->is_over = 1;
				return ;
			}
			if (game->rules.number_of_times_each_philosopher_must_eat > 0
				&& game->philos[i]->number_of_meals >=
				(size_t)game->rules.number_of_times_each_philosopher_must_eat)
				sated_philos++;
			i++;
			usleep(10);
		}
		if (sated_philos >= game->n_philos)
		{
			game->is_over = 1;
			return ;
		}
	}
}

void	game_end(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->n_philos)
	{
		pthread_join(game->philos[i]->tid, NULL);
		i++;
	}
}
