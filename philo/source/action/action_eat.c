#include "philosophers/action.h"
#include "philosophers/time.h"
#include "philosophers/philo.h"
#include "philosophers/game.h"
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void	action_eat(t_game *game, t_philo *target)
{
	action_log(ACTION_EATING, target, game);
	target->last_meal = time_now();
	target->number_of_meals++;
	time_sleep(game->rules.time_to_eat);
	pthread_mutex_unlock(&(target->left_fork->mutex));
	pthread_mutex_unlock(&(target->right_fork->mutex));
}
