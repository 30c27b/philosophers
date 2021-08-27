#include "philosophers.h"
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

static int	create_forks(t_game *game)
{
	size_t	i;

	i = 0;
	game->n_forks = game->rules.number_of_philosophers;
	game->forks = malloc(sizeof(t_fork *) * game->n_forks);
	if (game->forks == NULL)
		return (-1);
	while (i < game->n_forks)
	{
		game->forks[i] = fork_new(i);
		if (game->forks[i] == NULL)
			return (-1);
		i++;
	}
	return (0);
}

static int	create_philos(t_game *game)
{
	size_t	i;
	t_fork	*right_fork;

	i = 0;
	game->n_philos = game->rules.number_of_philosophers;
	game->philos = malloc(sizeof(t_philo *) * game->n_philos);
	if (game->philos == NULL)
		return (-1);
	while (i < game->n_philos)
	{
		if (i == game->n_philos - 1)
			right_fork = game->forks[0];
		else
			right_fork = game->forks[i + 1];
		game->philos[i] = philo_new(i + 1, game->forks[i], right_fork);
		if (game->philos[i] == NULL)
			return (-1);
		i++;
	}
	return (0);
}

t_game	*game_new(t_rules rules)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (game == NULL)
		return (NULL);
	memset(game, 0, sizeof(t_game));
	game->rules = rules;
	game->status = GS_RUNNING;
	if (pthread_mutex_init(&(game->logging), NULL))
		return (NULL);
	if (pthread_mutex_init(&(game->philo_died), NULL))
		return (NULL);
	if (create_forks(game) < 0)
		return (NULL);
	if (create_philos(game) < 0)
		return (NULL);
	return (game);
}
