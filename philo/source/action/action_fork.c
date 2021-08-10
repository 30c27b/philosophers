#include "philosophers/action.h"
#include "philosophers/time.h"
#include "philosophers/philo.h"
#include "philosophers/game.h"
#include <pthread.h>

void	action_fork(t_game *game, t_philo * target)
{
	pthread_mutex_lock(&(target->left_fork->mutex));
	pthread_mutex_lock(&(target->right_fork->mutex));
	action_log(ACTION_FORK, target, game);
}

