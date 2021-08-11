#include "philosophers/action.h"
#include "philosophers/time.h"
#include "philosophers/philo.h"
#include "philosophers/game.h"
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void	action_eat(t_game *game, t_philo *target)
{
	
	action_log(ACTION_FORK, target, game);
	target->current_status = STS_EATING;
	target->number_of_meals++;
	target->last_meal = time_now();
	action_log(ACTION_EATING, target, game);
	time_sleep(1000);
}
