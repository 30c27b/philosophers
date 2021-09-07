#ifndef GAME_H
# define GAME_H

# include "philosophers/time.h"
# include "philosophers/fork.h"
# include "philosophers/philo.h"
# include "philosophers/rules.h"

# define BUFFER_LEN 400

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
	size_t			buf_len;
	char			*buffer;
}	t_game;

t_game	*game_new(t_rules rules);

int		game_start(t_game *self);

void	game_destroy(t_game *self);

#endif
