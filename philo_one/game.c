/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:22:24 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/29 11:05:45 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

t_game	*game_new(t_rules rules)
{
	t_game	*game;
	size_t	i;

	game = malloc(sizeof(t_game));
	if (game == NULL)
		return (NULL);
	memset(game, 0, sizeof(t_game));
	game->rules = rules;
	game->n_philos = rules.number_of_philosophers;
	game->philos = malloc(sizeof(t_philo*) * game->n_philos);
	if (game->philos == NULL)
		return (NULL);
	i = 0;
	while (++i <= game->n_philos)
		game->philos[i - 1] = philo_init(i);
	game->n_forks = rules.number_of_philosophers;
	i = 0;
	return (game);
}

int	game_start(t_game *game)
{
	game->start_time = philo_time();
}
